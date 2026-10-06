# Module 6 - Creating Classes & Objects

## Assignment
Create a class that represents something in your application. Your class must contain
private data members, a constructor, at least two member functions, and at least one
getter or setter. Create at least two objects from your class and display their
information.

## What I did
- I made a `Student` class in `Student.h`. Its data members `name`, `id` and `score`
  are private, so they can only be changed through the class's functions.
- It has a constructor that sets all three values when a student is created.
- Member functions: `displayStudent()` prints the student and `isPassing()` checks if
  the score is 60 or higher.
- Getters `getName()` and `getScore()`, and a setter `setScore()` that only accepts
  scores from 0 to 100.
- Every line of `students.csv` becomes a Student object, so the program starts with 8
  objects, and you can add more from the menu.

## Program flow
```
main()
 ├── loadStudents()   reads students.csv and creates Student objects
 ├── showWelcome()
 └── menu loop: showMenu()
      ├── 1 addStudent()      creates a new object
      ├── 2 displayStudents() calls displayStudent() and isPassing()
      ├── 3 searchStudent()   uses getName()
      ├── 4 updateScore()     uses setScore() and getScore()
      └── 5 Exit
```
`main()` is where the program starts. It loads the data and then calls the other
functions from the menu.

## Files
- `main.cpp` - the menu and functions
- `Student.h` - the Student class
- `students.csv` - the data

## How to run
```
g++ -o records main.cpp
./records
```

## Sample output
```
Welcome to the Student Record Manager!
Loaded 8 students.

=== STUDENT RECORD MANAGER ===
1. Add Student
2. Display Students
3. Search
4. Update Score
5. Exit
Choose an option (1-5): 2
Ada (id 1001) - 72
   Passing
Sam (id 1002) - 69
   Passing
...
Quinn (id 1008) - 40
   Not passing
```
