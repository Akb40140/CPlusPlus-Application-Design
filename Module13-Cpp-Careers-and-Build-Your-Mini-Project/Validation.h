// Validation.h - functions that keep asking until the input is valid
#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
using namespace std;

string readName(string prompt);
int readInt(string prompt, int min, int max);
double readDouble(string prompt, double min, double max);

#endif
