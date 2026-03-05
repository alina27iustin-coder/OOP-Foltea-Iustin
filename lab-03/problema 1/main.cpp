#include <iostream>
#include "Math.h"
using namespace std;
int main()
{
    cout<<Math::Add(2, 3)<<'\n';
    cout<<Math::Add(2, 3, 4)<<'\n';
    cout<<Math::Add(2.5, 3.8)<<'\n';
    cout<<Math::Add(1.1, 2.2, 3.3)<<'\n';
    cout<<Math::Mul(6, 7)<<'\n';
    cout<<Math::Mul(2, 3, 4)<<'\n';
    cout<<Math::Mul(2.5, 4.0)<<'\n';
    cout<<Math::Mul(1.5, 2.0, 3.0)<<'\n';
    cout<<Math::Add(5, 10, 20, 30, 40, 50)<<'\n';
    char* s=Math::Add("Hello, ", "world!");
    if(s)
    {
        cout<<s<<'\n';
        delete[] s;
    }
    else
        cout<<"nullptr\n";
    return 0;
}