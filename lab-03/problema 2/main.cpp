#include <iostream>
#include "Canvas.h"
int main()
{
    Canvas c(40, 15);
    c.Clear();
    c.SetPoint(2, 2, 'X');

    c.DrawRect(1, 1, 15, 6, '#');
    c.FillRect(18, 1, 35, 6, '+');

    c.DrawCircle(10, 11, 3, 'o');
    c.FillCircle(28, 11, 3, '@');

    c.DrawLine(0, 14, 39, 0, '*');

    c.Print();
    return 0;
}