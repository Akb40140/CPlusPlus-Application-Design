# Module 4 - Datasets, Arrays & Pointers

## Assignment
Choose a small Kaggle dataset. Select 5-10 records and at least 2-3 fields. Represent
the data in C++ arrays. Display the records and demonstrate accessing one value through
a pointer.

## Dataset
I used "Students Performance in Exams" from Kaggle:
https://www.kaggle.com/datasets/spscientist/students-performance-in-exams

It has 1000 rows, so I took the first 8 and saved them in `students.csv` with 3 fields:
name, student id and math score. The dataset doesn't have names, so I made them up.

## What I did
- `loadRecords()` reads `students.csv` with `ifstream` and puts each field in its own
  array: `names`, `ids` and `scores`. The same index is the same student in all three.
- Option 1 displays all 8 records.
- Option 2 searches for a student by name.
- Option 3 is the pointer demo. `double* scorePtr = &scores[0];` points to the first
  score, and `*scorePtr` reads the value through the pointer. It also prints the address.

## How to run
`students.csv` has to be in the same folder.
```
g++ -o records main.cpp
./records
```

## Sample output
```
Loaded 8 records from students.csv.

=== STUDENT RECORD MANAGER ===
1. Display Records
2. Search
3. Pointer Demo
4. Exit
Choose an option (1-4): 1
Ada (id 1001) - 72
Sam (id 1002) - 69
Jordan (id 1003) - 90
Riley (id 1004) - 47
Casey (id 1005) - 76
Morgan (id 1006) - 71
Avery (id 1007) - 88
Quinn (id 1008) - 40

Choose an option (1-4): 3
First student: Ada
Score through pointer: 72
Address in memory: 0x16fdfe8f0
```
