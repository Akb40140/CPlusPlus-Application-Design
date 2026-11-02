# C++-Application-Design

**Name:** Ahmed Mohammed

**Class:** Teach C++

**Application:** Student Record Manager

My C++ Application Design class projects and assignments.

## About my application
The Student Record Manager keeps track of students and their math scores. It loads
students from a CSV file (from a Kaggle dataset), lets an Admin add, update and delete
students, and lets a Regular User view and search. Students are kept sorted by id and
found with binary search. Each module added a new part to it.

## Completed Modules
1. Set Up GitHub & Your Development Environment
2. Menus, Switch Case & Application Flow
3. Variables, Cin, Cout
4. Datasets, Arrays & Pointers
5. Records, Headers & Functions
6. Creating Classes & Objects
7. Security, Roles & Binary Search

## Midterm Project
The C++ Midway Project is in `Midterm`. It builds on Module 7 with a `Roster` class, a
dynamic array, search by name, class statistics and saving to a file.

## How to run the application
The newest version is in `Midterm`.
```
cd Midterm
g++ -o records main.cpp Student.cpp Roster.cpp
./records
```
The Admin password for the demo is `admin123`.
