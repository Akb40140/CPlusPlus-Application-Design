// Roster.h - the Roster class holds all the students.
// The students are in a dynamic array that stays sorted by id.
#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "Student.h"
using namespace std;

class Roster {
private:
    Student* students;   // dynamic array
    int count;           // how many students we have
    int capacity;        // how many students fit in the array

    void grow();

public:
    Roster();
    ~Roster();

    int getCount();
    int getCapacity();

    // File I/O
    void loadFromFile(string fileName);
    void saveToFile(string fileName);
    void writeReport(string fileName);

    // Add and delete
    bool addStudent(Student newStudent);
    bool deleteStudent(int id);

    // Search
    int binarySearch(int id);
    Student* findById(int id);
    void searchByName(string text);

    // Display
    void viewStudents();
    void showStats();

    // Statistics
    double getAverage();
    Student* getHighest();
    Student* getLowest();
};

#endif
