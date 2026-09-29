// RecordTools.h - Module 5
// The header holds declarations only: what each record function is called,
// what it takes, and what it gives back. The code that does the work lives in
// RecordTools.cpp. Any file that wants these functions writes
//     #include "RecordTools.h"
// the same way main.cpp writes #include <iostream> for the standard library.

// Include guard: if this header gets included twice, the second copy is
// skipped, so nothing is declared twice.
#ifndef RECORDTOOLS_H
#define RECORDTOOLS_H

#include <string>

const int MAX_RECORDS = 10;   // how many records the array can hold

// One record groups the fields for one student, so a record is a single
// value instead of three parallel arrays that have to stay in step.
struct StudentRecord {
    std::string name;
    int id;
    double mathScore;
};

// ---- Input helpers ----
std::string readLine(std::string prompt);
double readNumber(std::string prompt);

// ---- Loading ----
// Reads students.csv into the array. Returns the number of records loaded,
// or -1 if the file could not be opened.
int loadRecords(std::string fileName, StudentRecord records[]);

// ---- Record functions ----
void showMessage();
void addRecord(StudentRecord records[], int& count);
void displayRecords(const StudentRecord records[], int count);
int findRecord(const StudentRecord records[], int count, std::string name);
void searchRecords(const StudentRecord records[], int count);
void updateRecord(StudentRecord records[], int count);
void deleteRecord(StudentRecord records[], int& count);

// ---- Calculations ----
double calculateAverage(const StudentRecord records[], int count);
int findHighestScore(const StudentRecord records[], int count);
void showResults(const StudentRecord records[], int count);

#endif
