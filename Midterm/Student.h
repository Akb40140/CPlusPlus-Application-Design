// Student.h - the Student class
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    double score;

public:
    // Default constructor, needed to make an array of Students
    Student();
    Student(string studentName, int studentId, double studentScore);

    void displayStudent();
    bool isPassing();
    char getLetterGrade();

    // Getters
    string getName();
    int getId();
    double getScore();

    // Setter
    void setScore(double newScore);
};

#endif
