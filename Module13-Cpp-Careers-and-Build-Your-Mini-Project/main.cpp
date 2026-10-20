// Module 13 - C++ Careers & Build Your Mini Project
// The finished app. Changes are now saved back to students.csv, so the data
// is still there the next time the program runs.
#include <iostream>
#include <fstream>
#include "Student.h"
#include "User.h"
#include "Validation.h"
#include "AICoach.h"
#include "Stats.h"
using namespace std;

const int MAX_STUDENTS = 100;
const string DATA_FILE = "students.csv";
const string ADMIN_PASSWORD = "admin123";   // demo only, not a real password
const int MIN_ID = 1000;
const int MAX_ID = 9999;

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

// Writes every student back to the file so changes aren't lost.
void saveStudents(string fileName, Student students[], int count) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: could not save to " << fileName << "." << endl;
        return;
    }

    file << "name,student_id,math_score" << endl;
    for (int i = 0; i < count; i++) {
        file << students[i].getName() << "," << students[i].getId() << ","
             << students[i].getScore() << endl;
    }

    file.close();
    cout << "Saved to " << fileName << "." << endl;
}

// Asks who is using the program and returns their User object.
User login() {
    string name = readName("Enter your name: ");
    cout << "1. Admin" << endl;
    cout << "2. Regular User" << endl;
    int roleChoice = readInt("Choose your role (1-2): ", 1, 2);

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
    cout << "6. AI Study Coach" << endl;
    cout << "7. Class Statistics" << endl;
    cout << "8. Search Speed Test" << endl;
    cout << "9. Exit" << endl;
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
    return readInt("Enter student id (1000-9999): ", MIN_ID, MAX_ID);
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
    if (*count >= MAX_STUDENTS) {
        cout << "The list is full." << endl;
        return;
    }

    string name = readName("Enter student name: ");

    // Keep asking until the id is not already taken
    int id = askForId();
    while (binarySearch(students, *count, id) != -1) {
        cout << "Error: id " << id << " is already used. Try again." << endl;
        id = askForId();
    }

    double score = readDouble("Enter math score (0-100): ", 0, 100);

    insertSorted(students, count, Student(name, id, score));
    cout << "Student added." << endl;
}

void updateScore(Student students[], int count) {
    int i = binarySearch(students, count, askForId());
    if (i == -1) {
        cout << "No student with that id." << endl;
        return;
    }

    students[i].setScore(readDouble("Enter new score (0-100): ", 0, 100));
    cout << "Score is now " << students[i].getScore() << endl;
}

double classAverage(Student students[], int count) {
    if (count == 0) {
        return 0;
    }
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += students[i].getScore();
    }
    return total / count;
}

void studyCoach(Student students[], int count) {
    int i = binarySearch(students, count, askForId());
    if (i == -1) {
        cout << "No student with that id." << endl;
        return;
    }
    runStudyCoach(students[i], classAverage(students, count));
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
    int count = loadStudents(DATA_FILE, students);
    int choice = 0;

    cout << "Loaded " << count << " students." << endl;
    User user = login();

    while (choice != 9 && !cin.eof()) {
        showMenu(user);
        choice = readInt("Choose an option (1-9): ", 1, 9);

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
                saveStudents(DATA_FILE, students, count);
                break;
            case 4:
                updateScore(students, count);
                saveStudents(DATA_FILE, students, count);
                break;
            case 5:
                deleteStudent(students, &count);
                saveStudents(DATA_FILE, students, count);
                break;
            case 6:
                studyCoach(students, count);
                break;
            case 7:
                showClassStats(students, count);
                break;
            case 8:
                searchSpeedTest();
                break;
            case 9:
                cout << "Goodbye!" << endl;
                break;
        }
    }

    return 0;
}
