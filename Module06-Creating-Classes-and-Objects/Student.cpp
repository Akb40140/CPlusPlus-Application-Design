// Student.cpp - the code for the Student class's member functions
#include <iostream>
#include "Student.h"
using namespace std;

// Default constructor
Student::Student() {
    name = "";
    id = 0;
    score = 0;
}

// Constructor that sets all three values
Student::Student(string studentName, int studentId, double studentScore) {
    name = studentName;
    id = studentId;
    score = studentScore;
}

// Prints the student's information
void Student::displayStudent() {
    cout << name << " (id " << id << ") - " << score << endl;
}

// A score of 60 or higher is passing
bool Student::isPassing() {
    return score >= 60;
}

string Student::getName() {
    return name;
}

int Student::getId() {
    return id;
}

double Student::getScore() {
    return score;
}

// Only accepts scores from 0 to 100
void Student::setScore(double newScore) {
    if (newScore >= 0 && newScore <= 100) {
        score = newScore;
    }
}
