// Module 2 - Menus, Switch Case & Application Flow
// Builds the main menu that will control the rest of the application.

#include <iostream>
#include <limits>
#include <string>
using namespace std;

void addRecord() {
    cout << "\n[Add Record] This is where a new record will be created." << endl;
}

void viewRecords() {
    cout << "\n[View Records] This is where all records will be listed." << endl;
}

void searchRecords() {
    cout << "\n[Search] This is where a record will be looked up." << endl;
}

void updateRecord() {
    cout << "\n[Update Record] This is where an existing record will be changed." << endl;
}

void deleteRecord() {
    cout << "\n[Delete Record] This is where a record will be removed." << endl;
}

void showMenu() {
    cout << "\n=== MY APPLICATION ===" << endl;
    cout << "1. Add Record" << endl;
    cout << "2. View Records" << endl;
    cout << "3. Search" << endl;
    cout << "4. Update Record" << endl;
    cout << "5. Delete Record" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option (1-6): ";
}

// Reads one menu choice. If the user types something that is not a number,
// cin goes into a fail state, so we clear it and throw away the bad input.
// Without this the program would loop forever on a letter like "abc".
int readChoice() {
    int choice = 0;

    while (!(cin >> choice)) {
        if (cin.eof()) {
            return 6;  // no more input, treat it as Exit
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That is not a number. Please enter 1-6: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

int main() {
    int choice = 0;

    while (choice != 6) {
        showMenu();
        choice = readChoice();

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                searchRecords();
                break;
            case 4:
                updateRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                cout << "\nGoodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please pick a number from 1 to 6." << endl;
        }
    }

    return 0;
}
