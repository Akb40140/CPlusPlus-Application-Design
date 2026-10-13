# Module 7 - Security, Roles & Binary Search

## Assignment
Create Admin and Regular User roles. Restrict actions based on the user's role. Store
records in sorted order and implement a binary search to find a record by ID or another
unique field.

## What I did
- **Roles:** `User.h` has a `User` class with a protected `username` and `role`.
  `Admin` and `RegularUser` inherit from `User`. When the program starts it asks for your
  name and role. Picking Admin needs a password (`admin123`, just for this demo). A wrong
  password logs you in as a Regular User.
- **Restricting actions:** Everyone can view and search. Add, update and delete call
  `user.canEdit()` first, and a Regular User gets "Access denied. Only an Admin can do
  that."
- **Sorted order:** `insertSorted()` puts every student in the right spot by id, both
  when loading `students.csv` and when adding a new student. Deleting shifts the rest
  back, so the list stays sorted.
- **Binary search:** `binarySearch()` finds a student by id. It checks the middle of the
  list and throws away the half the id can't be in, so it only takes a few steps. Search,
  update, delete, and the duplicate-id check when adding all use it.

## Files
- `main.cpp` - menu, login, binary search and the record functions
- `Student.h` - the Student class (I added `getId()`)
- `User.h` - the User, Admin and RegularUser classes
- `students.csv` - the data

## How to run
```
g++ -o records main.cpp
./records
```

## Sample output
```
Loaded 8 students.
Enter your name: Sam
1. Admin
2. Regular User
Choose your role: 2

=== STUDENT RECORD MANAGER ===
Logged in as Sam (Regular User)
1. View Students
2. Search by ID
3. Add Student (Admin)
4. Update Score (Admin)
5. Delete Student (Admin)
6. Exit
Choose an option (1-6): 2
Enter student id: 1004
Riley (id 1004) - 47

Choose an option (1-6): 5
Access denied. Only an Admin can do that.
```
