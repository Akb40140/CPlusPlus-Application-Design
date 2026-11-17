// Validation.cpp - the code for the functions in Validation.h
#include <iostream>
#include <limits>
#include "Validation.h"
using namespace std;

// Throws away whatever is left on the line the user typed.
void clearLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// A name can't be empty and can only have letters, spaces, - and '
string readName(string prompt) {
    while (true) {
        string name;
        cout << prompt;
        getline(cin, name);

        if (cin.eof()) {
            return "Unknown";
        }

        bool hasLetter = false;
        bool allValid = true;
        bool allSpaces = true;
        for (int i = 0; i < (int)name.length(); i++) {
            char c = name[i];
            if (c != ' ') {
                allSpaces = false;
            }
            if (isalpha(c)) {
                hasLetter = true;
            } else if (c != ' ' && c != '-' && c != '\'') {
                allValid = false;
            }
        }

        if (allSpaces) {
            cout << "Error: the name can't be empty. Try again." << endl;
        } else if (!allValid || !hasLetter) {
            cout << "Error: use only letters, spaces, - or '. Try again." << endl;
        } else {
            return name;
        }
    }
}

// Keeps asking until the user types a whole number between min and max.
int readInt(string prompt, int min, int max) {
    while (true) {
        int value;
        cout << prompt;

        if (cin >> value) {
            // "12abc" reads 12, so make sure nothing else was typed
            if (cin.peek() != '\n') {
                cout << "Error: enter a whole number only. Try again." << endl;
            } else if (value < min || value > max) {
                cout << "Error: enter a number from " << min << " to " << max
                     << ". Try again." << endl;
            } else {
                clearLine();
                return value;
            }
        } else if (cin.eof()) {
            return min;
        } else {
            cout << "Error: that is not a number. Try again." << endl;
        }
        clearLine();
    }
}

// Same idea as readInt, but allows decimals like 87.5
double readDouble(string prompt, double min, double max) {
    while (true) {
        double value;
        cout << prompt;

        if (cin >> value) {
            if (cin.peek() != '\n') {
                cout << "Error: enter a number only. Try again." << endl;
            } else if (value < min || value > max) {
                cout << "Error: enter a number from " << min << " to " << max
                     << ". Try again." << endl;
            } else {
                clearLine();
                return value;
            }
        } else if (cin.eof()) {
            return min;
        } else {
            cout << "Error: that is not a number. Try again." << endl;
        }
        clearLine();
    }
}
