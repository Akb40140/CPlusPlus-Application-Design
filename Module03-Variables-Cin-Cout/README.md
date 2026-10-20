# Module 3 - Variables, Cin, Cout

## Assignment
Build a personalized "Welcome to My Application" program. Store the user's name,
application name, and version number in variables. Display them in a clean welcome
screen and push the project to GitHub.

## What I did
- The program asks for your name with `cin` and saves it in `userName`.
- The app name and version are stored in `appName` and `version`.
- I made 8 variables using 6 different types:

| Variable | Type |
|----------|------|
| `userName`, `appName` | string |
| `moduleNumber`, `totalRecords` | int |
| `version` | double |
| `loadTime` | float |
| `appGrade` | char |
| `isRunning` | bool |

- Everything is printed with `cout` on a welcome screen, then a simple menu.

## How to run
```
g++ -o welcome main.cpp
./welcome
```

## Sample output
```
Enter your name: Ahmed

========================================
   WELCOME TO MY APPLICATION
========================================
User:          Ahmed
Application:   Student Record Manager
Version:       1.0
Module:        3
Records Saved: 0
App Grade:     A
Running:       true
Load Time:     0.5 seconds
========================================
```
