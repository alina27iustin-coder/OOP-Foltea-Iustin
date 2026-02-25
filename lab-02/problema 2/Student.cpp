#include "Student.h"
Student::Student() {//constructor
    name="";
    math=1;
    english=1;
    history=1;
}
bool Student::SetName(const std::string& newName) {
    if (newName.empty()) return false;
    name=newName;
    return true;
}
const std::string& Student::GetName() const {
    return name;
}
bool Student::SetMath(float grade) {
    if (grade<1 || grade>10) return false;
    math=grade;
    return true;
}

float Student::GetMath() const {
    return math;
}
bool Student::SetEnglish(float grade) {
    if (grade<1 || grade>10) return false;
    english = grade;
    return true;
}
float Student::GetEnglish() const {
    return english;
}
bool Student::SetHistory(float grade) {
    if (grade<1 || grade>10) return false;
    history=grade;
    return true;
}
float Student::GetHistory() const {
    return history;
}
float Student::Average() const {
    return (math+english+history) / 3;
}