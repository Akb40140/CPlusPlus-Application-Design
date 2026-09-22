// Module 4 - Datasets, Arrays, and Pointers
// Builds on the Module 2 menu app. A small Kaggle dataset is loaded into
// parallel arrays, and every function reaches that data through pointers.
//
// Dataset: "Students Performance in Exams" (Kaggle, spscientist)
// https://www.kaggle.com/datasets/spscientist/students-performance-in-exams
// The source rows are anonymous, so the first 8 were cut down to three fields
// and given placeholder names, since the app searches by name.

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

const int MAX_RECORDS = 10;   // how many records the arrays can hold

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

// ---- Dataset -------------------------------------------------------------
// The arrays live in main(). Every function below receives them as pointers,
// so nothing is copied and the functions work on the real data.

// Copies the dataset excerpt into the arrays. 8 of the 10 slots are used, so
// there is room left to add records from the menu.
void loadDataset(string* nameList, int* idList, double* gradeList, int* count) {
    const int SIZE = 8;

    string sourceNames[SIZE]  = {"Ada",   "Sam",    "Jordan", "Riley",
                                 "Casey", "Morgan", "Avery",  "Quinn"};
    int    sourceIds[SIZE]    = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008};
    double sourceGrades[SIZE] = {72.0, 69.0, 90.0, 47.0, 76.0, 71.0, 88.0, 40.0};

    for (int i = 0; i < SIZE; i++) {
        *(nameList + i)  = sourceNames[i];
        *(idList + i)    = sourceIds[i];
        *(gradeList + i) = sourceGrades[i];
    }

    *count = SIZE;   // written through the pointer, so main sees it
}

// ---- Finding a record ----------------------------------------------------

// Returns a pointer to the matching name, or nullptr when there is no match.
// Returning an address lets the caller edit the record it found.
string* findRecord(string* nameList, int count, string target) {
    for (int i = 0; i < count; i++) {
        // *(nameList + i) is pointer arithmetic for nameList[i].
        if (*(nameList + i) == target) {
            return nameList + i;
        }
    }
    return nullptr;
}

// Pointer subtraction: the gap between the two addresses is the slot number.
int slotOf(string* found, string* nameList) {
    return found - nameList;
}

// ---- Menu actions --------------------------------------------------------

void addRecord(string* nameList, int* idList, double* gradeList, int* count) {
    // *count dereferences the pointer to read the real record count.
    if (*count >= MAX_RECORDS) {
        cout << "\nThe dataset is full. Delete a record first." << endl;
        return;
    }

    cout << endl;
    *(nameList + *count)  = readLine("Enter student name: ");
    *(idList + *count)    = (int)readNumber("Enter student id: ");
    *(gradeList + *count) = readNumber("Enter math score (0-100): ");

    (*count)++;   // writing through the pointer updates the count in main
    cout << "Record saved in slot " << *count << "." << endl;
}

void viewRecords(string* nameList, int* idList,
                 double* gradeList, int count) {
    cout << endl;
    if (count == 0) {
        cout << "No records yet. Use option 1 to add one." << endl;
        return;
    }

    cout << "=== ALL RECORDS ===" << endl;
    cout << left << setw(5) << "#" << setw(22) << "NAME"
         << setw(10) << "ID" << "MATH SCORE" << endl;

    // Walk the arrays with pointers instead of an index.
    for (int i = 0; i < count; i++) {
        cout << left << setw(5) << (i + 1)
             << setw(22) << *(nameList + i)
             << setw(10) << *(idList + i)
             << fixed << setprecision(2) << *(gradeList + i) << endl;
    }
}

void searchRecords(string* nameList, int* idList,
                   double* gradeList, int count) {
    cout << endl;
    string target = readLine("Enter the name to search for: ");
    string* found = findRecord(nameList, count, target);

    if (found == nullptr) {
        cout << "No record found for " << target << "." << endl;
        return;
    }

    int slot = slotOf(found, nameList);
    cout << "Found in slot " << (slot + 1) << ": "
         << *found << " (id " << idList[slot] << ") - "
         << fixed << setprecision(2) << gradeList[slot] << endl;
}

void updateRecord(string* nameList, double* gradeList, int count) {
    cout << endl;
    string target = readLine("Enter the name to update: ");
    string* found = findRecord(nameList, count, target);

    if (found == nullptr) {
        cout << "No record found for " << target << "." << endl;
        return;
    }

    gradeList[slotOf(found, nameList)] = readNumber("Enter the new math score: ");
    cout << "Updated " << *found << "." << endl;
}

