#include <stdio.h>
long long my_atoll(const char *s) 
{
    long long val=0;
    int sign=1;
    while (*s == ' ' || *s == '\t') s++;
    if (*s == '-') { sign = -1; s++; }
    else if (*s == '+') { s++; }
    while (*s >= '0' && *s <= '9') {
        val=val*10+(*s-'0');
        s++;
    }
    return sign*val;
}
