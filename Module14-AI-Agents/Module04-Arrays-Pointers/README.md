# Module 4 — Datasets, Arrays & Pointers

## Assignment
Choose a small Kaggle dataset. Select 5–10 records and at least 2–3 fields. Represent the
data in C++ arrays. Display the records and demonstrate accessing one value through a
pointer.

## Dataset
**Students Performance in Exams** (Kaggle, uploaded by *spscientist*)
<https://www.kaggle.com/datasets/spscientist/students-performance-in-exams>

The original CSV has 1000 anonymous rows and 8 columns. For this module it was cut down to
**8 records** and **3 fields**. The rows are anonymous in the source file, so a placeholder
name was assigned to each one — the app searches by name, so every record needs one.

| Field       | C++ type | Array     | Notes                            |
|-------------|----------|-----------|----------------------------------|
| Student name| `string` | `names`   | Placeholder; source is anonymous |
| Student id  | `int`    | `ids`     | Sequential id for each row       |
| Math score  | `double` | `grades`  | `math score` column, 0–100       |

## How this is met
- **5–10 records:** 8 records are loaded at startup by `loadDataset()`. `MAX_RECORDS` is 10,
  so two slots stay free for records added from the menu.
- **2–3 fields:** three parallel arrays (`names`, `ids`, `grades`). Position `i` in each
  array is the same student: `names[2]`, `ids[2]` and `grades[2]` are all record 3.
- **Displayed:** `viewRecords()` prints the table, and it runs automatically at startup.
- **One value through a pointer:** option 7, `pointerDemo()`, sets
  `const double* scorePtr = &gradeList[0];` and reads the score with `*scorePtr`. It then
  does `scorePtr + 1` and prints both addresses, which shows the address moving by
  `sizeof(double)` (8 bytes) — one array element.

## Pointers used elsewhere
Every function takes the arrays as pointers rather than copies:
- `*(nameList + *count)` is pointer arithmetic, the same slot as `nameList[*count]`.
- `int* count` lets `addRecord()`, `deleteRecord()` and `loadDataset()` change the real
  `recordCount` in `main` by writing through the pointer: `(*count)++`.
- `findRecord()` **returns a pointer** to the matching slot, or `nullptr` when there is no
  match. Returning an address lets the caller edit the record it found.
- `found - nameList` is pointer subtraction; the difference is the slot number, which is
  how search, update and delete know which index they landed on.

## Build and run
```
g++ -std=c++17 -Wall -Wextra -o records main.cpp
./records
```

## Sample run
```
Loaded 8 records from the Kaggle dataset excerpt.

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
