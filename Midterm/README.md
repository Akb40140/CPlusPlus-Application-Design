# C++ Midway Project - Student Record Manager

The report with screenshots is in `output.pdf`.

## What it does
Keeps track of students and their math scores. Anyone can view the list, search by id or
name, see class statistics, and write a report to `report.txt`. An Admin can also add
students, update scores, and delete students. Changes are saved to `students.csv`.

## Files
- `main.cpp` - login, menu and the menu actions
- `Roster.h`, `Roster.cpp` - the dynamic array, searches, statistics and file I/O
- `Student.h`, `Student.cpp` - the Student class
- `User.h` - the User, Admin and RegularUser classes
- `students.csv` - the data
- `output.pdf` - the report

## How to run
```
g++ -o records main.cpp Student.cpp Roster.cpp
./records
```
The Admin password for the demo is `admin123`.
