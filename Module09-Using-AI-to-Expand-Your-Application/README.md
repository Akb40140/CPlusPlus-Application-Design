# Module 9 - Using AI to Expand Your Application

## Assignment
Choose one AI-powered feature for your application. Describe what the feature does, what
data it would need, what the user would see, and where AI would fit into your current
application architecture. Build a mock version or prototype if a live AI service is not
available.

## My AI feature: AI Study Coach
**What it does:** You pick a student, and the coach gives that student one short,
personal study tip based on their math score.

**What data it needs:** The student's name and math score, plus the class average so the
tip can compare them to the class. In the future it could also use scores from other
subjects or older tests to spot trends.

**What the user sees:** A new menu option, `6. AI Study Coach`. You enter a student id,
and the program shows the prompt it sent and the tip it got back.

**Where AI fits in my app:**
```
Menu option 6
   |
   +--> User request       enter a student id, found with binary search
   +--> Prepare data       buildPrompt() turns the student into a text prompt
   +--> AI service         mockAIService()  <-- a real AI API would go here
   +--> Receive result     the tip comes back as a string
   +--> Validate result    isValidResponse() checks it isn't empty or too long
   +--> Display to user    runStudyCoach() prints the tip
```
The AI is just one more part of the program. Everything else (menu, roles, validation,
binary search) stays the same.

## The mock version
I don't have a live AI service, so `mockAIService()` uses simple rules instead. It picks
a tip based on whether the score is under 50, 50-69, 70-84, or 85+. Because the rest of
the code only calls `mockAIService(prompt, score)`, I could swap in a real AI call later
without changing the menu or the other functions.

Checking the answer with `isValidResponse()` matters because a real AI could send back
an empty or very long answer, and the app shouldn't show that without checking.

## Files
- `main.cpp` - menu, login, binary search, record functions, new option 6
- `AICoach.h` / `AICoach.cpp` - the AI Study Coach
- `Validation.h` / `Validation.cpp` - input validation from Module 8
- `Student.h`, `User.h` - classes
- `students.csv` - the data

## How to run
```
g++ -o records main.cpp Validation.cpp AICoach.cpp
./records
```

## Sample output
```
Choose an option (1-7): 6
Enter student id (1000-9999): 1004

--- AI Study Coach (mock) ---
Prompt sent: Give one short study tip for a student named Riley who scored 47 in math. The class average is 69.
Tip for Riley: Start with the basics: review one topic a day and redo the practice problems you missed. Ask for tutoring this week.
```
