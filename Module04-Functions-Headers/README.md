# Module 4 — Datasets, Arrays & Pointers

## Assignment
Choose a small Kaggle dataset. Select 5–10 records and at least 2–3 fields. Represent the
data in C++ arrays. Display the records and demonstrate accessing one value through a
pointer.

Download the .csv or .txt file, upload it to GitHub (no more than 10 records), and use
`fstream` in the C++ file to import it.

## Dataset
**Students Performance in Exams** (Kaggle, uploaded by *spscientist*)
<https://www.kaggle.com/datasets/spscientist/students-performance-in-exams>

The original CSV has 1000 anonymous rows and 8 columns. For this module it was cut down to
**8 records** and **3 fields**, saved as **`students.csv`** in this folder. The rows are
anonymous in the source file, so a placeholder name was assigned to each one — the app
searches by name, so every record needs one.

```
name,student_id,math_score
Ada,1001,72
Sam,1002,69
...
```

| Field       | C++ type | Array     | Notes                            |
|-------------|----------|-----------|----------------------------------|
| Student name| `string` | `names`   | Placeholder; source is anonymous |
| Student id  | `int`    | `ids`     | Sequential id for each row       |
| Math score  | `double` | `grades`  | `math score` column, 0–100       |

## How this is met
- **File uploaded:** `students.csv` sits in this folder, 8 records plus a header row.
- **Imported with fstream:** `loadDataset()` opens it with `ifstream file(fileName);` and
  reads each line field by field with `getline(file, name, ',')`, which stops at the next
  comma. The last field uses plain `getline()` to take the rest of the line. `stoi()` and
  `stod()` turn the id and score text into an `int` and a `double`. The stream is closed
  with `file.close()`. If the file is missing the program says so and starts empty instead
  of crashing.
- **5–10 records:** 8 records are loaded at startup. `MAX_RECORDS` is 10, so the read loop
  also stops early if the file ever holds more rows than the arrays can take.
- **2–3 fields:** three parallel arrays (`names`, `ids`, `grades`). Position `i` in each
  array is the same student: `names[2]`, `ids[2]` and `grades[2]` are all record 3.
- **Displayed:** `viewRecords()` prints the table, and it runs automatically at startup.
- **One value through a pointer:** option 7, `pointerDemo()`, sets
  `double* scorePtr = &gradeList[0];` and reads the score with `*scorePtr`. It then
  does `scorePtr + 1` and prints both addresses, which shows the address moving by
  8 bytes — the size of one `double`, which is one array element.

## Pointers used elsewhere
Every function takes the arrays as pointers rather than copies:
- `*(nameList + *count)` is pointer arithmetic, the same slot as `nameList[*count]`.
- `int* count` lets `addRecord()`, `deleteRecord()` and `loadDataset()` change the real
  `recordCount` in `main` by writing through the pointer: `(*count)++`.
- `findRecord()` **returns a pointer** to the matching slot, or `nullptr` when there is no
  match. Returning an address lets the caller edit the record it found.
- `found - nameList` is pointer subtraction; the difference is the slot number, which is
  how search, update and delete know which index they landed on.

## Files
| File | Purpose |
|------|---------|
| `main.cpp` | The program |
| `students.csv` | The dataset excerpt it reads |
| `.gitignore` | Keeps compiled binaries out of the repo |

## Build and run
`students.csv` must sit in the same folder you run the program from.

```
g++ -std=c++17 -Wall -Wextra -o records main.cpp
./records
```

## Sample run
```
Loaded 8 records from students.csv.

=== ALL RECORDS ===
#    NAME                  ID        MATH SCORE
1    Ada                   1001      72.00
2    Sam                   1002      69.00
3    Jordan                1003      90.00
4    Riley                 1004      47.00
5    Casey                 1005      76.00
6    Morgan                1006      71.00
7    Avery                 1007      88.00
8    Quinn                 1008      40.00

=== POINTER DEMO ===
scorePtr points at slot 1.
  *scorePtr (the value)  = 72.00
  scorePtr (the address) = 0x16b6fac10
After scorePtr + 1 it points at slot 2.
  *scorePtr (the value)  = 69.00
  scorePtr (the address) = 0x16b6fac18
The address moved by 8 bytes, the size of one double.
First name through a pointer: Ada
```
