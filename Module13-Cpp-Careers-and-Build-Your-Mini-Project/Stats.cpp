// Stats.cpp - performance-focused features
#include <iostream>
#include "Stats.h"
using namespace std;

// Works out every statistic in ONE loop through the students instead of
// looping once for the average, again for the highest, and again for the lowest.
void showClassStats(Student students[], int count) {
    if (count == 0) {
        cout << "No students yet." << endl;
        return;
    }

    double total = 0;
    int highest = 0;
    int lowest = 0;
    int passing = 0;

    for (int i = 0; i < count; i++) {
        total += students[i].getScore();
        if (students[i].getScore() > students[highest].getScore()) {
            highest = i;
        }
        if (students[i].getScore() < students[lowest].getScore()) {
            lowest = i;
        }
        if (students[i].isPassing()) {
            passing++;
        }
    }

    cout << "\n--- Class Statistics ---" << endl;
    cout << "Students: " << count << endl;
    cout << "Average score: " << total / count << endl;
    cout << "Highest: " << students[highest].getName() << " ("
         << students[highest].getScore() << ")" << endl;
    cout << "Lowest: " << students[lowest].getName() << " ("
         << students[lowest].getScore() << ")" << endl;
    cout << "Passing: " << passing << " of " << count << endl;
}

// Shows why binary search matters when the app gets big. It makes 1,000,000
// sorted ids and counts how many checks each search needs to find the last one.
void searchSpeedTest() {
    const int SIZE = 1000000;
    int* ids = new int[SIZE];   // too big for a normal array, so use the heap
    for (int i = 0; i < SIZE; i++) {
        ids[i] = 1000 + i;
    }
    int target = ids[SIZE - 1];

    // Linear search: check one by one from the start
    int linearChecks = 0;
    for (int i = 0; i < SIZE; i++) {
        linearChecks++;
        if (ids[i] == target) {
            break;
        }
    }

    // Binary search: cut the list in half each time
    int binaryChecks = 0;
    int left = 0;
    int right = SIZE - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        binaryChecks++;
        if (ids[mid] == target) {
            break;
        }
        if (ids[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    delete[] ids;   // give the memory back

    cout << "\n--- Search Speed Test (1,000,000 students) ---" << endl;
    cout << "Linear search checks: " << linearChecks << endl;
    cout << "Binary search checks: " << binaryChecks << endl;
}
