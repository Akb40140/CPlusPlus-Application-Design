// Module 5 - Records, Headers & Functions
// Builds on the Module 4 app. Each student is now one StudentRecord, and the
// record functions have moved out of this file:
//   RecordTools.h   - declarations (what the functions are)
//   RecordTools.cpp - definitions  (how they work)
// main.cpp only runs the menu and calls those functions.
//
// Dataset: "Students Performance in Exams" (Kaggle, spscientist)
// https://www.kaggle.com/datasets/spscientist/students-performance-in-exams

#include <iostream>             // standard library header, angle brackets
#include <limits>
#include "RecordTools.h"        // our own header, quotes
using namespace std;

void showMenu(int count) {
    cout << "\n=== STUDENT RECORD MANAGER ===" << endl;
    cout << "Records stored: " << count << " of " << MAX_RECORDS << endl;
    cout << "1. Add Record" << endl;
    cout << "2. Display Records" << endl;
    cout << "3. Search" << endl;
    cout << "4. Update Record" << endl;
    cout << "5. Delete Record" << endl;
    cout << "6. Calculate Results" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose an option (1-7): ";
}

// A letter puts cin in a fail state, so we clear it and throw the bad text
// away instead of looping forever.
int readChoice() {
    int choice = 0;

    while (!(cin >> choice)) {
        if (cin.eof()) {
            return 7;   // no more input, treat it as Exit
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That is not a number. Please enter 1-7: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

// main() is where every C++ program starts. It sets up the data, then hands
// each job to a function.
int main() {
    StudentRecord records[MAX_RECORDS];
    int recordCount = 0;
    int choice = 0;

    int loaded = loadRecords("students.csv", records);
    if (loaded == -1) {
        cout << "Could not open students.csv. Starting with no records." << endl;
    } else {
        recordCount = loaded;
        cout << "Loaded " << recordCount << " records from students.csv." << endl;
    }
    showMessage();

    while (choice != 7) {
        showMenu(recordCount);
        choice = readChoice();

        switch (choice) {
            case 1:
                addRecord(records, recordCount);
                break;
            case 2:
                displayRecords(records, recordCount);
                break;
            case 3:
                searchRecords(records, recordCount);
                break;
            case 4:
                updateRecord(records, recordCount);
                break;
            case 5:
                deleteRecord(records, recordCount);
                break;
            case 6:
                showResults(records, recordCount);
                break;
            case 7:
                cout << "\nGoodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please pick a number from 1 to 7." << endl;
        }
    }

    return 0;
}
