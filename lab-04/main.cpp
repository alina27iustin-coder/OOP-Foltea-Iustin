#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
    Sort s1(10, 1, 100);//constructor cu random values
    cout << "s1 initial random: ";
    s1.Print();
    s1.InsertSort(true);
    cout << "s1 after InsertSort ascending: ";
    s1.Print();
    cout<<'\n';
    Sort s2({10, 40, 100, 5, 70});//constructor cu initialization list
    cout << "s2 initial: ";
    s2.Print();
    cout<<'\n';
    s2.BubbleSort();
    cout << "s2 after BubbleSort descending (default): ";
    s2.Print();
    cout<<'\n';
    int v[] = {8, 3, 9, 1, 4, 7};
    Sort s3(v, 6);
    cout<<"s3 initial (from array): ";
    s3.Print();
    s3.QuickSort(true);
    cout << "s3 after QuickSort ascending: ";
    s3.Print();
    cout<<'\n';
    Sort s4(5, 15, 2, 99, 34, 7);//constructor cu variadic parameters
    cout<<"s4 initial (variadic): ";
    s4.Print();
    s4.BubbleSort(true);
    cout<<"s4 after BubbleSort ascending: ";
    s4.Print();
    cout<<'\n';
    Sort s5("10,40,100,5,70");//constructor din string
    cout << "s5 initial (din string): ";
    s5.Print();
    s5.InsertSort();
    cout << "s5 after InsertSort descending (default): ";
    s5.Print();
    cout<<'\n';
    cout<<"s5 count = "<<s5.GetElementsCount()<<'\n';//GetElementsCount
    cout<<"s5 element la index 2 = "<< s5.GetElementFromIndex(2)<<'\n'; //GetElementFromIndex
    return 0;
}