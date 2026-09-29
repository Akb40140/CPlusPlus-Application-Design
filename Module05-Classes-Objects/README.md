# Module 5 — Records, Headers & Functions

## Assignment
Create functions to add a record, display records, and calculate a simple result. Move at
least one function declaration into your own .h header file and implement it in a .cpp
file.

## What changed from Module 4
Module 4 kept each student in three parallel arrays (`names`, `ids`, `grades`). Here each
student is one **record**, a `struct` that groups the fields:

```cpp
struct StudentRecord {
    std::string name;
    int id;
    double mathScore;
};
```

The app holds `StudentRecord records[MAX_RECORDS]`. Moving or deleting a student is now
one assignment (`records[i] = records[i + 1];`) instead of three.

The program is also split across three files:

| File | Role |
|------|------|
| `RecordTools.h` | **Declarations.** Says which functions exist, what they take, and what they return. |
| `RecordTools.cpp` | **Definitions.** The code that does the work. |
| `main.cpp` | **Entry point.** Loads the data, runs the menu, and calls the functions. |

## How this is met
- **Add a record:** `addRecord(StudentRecord records[], int& count)` asks for a name, id
  and score, builds a `StudentRecord`, and stores it. `count` is passed **by reference**
  (`int&`), so the function changes the real count in `main`.
- **Display records:** `displayRecords()` prints the table. It takes the array as
  `const`, so it can read records but not change them.
- **Calculate a simple result:** `calculateAverage()` returns the average math score and
  returns `0` when there are no records, so it never divides by zero.
  `findHighestScore()` returns the index of the top score. Option 6, `showResults()`,
  prints both.
- **Own header file:** every record function is declared in `RecordTools.h` and
  implemented in `RecordTools.cpp`. `main.cpp` only has `#include "RecordTools.h"`.
- **Include guard:** `#ifndef RECORDTOOLS_H / #define RECORDTOOLS_H / #endif` stops the
  header being processed twice if more than one file includes it.

## Standard headers vs. user-defined headers
```cpp
#include <iostream>        // standard library: angle brackets, found in the compiler's folders
#include "RecordTools.h"   // our own header: quotes, found in this project folder
```
Both work the same way. They paste declarations into the file so the compiler knows a
function exists before it is called. The code behind `<iostream>` comes with the
compiler. The code behind `RecordTools.h` is `RecordTools.cpp`, so that file must be
compiled too.

## The purpose of main()
Every C++ program starts running at `main()`. Here `main()` only coordinates the
program. It creates the records array, calls `loadRecords()`, shows the menu in a loop,
and uses `switch` to hand each choice to a function. All the real work happens in
the functions.

## Files
| File | Purpose |
|------|---------|
| `main.cpp` | Menu and program flow |
| `RecordTools.h` | Record struct and function declarations |
| `RecordTools.cpp` | Function definitions |
| `students.csv` | Dataset excerpt (8 records, Kaggle *Students Performance in Exams*) |
| `.gitignore` | Keeps compiled binaries out of the repo |

## Build and run
Both `.cpp` files go on the compile line. `students.csv` must be in the folder you run
from.

```
g++ -std=c++17 -Wall -Wextra -o records main.cpp RecordTools.cpp
./records
```

## Sample run
```
Loaded 8 records from students.csv.
Record system ready!

=== STUDENT RECORD MANAGER ===
Records stored: 8 of 10
1. Add Record
2. Display Records
3. Search
4. Update Record
5. Delete Record
6. Calculate Results
7. Exit
Choose an option (1-7): 6

=== RESULTS ===
Records counted: 8
Average math score: 69.12
Highest score: Jordan with 90.00

Choose an option (1-7): 1

Enter student name: Taylor
Enter student id: 1009
Enter math score (0-100): 95
Record saved. 9 record(s) stored.

Choose an option (1-7): 2

=== ALL RECORDS ===
#    NAME                  ID        MATH SCORE
1    Ada                   1001      72.00
2    Sam                   1002      69.00
3    Jordan                1003      90.00
4    Riley                 1004      47.00
5    Casey                 1005      76.00
6    Morgan                1006      71.00
7    Avery                 1007      88.00
8    Quinn                 1008      40.00
9    Taylor                1009      95.00
```
