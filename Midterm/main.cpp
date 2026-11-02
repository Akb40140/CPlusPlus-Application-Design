// C++ Midway Project - Student Record Manager
// Keeps track of students and their math scores. Students are loaded from
// students.csv, kept sorted by id, and found with binary search. An Admin can
// add, update and delete. A Regular User can only view and search.
#include <iostream>
#include <limits>
#include <string>
#include "Roster.h"
#include "User.h"
using namespace std;

const string DATA_FILE = "students.csv";
const string REPORT_FILE = "report.txt";
const string ADMIN_PASSWORD = "admin123";   // demo only, not a real password

// Clears bad input like "abc" and throws away the rest of the line.
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Asks who is using the program and returns their User object.
User login() {
    string name;
    int roleChoice = 0;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "1. Admin" << endl;
    cout << "2. Regular User" << endl;
    cout << "Choose your role: ";
    cin >> roleChoice;
    clearInput();

    if (roleChoice == 1) {
        string password;
        cout << "Enter admin password: ";
        getline(cin, password);

        if (password == ADMIN_PASSWORD) {
            return Admin(name);
        }
        cout << "Wrong password. Logging in as Regular User." << endl;
    }
    return RegularUser(name);
}

void showMenu(User user) {
    cout << "\n=== STUDENT RECORD MANAGER ===" << endl;
    cout << "Logged in as " << user.getName() << " (" << user.getRole() << ")" << endl;
    cout << "1. View Students" << endl;
    cout << "2. Search by ID" << endl;
    cout << "3. Search by Name" << endl;
    cout << "4. Class Statistics" << endl;
    cout << "5. Data Types and Sizes" << endl;
    cout << "6. Write Report to File" << endl;
    cout << "7. Add Student (Admin)" << endl;
    cout << "8. Update Score (Admin)" << endl;
    cout << "9. Delete Student (Admin)" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option (0-9): ";
}

// Returns the id the user typed, or -1 if it wasn't a number.
int askForId() {
    int id;
    cout << "Enter student id: ";
    if (!(cin >> id)) {
        id = -1;   // cin puts 0 in id when the input is bad
    }
    clearInput();
    return id;
}

// Returns the score the user typed, or -1 if it wasn't a number.
double askForScore() {
    double score;
    cout << "Enter math score (0-100): ";
    if (!(cin >> score)) {
        score = -1;   // cin puts 0 in score when the input is bad
    }
    clearInput();
    return score;
}

void searchById(Roster* roster) {
    Student* student = roster->findById(askForId());
    if (student == nullptr) {
        cout << "No student with that id." << endl;
    } else {
        student->displayStudent();
    }
}

void searchByName(Roster* roster) {
    string text;
    cout << "Enter a name: ";
    getline(cin, text);
    roster->searchByName(text);
}

void showSizes(Roster* roster) {
    cout << "char: " << sizeof(char) << " byte" << endl;
    cout << "bool: " << sizeof(bool) << " byte" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "string: " << sizeof(string) << " bytes" << endl;
    cout << "Student: " << sizeof(Student) << " bytes" << endl;
    cout << "Student pointer: " << sizeof(Student*) << " bytes" << endl;
    cout << "The array has room for " << roster->getCapacity() << " students, which is "
         << roster->getCapacity() * sizeof(Student) << " bytes." << endl;
}

void addStudent(Roster* roster) {
    string name;
    cout << "Enter student name: ";
    getline(cin, name);

    // A comma would break the line in the csv file
    if (name == "" || name.find(',') != string::npos) {
        cout << "That name can't be used." << endl;
        return;
    }

    int id = askForId();
    if (id <= 0) {
        cout << "That id can't be used." << endl;
        return;
    }
    if (roster->findById(id) != nullptr) {
        cout << "That id is already used." << endl;
        return;
    }

    double score = askForScore();
    if (score < 0 || score > 100) {
        cout << "The score has to be from 0 to 100." << endl;
        return;
    }

    roster->addStudent(Student(name, id, score));
    cout << "Student added." << endl;
    roster->saveToFile(DATA_FILE);
}

void updateScore(Roster* roster) {
    Student* student = roster->findById(askForId());
    if (student == nullptr) {
        cout << "No student with that id." << endl;
        return;
    }

    double score = askForScore();
    if (score < 0 || score > 100) {
        cout << "The score has to be from 0 to 100." << endl;
        return;
    }

    student->setScore(score);
    student->displayStudent();
    roster->saveToFile(DATA_FILE);
}

void deleteStudent(Roster* roster) {
    if (roster->deleteStudent(askForId())) {
        cout << "Student deleted." << endl;
        roster->saveToFile(DATA_FILE);
    } else {
        cout << "No student with that id." << endl;
    }
}

int main() {
    Roster roster;
    roster.loadFromFile(DATA_FILE);

    User user = login();
    int choice = -1;

    while (choice != 0) {
        showMenu(user);
        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }
            choice = -1;   // bad input like "abc"
        }
        clearInput();

        // Options 7-9 change data, so they need an Admin
        if (choice >= 7 && choice <= 9 && !user.canEdit()) {
            cout << "Access denied. Only an Admin can do that." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                roster.viewStudents();
                break;
            case 2:
                searchById(&roster);
                break;
            case 3:
                searchByName(&roster);
                break;
            case 4:
                roster.showStats();
                break;
            case 5:
                showSizes(&roster);
                break;
            case 6:
                roster.writeReport(REPORT_FILE);
                break;
            case 7:
                addStudent(&roster);
                break;
            case 8:
                updateScore(&roster);
                break;
            case 9:
                deleteStudent(&roster);
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Pick 0-9." << endl;
        }
    }

    return 0;
}
