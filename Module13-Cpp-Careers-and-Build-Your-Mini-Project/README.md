# Module 13 - C++ Careers & Build Your Mini Project

## Assignment
Build a mini C++ application using at least four course topics. Your project should
include data storage, functions, input validation, a search feature, and a clear user
experience. Document which modules you used.

## About the app
The Student Record Manager keeps track of students and their math scores. A teacher logs
in as Admin to add, update and delete students. A helper logs in as a Regular User and
can only view and search. Everyone can see class statistics and get a study tip from the
AI Study Coach.

This is the app I built all semester, finished off. The new part in this module is
**saving**: every add, update and delete is written back to `students.csv`, so the
changes are still there the next time the program runs.

## Required parts
| Requirement | How my app does it |
|-------------|--------------------|
| Data storage | Loads from `students.csv` with `ifstream` and saves back with `ofstream` after every change (`saveStudents()`) |
| Functions | Every menu option is its own function, split across `main.cpp`, `Validation.cpp`, `AICoach.cpp` and `Stats.cpp` |
| Input validation | `readName()`, `readInt()`, `readDouble()` reject empty names, letters in numbers, out-of-range ids and scores, and duplicate ids |
| Search | Binary search by student id on the sorted list |
| Clear user experience | Numbered menu showing who is logged in, labels on Admin-only options, and error messages that say what to fix |

## Modules I used
| Module | Topic | Where it is in the app |
|--------|-------|------------------------|
| 2 | Menus, switch case | Main menu loop and `switch` |
| 3 | Variables, cin, cout | All input and output |
| 4 | Datasets, arrays, pointers | Kaggle data in `students.csv`, `Student students[]`, `int* count` |
| 5 | Headers and functions | `.h` / `.cpp` files for validation, AI coach and stats |
| 6 | Classes and objects | `Student` class with private data, constructor, getters and setter |
| 7 | Roles and binary search | `User`, `Admin`, `RegularUser` and `binarySearch()` |
| 8 | Input validation | `Validation.cpp` |
| 9 | AI in an application | AI Study Coach (mock) |
| 12 | C++ and performance | One-pass class statistics and the search speed test |
| 13 | Data storage | Saving changes back to the file |

**Original feature:** the AI Study Coach, which picks a study tip based on a student's
score and checks the answer before showing it.

## Files
- `main.cpp` - menu, login, binary search, record functions, saving
- `Student.h` - Student class
- `User.h` - User, Admin and RegularUser classes
- `Validation.h` / `Validation.cpp` - input validation
- `AICoach.h` / `AICoach.cpp` - AI Study Coach
- `Stats.h` / `Stats.cpp` - class statistics and search speed test
- `students.csv` - the data (this file changes when you add, update or delete)

## How to run
```
g++ -o records main.cpp Validation.cpp AICoach.cpp Stats.cpp
./records
```
Admin password for the demo: `admin123`

## Sample output
```
Loaded 8 students.
Enter your name: Ahmed
1. Admin
2. Regular User
Choose your role (1-2): 1
Enter admin password: admin123

=== STUDENT RECORD MANAGER ===
Logged in as Ahmed (Admin)
1. View Students
2. Search by ID
3. Add Student (Admin)
4. Update Score (Admin)
5. Delete Student (Admin)
6. AI Study Coach
7. Class Statistics
8. Search Speed Test
9. Exit
Choose an option (1-9): 3
Enter student name: Taylor Lee
Enter student id (1000-9999): 1009
Enter math score (0-100): 95.5
Student added.
Saved to students.csv.
```
