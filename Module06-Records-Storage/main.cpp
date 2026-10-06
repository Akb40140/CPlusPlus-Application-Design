// Module 6 - Creating Classes & Objects
// Student Record Manager, now each student is a Student object
#include <iostream>
#include <fstream>
#include <limits>
#include "Student.h"
using namespace std;

const int MAX_STUDENTS = 10;

void showWelcome() {
    cout << "Welcome to the Student Record Manager!" << endl;
}

// Reads students.csv and makes a Student object for each line.
int loadStudents(string fileName, Student students[]) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not open " << fileName << "." << endl;
        return 0;
    }

    string header, name, idText, scoreText;
    getline(file, header);   // skip the first line

    int count = 0;
    while (count < MAX_STUDENTS && getline(file, name, ',') &&
           getline(file, idText, ',') && getline(file, scoreText)) {
        students[count] = Student(name, stoi(idText), stod(scoreText));
        count++;
    }

    file.close();
    return count;
}

void showMenu() {
    cout << "\n=== STUDENT RECORD MANAGER ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display Students" << endl;
    cout << "3. Search" << endl;
    cout << "4. Update Score" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option (1-5): ";
}

void addStudent(Student students[], int* count) {
    if (*count >= MAX_STUDENTS) {
        cout << "The list is full." << endl;
        return;
    }

    string name;
    int id;
    double score;

    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student id: ";
    cin >> id;
    cout << "Enter math score: ";
    cin >> score;
    cin.ignore(1000, '\n');

    students[*count] = Student(name, id, score);
    (*count)++;
    cout << "Student added." << endl;
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        cout << "No students yet." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        students[i].displayStudent();
        if (students[i].isPassing()) {
            cout << "   Passing" << endl;
        } else {
            cout << "   Not passing" << endl;
        }
    }
}

// Returns the position of the student, or -1 if not found.
int findStudent(Student students[], int count, string name) {
    for (int i = 0; i < count; i++) {
        if (students[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

void searchStudent(Student students[], int count) {
    string name;
    cout << "Enter a name: ";
    getline(cin, name);

    int i = findStudent(students, count, name);
    if (i == -1) {
        cout << "No student found." << endl;
    } else {
        students[i].displayStudent();
    }
}

void updateScore(Student students[], int count) {
    string name;
    cout << "Enter a name: ";
    getline(cin, name);

    int i = findStudent(students, count, name);
    if (i == -1) {
        cout << "No student found." << endl;
        return;
    }

    double newScore;
    cout << "Enter new score (0-100): ";
    cin >> newScore;
    cin.ignore(1000, '\n');

    students[i].setScore(newScore);
    cout << "Score is now " << students[i].getScore() << endl;
}

int main() {
    Student students[MAX_STUDENTS];
    int count = loadStudents("students.csv", students);
    int choice = 0;

    showWelcome();
    cout << "Loaded " << count << " students." << endl;

    while (choice != 5) {
        showMenu();
        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();   // bad input like "abc"
            choice = 0;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateScore(students, count);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Pick 1-5." << endl;
        }
    }

    return 0;
}
