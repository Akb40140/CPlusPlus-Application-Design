// AICoach.cpp - the AI Study Coach feature
//
// Flow (from the module's architecture):
//   User request -> Prepare data -> AI service -> Receive result
//   -> Validate result -> Display to user
//
// There is no live AI service yet, so mockAIService() stands in for it with
// simple rules. Later it could be replaced with a real AI API call and the
// rest of the code would stay the same.
#include <iostream>
#include "AICoach.h"
using namespace std;

// Step 1: prepare the data the AI needs as a text prompt.
string buildPrompt(Student student, double classAverage) {
    return "Give one short study tip for a student named " + student.getName() +
           " who scored " + to_string((int)student.getScore()) +
           " in math. The class average is " + to_string((int)classAverage) + ".";
}

// Step 2: the "AI". A real version would send the prompt to an AI service.
// This mock looks at the score and picks a tip.
string mockAIService(string prompt, double score) {
    if (prompt == "") {
        return "";
    }

    if (score < 50) {
        return "Start with the basics: review one topic a day and redo the practice "
               "problems you missed. Ask for tutoring this week.";
    } else if (score < 70) {
        return "You're close. Focus on the problem types you get wrong most and "
               "do 20 minutes of practice each day.";
    } else if (score < 85) {
        return "Good work. Try harder practice problems and explain your steps out "
               "loud to lock them in.";
    } else {
        return "Great score! Keep it up by helping a classmate - teaching is a "
               "strong way to review.";
    }
}

// Step 3: never trust the AI blindly. Check the answer before showing it.
bool isValidResponse(string response) {
    return response != "" && response.length() < 300;
}

// Runs the whole flow for one student.
void runStudyCoach(Student student, double classAverage) {
    string prompt = buildPrompt(student, classAverage);
    string response = mockAIService(prompt, student.getScore());

    cout << "\n--- AI Study Coach (mock) ---" << endl;
    cout << "Prompt sent: " << prompt << endl;

    if (isValidResponse(response)) {
        cout << "Tip for " << student.getName() << ": " << response << endl;
    } else {
        cout << "The coach could not give a tip right now." << endl;
    }
}