void deleteRecord(string* nameList, int* idList, double* gradeList, int* count) {
    cout << endl;
    string target = readLine("Enter the name to delete: ");
    string* found = findRecord(nameList, *count, target);

    if (found == nullptr) {
        cout << "No record found for " << target << "." << endl;
        return;
    }

    // Shift every later record back one slot so there is no hole.
    for (int i = slotOf(found, nameList); i < *count - 1; i++) {
        nameList[i] = nameList[i + 1];
        idList[i] = idList[i + 1];
        gradeList[i] = gradeList[i + 1];
    }

    (*count)--;
    cout << "Deleted " << target << ". " << *count << " record(s) left." << endl;
}

void showAverage(double* gradeList, int count) {
    cout << endl;
    if (count == 0) {
        cout << "No records yet, so there is no average." << endl;
        return;
    }

    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += *(gradeList + i);
    }
    cout << "Average math score for " << count << " record(s): "
         << fixed << setprecision(2) << (total / count) << endl;
}

// The assignment asks for one value reached through a pointer. This is that
// demonstration on its own: a pointer aimed at a single array element.
void pointerDemo(string* nameList, double* gradeList, int count) {
    cout << endl;
    if (count == 0) {
        cout << "Load or add a record first." << endl;
        return;
    }

    cout << "=== POINTER DEMO ===" << endl;

    // &gradeList[0] is the address of the first score.
    double* scorePtr = &gradeList[0];
    cout << "scorePtr points at slot 1." << endl;
    cout << "  *scorePtr (the value)  = "
         << fixed << setprecision(2) << *scorePtr << endl;
    cout << "  scorePtr (the address) = " << scorePtr << endl;

    if (count > 1) {
        scorePtr++;   // step forward one element and read through it again
        cout << "After scorePtr + 1 it points at slot 2." << endl;
        cout << "  *scorePtr (the value)  = " << *scorePtr << endl;
        cout << "  scorePtr (the address) = " << scorePtr << endl;
        cout << "The address moved by 8 bytes, the size of one double." << endl;
    }

    // The same idea on the name array, where each element is a string.
    cout << "First name through a pointer: " << *nameList << endl;
}

// ---- Menu ----------------------------------------------------------------

void showMenu(int count) {
    cout << "\n=== STUDENT RECORD MANAGER ===" << endl;
    cout << "Records stored: " << count << " of " << MAX_RECORDS << endl;
    cout << "1. Add Record" << endl;
    cout << "2. View Records" << endl;
    cout << "3. Search" << endl;
    cout << "4. Update Record" << endl;
    cout << "5. Delete Record" << endl;
    cout << "6. Show Average Score" << endl;
    cout << "7. Pointer Demo" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose an option (1-8): ";
}

// Same validation idea as Module 2: a letter puts cin in a fail state, so we
// clear it and throw the bad text away instead of looping forever.
int readChoice() {
    int choice = 0;

    while (!(cin >> choice)) {
        if (cin.eof()) {
            return 8;   // no more input, treat it as Exit
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That is not a number. Please enter 1-8: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

int main() {
    // Position i in each array is the same student: names[2], ids[2] and
    // grades[2] are all record 3.
    string names[MAX_RECORDS];
    int ids[MAX_RECORDS];
    double grades[MAX_RECORDS];
    int recordCount = 0;        // how many slots are actually filled
    int choice = 0;

    // An array name is the address of its first element, so passing names
    // passes a pointer. &recordCount lets a function change the count itself.
    loadDataset(names, ids, grades, &recordCount);
    cout << "Loaded " << recordCount
         << " records from the Kaggle dataset excerpt." << endl;
    viewRecords(names, ids, grades, recordCount);
    pointerDemo(names, grades, recordCount);

    while (choice != 8) {
        showMenu(recordCount);
        choice = readChoice();

        switch (choice) {
            case 1:
                addRecord(names, ids, grades, &recordCount);
                break;
            case 2:
                viewRecords(names, ids, grades, recordCount);
                break;
            case 3:
                searchRecords(names, ids, grades, recordCount);
                break;
            case 4:
                updateRecord(names, grades, recordCount);
                break;
            case 5:
                deleteRecord(names, ids, grades, &recordCount);
                break;
            case 6:
                showAverage(grades, recordCount);
                break;
            case 7:
                pointerDemo(names, grades, recordCount);
                break;
            case 8:
                cout << "\nGoodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please pick a number from 1 to 8." << endl;
        }
    }

    return 0;
}
