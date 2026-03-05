#include "Math.h"
#include <cstring>
#include <cstdarg>
int Math::Add(int a, int b)
{
    return a+b;
}
int Math::Add(int a, int b, int c)
{
    return a+b+c;
}
int Math::Add(double a, double b)
{
    return a+b;
}
int Math::Add(double a, double b, double c)
{
    return a+b+c;
}
int Math::Mul(int a, int b)
{
    return a*b;
}
int Math::Mul(int a, int b, int c)
{
    return a*b*c;
}
int Math::Mul(double a, double b)
{
    return a*b;
}
int Math::Mul(double a, double b, double c)
{
    return a*b*c;
}
int Math::Add(int count, ...)
{
    int sum=0;
    va_list numar;
    va_start(numar, count);
    for (int i=0; i<count; i++)
        sum+=va_arg(numar, int);
    va_end(numar);
    return sum;
}
char* Math::Add(const char* s1, const char* s2)
{
    if (s1==nullptr || s2==nullptr)
        return nullptr;
    char* r=new char[(int)strlen(s1)+(int)strlen(s2)+1];
    strcpy(r,s1);
    strcat(r,s2);
    return r;
}