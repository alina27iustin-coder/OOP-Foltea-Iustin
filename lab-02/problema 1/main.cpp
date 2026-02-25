#include <iostream>
#include "NumberList.h"

int main() {
    NumberList numbers;
    numbers.Init();
    numbers.Add(10);
    numbers.Add(50);
    numbers.Add(40);
    numbers.Add(60);
    numbers.Add(20);
    numbers.Add(30);
    numbers.Print();
    numbers.Sort();
    numbers.Print();
}