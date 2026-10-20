// AICoach.h - the AI Study Coach feature (mock version)
#ifndef AICOACH_H
#define AICOACH_H

#include <string>
#include "Student.h"
using namespace std;

string buildPrompt(Student student, double classAverage);
string mockAIService(string prompt, double score);
bool isValidResponse(string response);
void runStudyCoach(Student student, double classAverage);

#endif
