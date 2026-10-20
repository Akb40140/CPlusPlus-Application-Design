# Module 6 - Creating Classes & Objects

## Assignment
Create a class that represents something in your application. Your class must contain
private data members, a constructor, at least two member functions, and at least one
getter or setter. Create at least two objects from your class and display their
information.

## What I did
- I made a `Student` class. The class is defined in `Student.h` and the code for its
  member functions is in `Student.cpp`. Its data members `name`, `id` and `score`
  are private, so they can only be changed through the class's functions.
- It has a constructor that sets all three values when a student is created.
- Member functions: `displayStudent()` prints the student and `isPassing()` checks if
  the score is 60 or higher.
- Getters `getName()`, `getId()` and `getScore()`, and a setter `setScore()` that only accepts
  scores from 0 to 100.
- `showClassDemo()` creates two objects, `student1` and `student2`, displays them, and
  uses the setter and getters on `student2`.
- Every line of `students.csv` also becomes a Student object, so the program starts with 8
  objects, and you can add more from the menu.

## Program flow
```
main()
 ├── loadStudents()   reads students.csv and creates Student objects
 ├── showWelcome()
 ├── showClassDemo()  creates student1 and student2 and displays them
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
- `Student.h` - the Student class definition
- `Student.cpp` - the Student class's member functions
- `students.csv` - the data

## How to run
```
g++ -o records main.cpp Student.cpp
./records
```

## Sample output
```
Welcome to the Student Record Manager!

--- Two Student objects ---
Alex (id 2001) - 85
Jamie (id 2002) - 55
Jamie's new score: 65
Jamie is now passing.

Loaded 8 students from students.csv.

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
