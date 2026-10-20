# Module 2 - Menus, Switch Case & Application Flow

## Assignment
Create a main menu for your application with at least five options. Use a loop so the
menu continues until the user chooses Exit. Use a switch/case statement to route each
choice to a function. Include input validation so an invalid menu choice does not
crash the program.

## What I did
- The menu has 6 options: Add, View, Search, Update, Delete and Exit.
- A `while` loop keeps showing the menu until you pick 6 (Exit).
- A `switch` sends each choice to its own function, like `addRecord()` and
  `viewRecords()`. They just print a message for now; I'll fill them in later modules.
- `readChoice()` handles bad input. If you type letters, `cin.clear()` and
  `cin.ignore()` reset it so the program doesn't get stuck in a loop. A number that
  isn't 1-6 goes to `default` and says "Invalid choice".

## How to run
```
g++ -o menu main.cpp
./menu
```

## Sample output
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
