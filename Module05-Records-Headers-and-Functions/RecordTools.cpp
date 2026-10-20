// RecordTools.cpp - the code for the functions in RecordTools.h
#include <iostream>
#include <fstream>
#include <iomanip>
#include "RecordTools.h"
using namespace std;

void showMessage() {
    cout << "Record system ready!" << endl;
}

// Reads students.csv into the arrays and returns how many records it read.
int loadRecords(string fileName, string names[], int ids[], double scores[]) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not open " << fileName << "." << endl;
        return 0;
    }

    string header, name, idText, scoreText;
    getline(file, header);   // skip the first line

    int count = 0;
    while (count < MAX_RECORDS && getline(file, name, ',') &&
           getline(file, idText, ',') && getline(file, scoreText)) {
        names[count] = name;
        ids[count] = stoi(idText);
        scores[count] = stod(scoreText);
        count++;
    }

    file.close();
    return count;
}

void addRecord(string names[], int ids[], double scores[], int* count) {
    if (*count >= MAX_RECORDS) {
        cout << "The list is full." << endl;
        return;
    }

    cout << "Enter student name: ";
    getline(cin, names[*count]);
    cout << "Enter student id: ";
    cin >> ids[*count];
    cout << "Enter math score: ";
    cin >> scores[*count];
    cin.ignore(1000, '\n');

    (*count)++;
    cout << "Record added." << endl;
}

void displayRecords(string names[], int ids[], double scores[], int count) {
    if (count == 0) {
        cout << "No records yet." << endl;
        return;
    }

    cout << left << setw(12) << "NAME" << setw(8) << "ID" << "SCORE" << endl;
    for (int i = 0; i < count; i++) {
        cout << left << setw(12) << names[i] << setw(8) << ids[i]
             << scores[i] << endl;
    }
}

double calculateAverage(double scores[], int count) {
    if (count == 0) {
        return 0;
    }

    double total = 0;
    for (int i = 0; i < count; i++) {
        total += scores[i];
    }
    return total / count;
}
