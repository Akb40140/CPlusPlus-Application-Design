# Module 8 - Input Validation & Protecting Data

## Assignment
Add validation to your application. Prevent invalid entries such as negative values, empty
names, or incorrectly formatted dates. Your program should give the user a useful error
message and allow them to try again.

## What I did
I made three validation functions in `Validation.h` / `Validation.cpp`. Each one keeps
asking until the input is good, and prints an error message that says what was wrong.

| Function | What it checks | Used for |
|----------|----------------|----------|
| `readName()` | Not empty, only letters, spaces, `-` or `'` | Your name at login, new student names |
| `readInt()` | A whole number, in a range, nothing extra typed after it (so `12abc` is rejected) | Menu choice (1-6), role (1-2), student id (1000-9999) |
| `readDouble()` | A number, in a range | Math score (0-100), so no negative scores |

Other checks:
- When adding a student, the program won't accept an id that's already used. It asks
  again instead of making a duplicate.
- Letters in a number field used to break `cin`. Now `cin.clear()` and `cin.ignore()`
  reset it and the user gets another try.
- The roles and binary search from Module 7 still work the same.

My app doesn't have dates, so I validated the fields it does have.

## Files
- `main.cpp` - menu, login, binary search and the record functions
- `Validation.h` / `Validation.cpp` - the validation functions
- `Student.h` - the Student class
- `User.h` - the User, Admin and RegularUser classes
- `students.csv` - the data

## How to run
```
g++ -o records main.cpp Validation.cpp
./records
```

## Sample output
```
Enter your name:
Error: the name can't be empty. Try again.
Enter your name: Ahmed
1. Admin
2. Regular User
Choose your role (1-2): 5
Error: enter a number from 1 to 2. Try again.
Choose your role (1-2): 1
Enter admin password: admin123
...
Choose an option (1-6): 3
Enter student name: T4ylor
Error: use only letters, spaces, - or '. Try again.
Enter student name: Taylor
Enter student id (1000-9999): 1004
Error: id 1004 is already used. Try again.
Enter student id (1000-9999): 1009
Enter math score (0-100): -5
Error: enter a number from 0 to 100. Try again.
Enter math score (0-100): 95.5
Student added.
```
