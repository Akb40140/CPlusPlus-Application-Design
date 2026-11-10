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
8. Input Validation & Protecting Data
9. Using AI to Expand Your Application

## Where I used input validation (Module 8)
All of the checks are in `Validation.h` / `Validation.cpp` in
`Module08-Input-Validation-and-Protecting-Data`. Each function keeps asking until the input
is good, and it prints an error message that says what was wrong.

- **Login name** (`readName()`): it can't be empty or only spaces, and it can only use
  letters, spaces, `-` or `'`.
- **Role choice** (`readInt()`): it has to be 1 or 2.
- **Menu choice** (`readInt()`): it has to be a whole number from 1 to 6. Letters like
  `abc` and mixed input like `3abc` are rejected.
- **New student name** (`readName()`): same rules as the login name, so `T4ylor` is
  rejected.
- **Student id** (`readInt()`): it has to be a whole number from 1000 to 9999. When adding
  a student, an id that's already taken is rejected so there are no duplicates.
- **Math score** (`readDouble()`, used for add and update): it has to be a number from 0 to
  100, so negative scores are rejected.
- **Bad input in `cin`**: if letters are typed into a number field, `cin.clear()` and
  `cin.ignore()` reset the input so the program doesn't break and the user can try again.

My app doesn't have dates, so I validated the fields it does have.

## Module 9 response: Using AI to Expand My Application
**My AI feature: AI Study Coach.** You pick a student and the coach gives that student one
short, personal study tip based on their math score.

- **What it does:** It looks at a student's math score, compares it to the class average,
  and gives one study tip that fits how the student is doing.
- **What data it needs:** The student's name, their math score, and the class average.
  Later it could also use older test scores or other subjects to spot trends.
- **What the user sees:** A new menu option, `6. AI Study Coach`. The user enters a student
  id, and the program shows the prompt it sent and the tip it got back.
- **Where AI fits in my app:** The AI is one more part of the program, and the menu,
  roles, validation and binary search all stay the same.
  ```
  User request    -> enter a student id (found with binary search)
  Prepare data    -> buildPrompt() turns the student into a text prompt
  AI service      -> mockAIService()  <-- a real AI API would go here
  Receive result  -> the tip comes back as a string
  Validate result -> isValidResponse() checks it isn't empty or too long
  Display to user -> runStudyCoach() prints the tip
  ```
- **Mock version:** I don't have a live AI service, so `mockAIService()` uses simple rules
  and picks a tip based on whether the score is under 50, 50-69, 70-84, or 85+. Because the
  rest of the code only calls `mockAIService()`, I could swap in a real AI call later
  without changing anything else. I check the answer before showing it because a real AI
  could send back something empty or too long.

The code is in `Module09-Using-AI-to-Expand-Your-Application`.

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
