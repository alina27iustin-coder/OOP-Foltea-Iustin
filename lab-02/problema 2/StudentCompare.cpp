#include "StudentCompare.h"
static int CompareFloat(float x, float y) {
    if (x == y) return 0;
    return (x > y) ? 1 : -1;
}
int CompareName(const Student& a, const Student& b) {
    if (a.GetName()==b.GetName()) return 0;
    return (a.GetName()>b.GetName()) ? 1 : -1;
}
int CompareMath(const Student& a, const Student& b) {
    return CompareFloat(a.GetMath(), b.GetMath());
}
int CompareEnglish(const Student& a, const Student& b) {
    return CompareFloat(a.GetEnglish(), b.GetEnglish());
}
int CompareHistory(const Student& a, const Student& b) {
    return CompareFloat(a.GetHistory(), b.GetHistory());
}
int CompareAverage(const Student& a, const Student& b) {
    return CompareFloat(a.Average(), b.Average());
}