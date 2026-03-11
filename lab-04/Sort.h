#pragma once
#include <initializer_list>
class Sort
{
        private:
            int* elements;//pointer catre primul element al unui vector
            int count;//nr de elem din lista

            int Partition(int left, int right, bool ascendent);//pozitia finala a pivotului dupa partitionare
            void QuickSortHelper(int left, int right, bool ascendent);//sortam [left,right]
        public:
            Sort(int count, int min, int max);//random
            Sort(std::initializer_list<int> list);
            Sort(int* v, int count);//array dat deja
            Sort(int count, ...);//varadic
            Sort(const char* values);

            void InsertSort(bool ascendent=false);//false=descresc
            void QuickSort(bool ascendent=false);//porneste uicksortHelper pe tot tabloul
            void BubbleSort(bool ascendent=false);
            void Print();
            int GetElementsCount();//nr de elem
            int GetElementFromIndex(int index);//elem de pe poz index
            ~Sort();
};