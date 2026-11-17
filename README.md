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

<!-- -->
12. C++ & AI

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

## Module 12 response: C++ & AI
**The AI system I researched: PyTorch.** PyTorch is one of the most popular tools for
building and training AI models. Meta created it, and it's now run by the PyTorch
Foundation. Most people write PyTorch code in Python, but the heavy work underneath is
done in C++.

- **What C++ contributes:**
  - **Speed.** Tensors (the big grids of numbers AI models use) and the math on them are
    handled by a C++ library called ATen. Python gives the instructions, and C++ does the
    millions of calculations.
  - **Training.** The autograd engine, which works out how to adjust the model while it
    learns, is written in C++.
  - **GPUs.** The code that runs on NVIDIA graphics cards is written in CUDA, which is
    based on C++.
  - **Running models without Python.** LibTorch is PyTorch's C++ version. It lets a
    trained model run inside apps, games, robots and devices where Python would be too
    slow or too big.
- **My performance feature:** I added two menu options to the Student Record Manager, in
  `Stats.h` / `Stats.cpp`.
  - `7. Class Statistics` works out the average, highest score, lowest score and number
    of passing students in one loop, where doing each one separately would take four.
  - `8. Search Speed Test` makes 1,000,000 sorted student ids with `new int[]`, counts
    how many checks each search needs to find the last one, and frees the memory with
    `delete[]`.
    ```
    --- Search Speed Test (1,000,000 students) ---
    Linear search checks: 1000000
    Binary search checks: 20
    ```
- **Where C++ would help if my app got much bigger:** With records for a whole school
  district, C++ would matter for searching and sorting hundreds of thousands of students,
  working out statistics for every class at once, controlling memory so the app doesn't
  waste RAM, and preparing the AI Study Coach's data quickly before it goes to an AI
  service.

The code is in `Module12-Cpp-and-AI`.

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

To run the Module 12 version with the statistics and speed test options:
```
cd Module12-Cpp-and-AI
g++ -o records main.cpp Validation.cpp AICoach.cpp Stats.cpp
./records
```
