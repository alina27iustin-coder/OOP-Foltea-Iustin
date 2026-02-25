#ifndef UNTITLED1_NUMBERLIST_H
#define UNTITLED1_NUMBERLIST_H
class NumberList
{
    int numbers[10];
    int count;
public:
    void Init();
    bool Add(int x);
    void Sort();
    void Print();
};
#endif //UNTITLED1_NUMBERLIST_H
