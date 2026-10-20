// Module 4 - Datasets, Arrays & Pointers
// Student Record Manager, now with real data from Kaggle stored in arrays.
//
// Dataset: "Students Performance in Exams" on Kaggle
// https://www.kaggle.com/datasets/spscientist/students-performance-in-exams
// I took the first 8 rows and kept the math score. The dataset doesn't have
// names, so I made some up.
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

const int MAX_RECORDS = 10;

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
        ids[count] = stoi(idText);       // text to int
        scores[count] = stod(scoreText); // text to double
        count++;
    }

    file.close();
    return count;
}

void displayRecords(string names[], int ids[], double scores[], int count) {
    for (int i = 0; i < count; i++) {
        cout << names[i] << " (id " << ids[i] << ") - " << scores[i] << endl;
    }
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

void pointerDemo(string names[], double scores[], int count) {
    if (count == 0) {
        cout << "No records loaded." << endl;
        return;
    }

    double* scorePtr = &scores[0];   // points to the first score
    cout << "First student: " << names[0] << endl;
    cout << "Score through pointer: " << *scorePtr << endl;
    cout << "Address in memory: " << scorePtr << endl;
}

void showMenu() {
    cout << "\n=== STUDENT RECORD MANAGER ===" << endl;
    cout << "1. Display Records" << endl;
    cout << "2. Search" << endl;
    cout << "3. Pointer Demo" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option (1-4): ";
}

int main() {
    // Parallel arrays: names[0], ids[0] and scores[0] are all the same student
    string names[MAX_RECORDS];
    int ids[MAX_RECORDS];
    double scores[MAX_RECORDS];
    int count = loadRecords("students.csv", names, ids, scores);
    int choice = 0;

    cout << "Loaded " << count << " records from students.csv." << endl;

    while (choice != 4) {
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
                displayRecords(names, ids, scores, count);
                break;
            case 2:
                searchRecords(names, ids, scores, count);
                break;
            case 3:
                pointerDemo(names, scores, count);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Pick 1-4." << endl;
        }
    }

    return 0;
}
