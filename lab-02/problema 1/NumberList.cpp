#include "NumberList.h"
#include <iostream>
void NumberList::Init() {
    count=0;
}
bool NumberList::Add(int x)
{
    if (count>=10)
        return false;
    count++;
    numbers[count] = x;
}
void NumberList::Sort()
{
    for (int i=0; i<count-1; i++){
        int minim=i;
        for (int j=i+1; j<count; j++)
            if(numbers[j]<numbers[minim])
                minim=j;
        if (minim!=i)
        {
            int tmp=numbers[i];
            numbers[i]=numbers[minim];
            numbers[minim]=tmp;
        }
    }
}
void NumberList::Print() {
    for (int i=0; i<count; i++)
        std::cout<<numbers[i]<<" ";
    std::cout<<std::endl;
}