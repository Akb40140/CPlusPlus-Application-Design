# Module 14 - C++ & AI Agents

## Assignment
Choose one industry and design an AI agent for it. Explain the agent's goal, what
information it can access, what tools it can use, what actions it can take, and what a
human should approve before the agent acts.

# My agent: Student Success Agent (Education)

## Goal
Help a community college catch students who are starting to fall behind **early**, while
there's still time to help, and connect them with tutoring before they fail a class. It
builds on the AI Study Coach in my Student Record Manager, but instead of waiting for
someone to ask, it keeps watch every week.

## What information it can access
- Test and assignment scores for each class (like my `students.csv`, but for every class)
- Missing assignments and attendance
- The tutoring center's schedule and open appointment times
- Each student's preferred way to be contacted (email or text)

It **cannot** see medical records, financial aid, disciplinary records or anything
outside the student's classes. Less access means less that can go wrong with private
data.

## Tools it can use
| Tool | What it does |
|------|--------------|
| Grade reader | Reads scores and finds students under 60% or dropping fast (fast C++ code, like my one-pass stats) |
| Study tip writer | An AI model that writes a short, personal study plan (like my AI Study Coach) |
| Tutoring calendar | Looks up open tutoring times |
| Message drafter | Writes an email or text to the student |
| Report builder | Makes a weekly summary for each instructor |

## Actions it can take
**On its own:**
- Scan grades every week and make a list of students who might need help
- Write a draft study plan and a draft message for each one
- Look up open tutoring times and hold one for up to 24 hours
- Send the instructor a weekly report

**Only after a human approves:**
- Send any message to a student
- Book a tutoring appointment
- Flag a student to an academic counselor

## What a human should approve, and why
1. **Every message to a student.** The instructor reads it first. A message saying
   "you're failing" can scare or embarrass someone, and the instructor might know
   something the agent doesn't (the student was sick, or already talked to them).
2. **Booking appointments.** The student's time is theirs to decide, so the agent only
   suggests times.
3. **Anything that goes on a student's record or goes to a counselor.** These can affect
   a student's future, so a person has to make that decision and be responsible for it.

The agent should also never change a grade, and it should always say that its messages
were written with AI help.

## How the agent works
```
1. Receive goal         "Find students who need help this week"
2. Understand request   which classes, what counts as "falling behind"
3. Check data           read scores, missing work, attendance
4. Choose a tool        grade reader -> study tip writer -> tutoring calendar
5. Execute              make the list, draft plans and messages, hold times
6. Check result         are the drafts short, kind and correct? (like isValidResponse())
7. Ask a human          send everything to the instructor to approve or edit
```

## Where C++ fits
Reading grades for thousands of students every week and working out who's dropping is
the kind of fast data processing C++ is good at. That part could be built from what I did
in my app: sorted records, binary search and one-pass statistics. The AI model would
handle the writing, and C++ would handle the numbers.
