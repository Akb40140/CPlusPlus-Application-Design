// Student.h - the Student class definition
// The member functions are written in Student.cpp
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    // Private data members, only the class's own functions can change them
    string name;
    int id;
    double score;

public:
    // Constructors
    Student();   // default constructor, needed to make an array of Students
    Student(string studentName, int studentId, double studentScore);

    // Member functions
    void displayStudent();
    bool isPassing();

    // Getters
    string getName();
    int getId();
    double getScore();

    // Setter
    void setScore(double newScore);
};

#endif
