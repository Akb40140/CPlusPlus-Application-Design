# Module 5 - Records, Headers & Functions

## Assignment
Create functions to add a record, display records, and calculate a simple result. Move at
least one function declaration into your own .h header file and implement it in a .cpp
file.

## What I did
- `addRecord()` adds a new student, `displayRecords()` shows all of them, and
  `calculateAverage()` works out the average math score.
- The declarations for these functions are in my header file `RecordTools.h`, and the
  code for them is in `RecordTools.cpp`.
- `main.cpp` includes the header with `#include "RecordTools.h"` and runs the menu.
- I still load the same 8 records from `students.csv` that I used in Module 4.

`<iostream>` is a header that comes with C++. `RecordTools.h` is a header I wrote myself,
so it uses quotes instead of angle brackets.

## Files
- `main.cpp` - the menu
- `RecordTools.h` - function declarations
- `RecordTools.cpp` - function code
- `students.csv` - the data

## How to run
```
g++ -o records main.cpp RecordTools.cpp
./records
```

## Sample output
```
Loaded 8 records.
Record system ready!

=== STUDENT RECORD MANAGER ===
1. Add Record
2. Display Records
3. Search
4. Average Score
5. Exit
Choose an option (1-5): 4
Average math score: 69.125
```
