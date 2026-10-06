// Student.h - the Student class
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    double score;

public:
    // Default constructor, needed to make an array of Students
    Student() {
        name = "";
        id = 0;
        score = 0;
    }

    // Constructor
    Student(string studentName, int studentId, double studentScore) {
        name = studentName;
        id = studentId;
        score = studentScore;
    }

    // Member functions
    void displayStudent() {
        cout << name << " (id " << id << ") - " << score << endl;
    }

    bool isPassing() {
        return score >= 60;
    }

    // Getters
    string getName() {
        return name;
    }

    double getScore() {
        return score;
    }

    // Setter
    void setScore(double newScore) {
        if (newScore >= 0 && newScore <= 100) {
            score = newScore;
        }
    }
};

#endif
