// RecordTools.h - declarations for the record functions
#ifndef RECORDTOOLS_H
#define RECORDTOOLS_H

#include <string>
using namespace std;

const int MAX_RECORDS = 10;

void showMessage();
int loadRecords(string fileName, string names[], int ids[], double scores[]);
void addRecord(string names[], int ids[], double scores[], int* count);
void displayRecords(string names[], int ids[], double scores[], int count);
double calculateAverage(double scores[], int count);

#endif
