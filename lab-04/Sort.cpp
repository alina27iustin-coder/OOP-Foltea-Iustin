#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
using namespace std;
Sort::Sort(int count, int min, int max)//constructor random
{
    this->count=count;
    elements=new int[count];
    srand((unsigned)time(0));
    for (int i=0; i<count; i++)
        elements[i]=min+rand()%(max-min+1);
}
Sort::Sort(initializer_list<int> list)
{
    count=list.size();
    elements=new int[count];
    const int* p=list.begin();
    for (int i=0; i<count; i++)
        elements[i] = p[i];
}
Sort::Sort(int count, ...)//constructor varadic
{
    this->count=count;
    elements=new int[count];
    va_list args;
    va_start(args, count);
    for (int i=0; i<count; i++)
        elements[i]=va_arg(args, int);
    va_end(args);
}
Sort::Sort(const char* values)//constructor din string
{
    count=1;//nr elem
    for (int i=0; values[i]!='\0'; i++)
        if (values[i]==',')
            count++;
    elements=new int[count];
    int index=0;
    int number=0;
    for (int i=0;; i++)
    {
        if(values[i]>='0' && values[i]<='9')
            number=number*10+(values[i]-'0');
        else if(values[i]==',' || values[i]=='\0')
        {
            elements[index]=number;
            index++;
            number=0;
            if(values[i]=='\0')
                break;
        }
    }
}
int Sort::Partition(int left, int right, bool ascendent)
{
    int pivot=elements[right];
    int i=left-1;
    for(int j=left; j<right; j++)
    {
        if(ascendent)
        {
            if(elements[j]<pivot)
            {
                i++;
                swap(elements[i],elements[j]);
            }
            else
                if (elements[j]>pivot)
                {
                    i++;
                    swap(elements[i],elements[j]);
                }
        }
    }
    int aux=elements[i+1];
    elements[i+1]=elements[right];
    elements[right]=aux;
    return i+1;
}
void Sort::QuickSortHelper(int left, int right, bool ascendent)
{
    if(left<right)
    {
        int pivotIndex=Partition(left, right, ascendent);
        QuickSortHelper(left, pivotIndex-1, ascendent);
        QuickSortHelper(pivotIndex+1, right, ascendent);
    }
}
void Sort::QuickSort(bool ascendent)
{
    QuickSortHelper(0, count-1, ascendent);
}
// constructor dintr-un vector/array existent
Sort::Sort(int* v, int count)
{
    this->count=count;
    elements=new int[count];
    for(int i=0; i<count; i++)
        elements[i]=v[i];
}
void Sort::BubbleSort(bool ascendent)
{
    for (int i=0; i<count-1; i++)
        for (int j=0; j<count-i-1; j++)
            if (ascendent)
                if (elements[j]>elements[j+1])
                {
                    int aux=elements[j];
                    elements[j]=elements[j+1];
                    elements[j+1]=aux;
                }
            else
                if(elements[j]<elements[j+1])
                {
                    int aux=elements[j];
                    elements[j]=elements[j + 1];
                    elements[j+1]=aux;
                }
}
void Sort::InsertSort(bool ascendent)
{
    for (int i=1; i<count; i++)
    {
        int key=elements[i];
        int j=i-1;
        if (ascendent)
            while (j>=0 && elements[j]>key) {
                elements[j+1]=elements[j];
                j--;
            }
        else
            while (j >= 0 && elements[j]<key)
            {
                elements[j+1]=elements[j];
                j--;
            }
        elements[j+1]=key;
    }
}
void Sort::Print()
{
    for (int i=0; i<count; i++)
        cout<<elements[i]<<' ';
    cout<<'\n';
}
int Sort::GetElementsCount()
{
    return count;
}
int Sort::GetElementFromIndex(int i)
{
    return elements[i];
}
Sort::~Sort()
{
    delete[] elements;
}


