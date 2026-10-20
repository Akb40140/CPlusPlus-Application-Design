// Module 7 - Security, Roles & Binary Search
// Student Record Manager with Admin / Regular User roles.
// Students are kept sorted by id so we can use binary search.
#include <iostream>
#include <fstream>
#include <limits>
#include "Student.h"
#include "User.h"
using namespace std;

const int MAX_STUDENTS = 10;
const string ADMIN_PASSWORD = "admin123";   // demo only, not a real password

// Binary search by id. Only works because the array is sorted by id.
// Returns the position of the student, or -1 if not found.
int binarySearch(Student students[], int count, int targetId) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid].getId() == targetId) {
            return mid;
        }
        if (students[mid].getId() < targetId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Puts a student in the right spot so the array stays sorted by id.
bool insertSorted(Student students[], int* count, Student newStudent) {
    if (*count >= MAX_STUDENTS) {
        return false;
    }

    int i = *count - 1;
    // Move bigger ids one spot to the right to make room
    while (i >= 0 && students[i].getId() > newStudent.getId()) {
        students[i + 1] = students[i];
        i--;
    }
    students[i + 1] = newStudent;
    (*count)++;
    return true;
}

int loadStudents(string fileName, Student students[]) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not open " << fileName << "." << endl;
        return 0;
    }

    string header, name, idText, scoreText;
    getline(file, header);   // skip the first line

    int count = 0;
    while (getline(file, name, ',') && getline(file, idText, ',') &&
           getline(file, scoreText)) {
        insertSorted(students, &count, Student(name, stoi(idText), stod(scoreText)));
    }

    file.close();
    return count;
}

// Asks who is using the program and returns their User object.
User login() {
    string name;
    int roleChoice;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "1. Admin" << endl;
    cout << "2. Regular User" << endl;
    cout << "Choose your role: ";
    cin >> roleChoice;
    cin.clear();
    cin.ignore(1000, '\n');

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
    cout << "3. Add Student (Admin)" << endl;
    cout << "4. Update Score (Admin)" << endl;
    cout << "5. Delete Student (Admin)" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option (1-6): ";
}

void viewStudents(Student students[], int count) {
    if (count == 0) {
        cout << "No students yet." << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        students[i].displayStudent();
    }
}

int askForId() {
    int id;
    cout << "Enter student id: ";
    cin >> id;
    cin.clear();
    cin.ignore(1000, '\n');
    return id;
}

void searchById(Student students[], int count) {
    int i = binarySearch(students, count, askForId());
    if (i == -1) {
        cout << "No student with that id." << endl;
    } else {
        students[i].displayStudent();
    }
}

void addStudent(Student students[], int* count) {
    string name;
    double score;

    cout << "Enter student name: ";
    getline(cin, name);
    int id = askForId();

    if (binarySearch(students, *count, id) != -1) {
        cout << "That id is already used." << endl;
        return;
    }

    cout << "Enter math score: ";
    cin >> score;
    cin.ignore(1000, '\n');

    if (insertSorted(students, count, Student(name, id, score))) {
        cout << "Student added." << endl;
    } else {
        cout << "The list is full." << endl;
    }
}

void updateScore(Student students[], int count) {
    int i = binarySearch(students, count, askForId());
    if (i == -1) {
        cout << "No student with that id." << endl;
        return;
    }

    double newScore;
    cout << "Enter new score (0-100): ";
    cin >> newScore;
    cin.ignore(1000, '\n');

    students[i].setScore(newScore);
    cout << "Score is now " << students[i].getScore() << endl;
}

void deleteStudent(Student students[], int* count) {
    int i = binarySearch(students, *count, askForId());
    if (i == -1) {
        cout << "No student with that id." << endl;
        return;
    }

    cout << "Deleted " << students[i].getName() << "." << endl;
    // Shift everyone after it back one spot, which keeps the order sorted
    for (int j = i; j < *count - 1; j++) {
        students[j] = students[j + 1];
    }
    (*count)--;
}

int main() {
    Student students[MAX_STUDENTS];
    int count = loadStudents("students.csv", students);
    int choice = 0;

    cout << "Loaded " << count << " students." << endl;
    User user = login();

    while (choice != 6) {
        showMenu(user);
        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();   // bad input like "abc"
            choice = 0;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Options 3-5 change data, so they need an Admin
        if (choice >= 3 && choice <= 5 && !user.canEdit()) {
            cout << "Access denied. Only an Admin can do that." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                viewStudents(students, count);
                break;
            case 2:
                searchById(students, count);
                break;
            case 3:
                addStudent(students, &count);
                break;
            case 4:
                updateScore(students, count);
                break;
            case 5:
                deleteStudent(students, &count);
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Pick 1-6." << endl;
        }
    }

    return 0;
}
