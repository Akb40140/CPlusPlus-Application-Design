// RecordTools.cpp - Module 5
// Definitions for everything declared in RecordTools.h. Including our own
// header first means the compiler checks that each definition here matches
// its declaration there.

#include "RecordTools.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

// ---- Input helpers -------------------------------------------------------

// Reads one whole line so names with spaces still work.
string readLine(string prompt) {
    string line;
    cout << prompt;
    getline(cin, line);
    return line;
}

// Reads a number and rejects anything that is not one.
double readNumber(string prompt) {
    double value = 0.0;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        if (cin.eof()) {
            return 0.0;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That is not a number. Try again." << endl;
    }
}

// ---- Loading -------------------------------------------------------------

// Each line of the file looks like:
//
//     Ada,1001,72
//
// getline(file, text, ',') reads up to the next comma, so the fields come off
// one at a time, and stoi/stod turn the number text into numbers.
int loadRecords(string fileName, StudentRecord records[]) {
    ifstream file(fileName);

    if (!file.is_open()) {
        return -1;
    }

    string headerLine;
    getline(file, headerLine);   // skip the column titles on line 1

    string name, idText, scoreText;
    int count = 0;

    while (count < MAX_RECORDS &&
           getline(file, name, ',') &&
           getline(file, idText, ',') &&
           getline(file, scoreText)) {

        if (name == "") {
            continue;   // skip a blank line at the end of the file
        }

        records[count].name = name;
        records[count].id = stoi(idText);
        records[count].mathScore = stod(scoreText);
        count++;
    }

    file.close();
    return count;
}

// ---- Record functions ----------------------------------------------------

void showMessage() {
    cout << "Record system ready!" << endl;
}

// count is passed by reference (int&), so adding one here changes the real
// count in main instead of a copy.
void addRecord(StudentRecord records[], int& count) {
    cout << endl;
    if (count >= MAX_RECORDS) {
        cout << "The list is full. Delete a record first." << endl;
        return;
    }

    StudentRecord newRecord;
    newRecord.name = readLine("Enter student name: ");
    newRecord.id = (int)readNumber("Enter student id: ");
    newRecord.mathScore = readNumber("Enter math score (0-100): ");

    records[count] = newRecord;
    count++;
    cout << "Record saved. " << count << " record(s) stored." << endl;
}

// const means this function can read the records but not change them.
void displayRecords(const StudentRecord records[], int count) {
    cout << endl;
    if (count == 0) {
        cout << "No records yet. Use option 1 to add one." << endl;
        return;
    }

    cout << "=== ALL RECORDS ===" << endl;
    cout << left << setw(5) << "#" << setw(22) << "NAME"
         << setw(10) << "ID" << "MATH SCORE" << endl;

    for (int i = 0; i < count; i++) {
        cout << left << setw(5) << (i + 1)
             << setw(22) << records[i].name
             << setw(10) << records[i].id
             << fixed << setprecision(2) << records[i].mathScore << endl;
    }
}

// Returns the index of the matching record, or -1 when there is no match.
int findRecord(const StudentRecord records[], int count, string name) {
    for (int i = 0; i < count; i++) {
        if (records[i].name == name) {
            return i;
        }
    }
    return -1;
}

void searchRecords(const StudentRecord records[], int count) {
    cout << endl;
    string target = readLine("Enter the name to search for: ");
    int index = findRecord(records, count, target);

    if (index == -1) {
        cout << "No record found for " << target << "." << endl;
        return;
    }

    cout << "Found in slot " << (index + 1) << ": " << records[index].name
         << " (id " << records[index].id << ") - "
         << fixed << setprecision(2) << records[index].mathScore << endl;
}

void updateRecord(StudentRecord records[], int count) {
    cout << endl;
    string target = readLine("Enter the name to update: ");
    int index = findRecord(records, count, target);

    if (index == -1) {
        cout << "No record found for " << target << "." << endl;
        return;
    }

    records[index].mathScore = readNumber("Enter the new math score: ");
    cout << "Updated " << records[index].name << "." << endl;
}

void deleteRecord(StudentRecord records[], int& count) {
    cout << endl;
    string target = readLine("Enter the name to delete: ");
    int index = findRecord(records, count, target);

    if (index == -1) {
        cout << "No record found for " << target << "." << endl;
        return;
    }

    // Shift every later record back one slot so there is no hole. Because a
    // record is one struct, a single assignment moves all of its fields.
    for (int i = index; i < count - 1; i++) {
        records[i] = records[i + 1];
    }

    count--;
    cout << "Deleted " << target << ". " << count << " record(s) left." << endl;
}

// ---- Calculations --------------------------------------------------------

// The simple result: the class average. Returns 0 when there are no records
// so we never divide by zero.
double calculateAverage(const StudentRecord records[], int count) {
    if (count == 0) {
        return 0.0;
    }

    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += records[i].mathScore;
    }
    return total / count;
}

// Returns the index of the highest score, or -1 when there are no records.
int findHighestScore(const StudentRecord records[], int count) {
    if (count == 0) {
        return -1;
    }

    int best = 0;
    for (int i = 1; i < count; i++) {
        if (records[i].mathScore > records[best].mathScore) {
            best = i;
        }
    }
    return best;
}

void showResults(const StudentRecord records[], int count) {
    cout << endl;
    if (count == 0) {
        cout << "No records yet, so there is nothing to calculate." << endl;
        return;
    }

    int best = findHighestScore(records, count);

    cout << "=== RESULTS ===" << endl;
    cout << "Records counted: " << count << endl;
    cout << "Average math score: " << fixed << setprecision(2)
         << calculateAverage(records, count) << endl;
    cout << "Highest score: " << records[best].name << " with "
         << records[best].mathScore << endl;
}
