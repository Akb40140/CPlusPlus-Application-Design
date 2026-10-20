# Module 2 — Menus, Switch Case & Application Flow

## Assignment
Create a main menu for your application with at least five options. Use a loop so the
menu continues until the user chooses Exit. Use a switch/case statement to route each
choice to a function. Include input validation so an invalid menu choice does not
crash the program.

## How this is met
- **Six options** (Add, View, Search, Update, Delete, Exit) — more than the five required.
- **Loop:** `while (choice != 6)` keeps the menu on screen until Exit is chosen.
- **Switch/case:** each choice calls its own function (`addRecord()`, `viewRecords()`,
  `searchRecords()`, `updateRecord()`, `deleteRecord()`).
- **Input validation:** `readChoice()` handles two bad-input cases.
  - Non-numeric input (e.g. `abc`) puts `cin` in a fail state. We call `cin.clear()`
    and `cin.ignore(...)` to discard the bad text and re-prompt. Without this the
    program would spin in an infinite loop.
  - A number outside 1–6 falls to `default:` and re-prompts.
  - End-of-input is treated as Exit so the program never hangs.

## Build and run
```
g++ -std=c++17 -Wall -Wextra -o menu main.cpp
./menu
```

## Sample run
```
=== MY APPLICATION ===
1. Add Record
2. View Records
3. Search
4. Update Record
5. Delete Record
6. Exit
Choose an option (1-6): abc
That is not a number. Please enter 1-6: 99
Invalid choice. Please pick a number from 1 to 6.
```
