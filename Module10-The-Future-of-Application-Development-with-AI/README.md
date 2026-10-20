# Module 10 - The Future of Application Development with AI

## Assignment
Imagine your application five years from now. Identify three tasks AI could help automate
and two tasks where human developers should remain responsible. Create a short "Future of
My Application" plan and explain why.

# Future of My Application: Student Record Manager

## Where it is now
Right now my Student Record Manager is a C++ command-line program. It loads students from
a CSV file, has Admin and Regular User roles, finds students with binary search, checks
every input, and has a mock AI Study Coach.

## Five years from now
I picture it as a tool a school could actually use. It would keep records for thousands
of students in a real database instead of a CSV file, track several subjects over time,
and have a real AI Study Coach that gives each student tips based on their history.
Teachers would use it through a simple web or phone app, and the fast C++ code would
still run in the background.

## Three tasks AI could help automate
1. **Writing tests.** Every time I add a feature, AI could write test cases for it,
   including bad inputs like empty names, negative scores and duplicate ids. My
   validation in Module 8 took a lot of trying things by hand, and AI could do that
   part faster.
2. **Personal study tips.** The AI Study Coach from Module 9 would use a real AI model
   instead of my four simple rules. It could look at a student's scores over the whole
   year and spot patterns, like always doing worse on one topic.
3. **Reports and documentation.** AI could write a summary for each class ("3 students
   are below 60, here's who improved") and keep the README and help screens up to date
   when the code changes.

## Two tasks humans should stay responsible for
1. **Security and privacy of student data.** Student grades are private. A person has
   to decide who can see what, how the Admin login works, and what data is allowed to go
   to an AI service. If this goes wrong it hurts real students, so a human needs to own
   it and answer for it.
2. **Final decisions about students.** AI can suggest that a student needs tutoring, but
   a teacher should decide. AI can be wrong or unfair, and it doesn't know things a
   teacher knows, like a student being sick during a test. The app should show the AI's
   suggestion, and a person makes the call.

## Why
AI is good at fast, repetitive work: writing tests, drafting tips and summarizing data.
It can also make mistakes that look confident, which is why my Module 9 code checks the
AI's answer with `isValidResponse()` before showing it. The parts that involve trust,
fairness and people's private information should stay with humans. My job as the
developer is to design the app, check what AI produces, and keep the data safe.

## My plan
| When | Step |
|------|------|
| Next | Save changes back to the file so data isn't lost when the program closes |
| Soon | Replace the mock AI Study Coach with a real AI service, still validating every answer |
| Later | Move from a CSV file to a database, and add more subjects and test dates |
| Always | A human reviews security, privacy and any AI suggestion that affects a student |
