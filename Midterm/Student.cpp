// Student.cpp - the member functions of the Student class
#include <iostream>
#include "Student.h"

Student::Student() {
    name = "";
    id = 0;
    score = 0;
}

Student::Student(string studentName, int studentId, double studentScore) {
    name = studentName;
    id = studentId;
    score = studentScore;
}

void Student::displayStudent() {
    cout << name << " (id " << id << ") - " << score
         << ", grade " << getLetterGrade() << endl;
}

bool Student::isPassing() {
    return score >= 60;
}

char Student::getLetterGrade() {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    }
    return 'F';
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

void Student::setScore(double newScore) {
    if (newScore >= 0 && newScore <= 100) {
        score = newScore;
    }
}
