// Module 5 - Records, Headers & Functions
// Student Record Manager, now split into main.cpp, RecordTools.h and RecordTools.cpp
#include <iostream>
#include <limits>
#include "RecordTools.h"
using namespace std;

void showMenu() {
    cout << "\n=== STUDENT RECORD MANAGER ===" << endl;
    cout << "1. Add Record" << endl;
    cout << "2. Display Records" << endl;
    cout << "3. Search" << endl;
    cout << "4. Average Score" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option (1-5): ";
}

void searchRecords(string names[], int ids[], double scores[], int count) {
    string target;
    cout << "Enter a name: ";
    getline(cin, target);

    for (int i = 0; i < count; i++) {
        if (names[i] == target) {
            cout << names[i] << " (id " << ids[i] << ") - " << scores[i] << endl;
            return;
        }
    }
    cout << "No record found." << endl;
}

int main() {
    string names[MAX_RECORDS];
    int ids[MAX_RECORDS];
    double scores[MAX_RECORDS];
    int count = loadRecords("students.csv", names, ids, scores);
    int choice = 0;

    cout << "Loaded " << count << " records." << endl;
    showMessage();

    while (choice != 5) {
        showMenu();
        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();   // bad input like "abc"
            choice = 0;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addRecord(names, ids, scores, &count);
                break;
            case 2:
                displayRecords(names, ids, scores, count);
                break;
            case 3:
                searchRecords(names, ids, scores, count);
                break;
            case 4:
                cout << "Average math score: " << calculateAverage(scores, count) << endl;
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Pick 1-5." << endl;
        }
    }

    return 0;
}
