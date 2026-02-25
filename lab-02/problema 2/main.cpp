#include <iostream>
#include "Student.h"
#include "StudentCompare.h"
int main()
{
    Student s1, s2;

    s1.SetName("Ana");
    s1.SetMath(9.5f);
    s1.SetEnglish(8.0f);
    s1.SetHistory(10.0f);

    s2.SetName("Mihai");
    s2.SetMath(7.0f);
    s2.SetEnglish(9.0f);
    s2.SetHistory(9.0f);

    std::cout<<s1.GetName()<<" avg = "<<s1.Average()<<"\n";
    std::cout<<s2.GetName()<< " avg = "<<s2.Average()<<"\n";

    std::cout<<"CompareName: "<<CompareName(s1, s2)<<"\n";
    std::cout<<"CompareAverage: "<<CompareAverage(s1, s2)<<"\n";
}