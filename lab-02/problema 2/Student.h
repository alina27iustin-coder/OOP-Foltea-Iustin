#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student
{
private:
    std::string name;
    float math;
    float english;
    float history;
public:
    Student();//construct
    bool SetName(const std::string& newName);
    const std::string& GetName() const;

    bool SetMath(float grade);
    float GetMath() const;

    bool SetEnglish(float grade);
    float GetEnglish() const;

    bool SetHistory(float grade);
    float GetHistory() const;

    float Average() const;
};
#endif