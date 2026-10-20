// Module 3 - Variables, Cin, Cout
// "Welcome to My Application" program

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    // Application information
    string appName = "Student Record Manager";   // text
    double version = 1.0;                         // decimal number
    int moduleNumber = 3;                         // whole number
    int totalRecords = 0;                         // whole number
    char appGrade = 'A';                          // single character
    bool isRunning = true;                        // true or false
    float loadTime = 0.5f;                        // decimal number (less memory)

    // Get the user's name with cin
    string userName;
    cout << "Enter your name: ";
    cin >> userName;

    // Welcome screen
    cout << endl;
    cout << "========================================" << endl;
    cout << "   WELCOME TO MY APPLICATION" << endl;
    cout << "========================================" << endl;
    cout << "User:          " << userName << endl;
    cout << "Application:   " << appName << endl;
    cout << "Version:       " << fixed << setprecision(1) << version << endl;
    cout << "Module:        " << moduleNumber << endl;
    cout << "Records Saved: " << totalRecords << endl;
    cout << "App Grade:     " << appGrade << endl;
    cout << "Running:       " << boolalpha << isRunning << endl;
    cout << "Load Time:     " << loadTime << " seconds" << endl;
    cout << "========================================" << endl;

    // Menu
    cout << endl;
    cout << "=== MAIN MENU ===" << endl;
    cout << "1. Add Record" << endl;
    cout << "2. View Records" << endl;
    cout << "3. Search" << endl;
    cout << "4. Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << endl;
    cout << "You chose option " << choice << ". Thanks for using " << appName << ", " << userName << "!" << endl;

    return 0;
}
