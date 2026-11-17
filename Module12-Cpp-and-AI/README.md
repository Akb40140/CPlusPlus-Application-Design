# Module 12 - C++ & AI

## Assignment
Research one AI system or product that uses C++. Identify what C++ contributes to the
system. Then add a performance-focused feature to your application or explain where C++
would be valuable if your application became much larger.

## Research: PyTorch
PyTorch is one of the most popular tools for building and training AI models. Meta
created it, and it's now run by the PyTorch Foundation. Most people write PyTorch code in
Python, but the heavy work underneath is done in C++.

**What C++ contributes:**
- **Speed.** Tensors (the big grids of numbers AI models use) and the math on them are
  handled by a C++ library called ATen. Python only gives the instructions, and C++ does
  millions of calculations fast.
- **Training.** The autograd engine, which works out how to adjust the model while it
  learns, is written in C++.
- **GPUs.** The code that runs on NVIDIA graphics cards is written in CUDA, which is
  based on C++. That's what makes training big models possible.
- **Running models without Python.** LibTorch is PyTorch's C++ version. Companies use it
  to put trained models inside apps, games, robots and devices where Python would be too
  slow or too big.

So PyTorch uses both languages: Python is easy for trying ideas, and C++ is fast for
the part that does the real work. This matches what the module said about C++ being the
performance layer under AI tools.

## My performance feature
I added two options to my Student Record Manager (in `Stats.h` / `Stats.cpp`):

**7. Class Statistics** works out the average, highest score, lowest score and number of
passing students in **one loop**. Doing each one separately would loop through every
student four times. With 8 students it doesn't matter, but with a whole school it would.

**8. Search Speed Test** shows why I used binary search in Module 7. It makes 1,000,000
sorted student ids with `new int[]` (too big for a normal array) and counts how many
checks each search needs to find the last student:

```
--- Search Speed Test (1,000,000 students) ---
Linear search checks: 1000000
Binary search checks: 20
```
Binary search needs 20 checks where linear search needs a million. It frees the memory
with `delete[]` when it's done.

## Where C++ would help if my app got much bigger
If my app held records for a whole school district, C++ would matter for:
- Searching and sorting hundreds of thousands of students quickly
- Working out statistics for every class at once
- Controlling memory so the app doesn't slow down or waste RAM
- Running the AI Study Coach's data preparation fast before sending it to an AI service

## Files
- `main.cpp` - menu with new options 7 and 8
- `Stats.h` / `Stats.cpp` - class statistics and the search speed test
- `AICoach.h` / `AICoach.cpp`, `Validation.h` / `Validation.cpp` - from earlier modules
- `Student.h`, `User.h` - classes
- `students.csv` - the data

## How to run
```
g++ -o records main.cpp Validation.cpp AICoach.cpp Stats.cpp
./records
```

## Sample output
```
Choose an option (1-9): 7

--- Class Statistics ---
Students: 8
Average score: 69.125
Highest: Jordan (90)
Lowest: Quinn (40)
Passing: 6 of 8
```
