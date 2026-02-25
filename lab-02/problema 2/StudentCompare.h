#ifndef StudentCompare
#define StudentCompare
#include "Student.h";
using namespace std;
int CompareName(const Student& a, const Student& b);
int CompareMath(const Student& a, const Student& b);
int CompareEnglish(const Student& a, const Student& b);
int CompareHistory(const Student& a, const Student& b);
int CompareAverage(const Student& a, const Student& b);
#endif