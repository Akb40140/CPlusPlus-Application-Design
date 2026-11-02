// Roster.cpp - the member functions of the Roster class
#include <fstream>
#include <iostream>
#include "Roster.h"

Roster::Roster() {
    capacity = 10;
    count = 0;
    students = new Student[capacity];
}

Roster::~Roster() {
    delete[] students;
}

int Roster::getCount() {
    return count;
}

int Roster::getCapacity() {
    return capacity;
}

// Makes an array twice as big and copies everyone over.
void Roster::grow() {
    capacity = capacity * 2;
    Student* bigger = new Student[capacity];

    for (int i = 0; i < count; i++) {
        bigger[i] = students[i];
    }

    delete[] students;
    students = bigger;
}

void Roster::loadFromFile(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not open " << fileName << "." << endl;
        return;
    }

    string header, name, idText, scoreText;
    getline(file, header);   // skip the first line

    while (getline(file, name, ',') && getline(file, idText, ',') &&
           getline(file, scoreText)) {
        addStudent(Student(name, stoi(idText), stod(scoreText)));
    }

    file.close();
    cout << "Loaded " << count << " students." << endl;
}

void Roster::saveToFile(string fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not save to " << fileName << "." << endl;
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

void Roster::writeReport(string fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not write " << fileName << "." << endl;
        return;
    }

    file << "Student Report" << endl;
    file << "Students: " << count << endl;

    for (int i = 0; i < count; i++) {
        file << students[i].getName() << " (id " << students[i].getId() << ") - "
             << students[i].getScore() << ", grade "
             << students[i].getLetterGrade() << endl;
    }

    if (count > 0) {
        file << "Average: " << getAverage() << endl;
    }

    file.close();
    cout << "Report written to " << fileName << "." << endl;
}

// Puts a student in the right spot so the array stays sorted by id.
// Returns false if the id is already used.
bool Roster::addStudent(Student newStudent) {
    if (binarySearch(newStudent.getId()) != -1) {
        return false;
    }
    if (count == capacity) {
        grow();
    }

    int i = count - 1;
    // Move bigger ids one spot to the right to make room
    while (i >= 0 && students[i].getId() > newStudent.getId()) {
        students[i + 1] = students[i];
        i--;
    }
    students[i + 1] = newStudent;
    count++;
    return true;
}

bool Roster::deleteStudent(int id) {
    int position = binarySearch(id);
    if (position == -1) {
        return false;
    }

    // Shift everyone after it back one spot, which keeps the order sorted
    for (int i = position; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
    return true;
}

// Binary search by id. Only works because the array is sorted by id.
// Returns the position of the student, or -1 if not found.
int Roster::binarySearch(int id) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid].getId() == id) {
            return mid;
        }
        if (students[mid].getId() < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Returns a pointer to the student, or nullptr if not found.
Student* Roster::findById(int id) {
    int position = binarySearch(id);
    if (position == -1) {
        return nullptr;
    }
    return &students[position];
}

// Goes through every student, since the array isn't sorted by name.
void Roster::searchByName(string text) {
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (students[i].getName().find(text) != string::npos) {
            students[i].displayStudent();
            found = true;
        }
    }

    if (!found) {
        cout << "No student with that name." << endl;
    }
}

void Roster::viewStudents() {
    if (count == 0) {
        cout << "No students yet." << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        students[i].displayStudent();
    }
}

void Roster::showStats() {
    if (count == 0) {
        cout << "No students yet." << endl;
        return;
    }

    // gradeCounts[0] is A, gradeCounts[1] is B, and so on
    char letters[5] = {'A', 'B', 'C', 'D', 'F'};
    int gradeCounts[5] = {0, 0, 0, 0, 0};
    int passing = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].isPassing()) {
            passing++;
        }
        for (int j = 0; j < 5; j++) {
            if (students[i].getLetterGrade() == letters[j]) {
                gradeCounts[j]++;
            }
        }
    }

    cout << "Students: " << count << endl;
    cout << "Average: " << getAverage() << endl;
    cout << "Highest: " << getHighest()->getName() << " - " << getHighest()->getScore() << endl;
    cout << "Lowest: " << getLowest()->getName() << " - " << getLowest()->getScore() << endl;
    cout << "Passing: " << passing << endl;

    for (int i = 0; i < 5; i++) {
        cout << letters[i] << ": " << gradeCounts[i] << endl;
    }
}

// Uses a pointer to go through the array.
double Roster::getAverage() {
    double total = 0;
    Student* current = students;

    for (int i = 0; i < count; i++) {
        total += current->getScore();
        current++;
    }
    return total / count;
}

Student* Roster::getHighest() {
    Student* highest = &students[0];

    for (int i = 1; i < count; i++) {
        if (students[i].getScore() > highest->getScore()) {
            highest = &students[i];
        }
    }
    return highest;
}

Student* Roster::getLowest() {
    Student* lowest = &students[0];

    for (int i = 1; i < count; i++) {
        if (students[i].getScore() < lowest->getScore()) {
            lowest = &students[i];
        }
    }
    return lowest;
}
