# Module 15 - C++ Resources & Keep Building

## Assignment
Create your personal C++ learning plan. Choose three resources, one project you want to
build next, and one C++ topic you still need to master. Add the plan to your GitHub
repository.

# My C++ Learning Plan

## Three resources
1. **cppreference.com** (official-style documentation)
   I'll use it to look up exactly how things like `getline`, `ifstream` and `vector`
   work. When I got stuck on `cin` failing in Module 2, the answer was in how `cin.clear()`
   and `cin.ignore()` work, and this site explains that kind of thing.
2. **learncpp.com** (free tutorial site)
   It goes through C++ step by step, in order. I want to use its chapters on `vector`,
   references and pointers to fill in gaps from this class.
3. **LeetCode or HackerRank** (practice problems)
   Short problems I can do a few times a week in C++ to get faster, especially searching
   and sorting like the binary search I wrote in Module 7.

## Next project: Study Group Finder
A C++ app where students add the classes they're taking and the times they're free, and
the app matches people in the same class who are free at the same time. It would reuse a
lot of what I learned:
- Classes for `Student` and `Course`
- Saving and loading from a file, like Module 13
- Input validation for times and class names, like Module 8
- Searching and sorting to find matches quickly

New things I'd have to learn for it: `vector` instead of fixed-size arrays, and
maybe `map` to group students by class.

## Topic I still need to master: pointers and memory
I used pointers in Module 4 (`int* count`) and `new` / `delete[]` in Module 12, but I
still have to think hard about when to use `*` and `&`, and I don't really know what
happens if I forget `delete`. Over the next two months I want to:
- Do the learncpp.com chapters on pointers, references and dynamic memory
- Rewrite part of my Student Record Manager with `vector` and references, and compare
- Learn what smart pointers (`unique_ptr`) are and why they're safer

## Schedule
| When | Goal |
|------|------|
| Weeks 1-4 | learncpp.com pointers and memory chapters, 2 LeetCode easy problems a week |
| Weeks 5-8 | Start the Study Group Finder with classes and file saving |
| Weeks 9-12 | Add search and matching, put it on GitHub with a README like this class |

**How I'll keep building:** build something, break it, debug it, improve it, and put it
on GitHub.
