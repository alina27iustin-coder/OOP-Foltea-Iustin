#include <iostream>
#include "Tree.h"
using namespace std;
bool egal(const int& a, const int& b){
    return a==b;
}
bool crescator(const int& a, const int& b){
    return a<b;
}
int main()
{
    Tree<int> arb;
    TreeNode<int>* rad=arb.add_nod(nullptr, 10);
    TreeNode<int>* n1=arb.add_nod(rad, 7);
    TreeNode<int>* n2=arb.add_nod(rad, 20);
    TreeNode<int>* n3=arb.insert(rad, 1, 4);
    arb.add_nod(n1, 8);
    arb.add_nod(n1, 9);
    cout<<"Radacina: " <<arb.get_rad()->value<<'\n';
    cout<<"Copil poz 0: "<<arb.get_nod(rad, 0)->value<<'\n';
    cout<<"Copil poz 1: "<<arb.get_nod(rad, 1)->value<<'\n';
    cout<<"Copil poz 2: "<<arb.get_nod(rad, 2)->value<<'\n';
    cout<<"Numar descendenti ai rad: "<<arb.count(rad)<<'\n';
    TreeNode<int>* gasit=arb.find(9, egal);
    if(gasit!=nullptr)
        cout<<"Valoarea 9 a fost gasita.\n";
    else
        cout<<"Valoarea 9 nu a fost gasita.\n";
    arb.sort(rad, crescator);
    cout<<"Copiii radacinii dupa sortare: ";
    for(int i=0; i< rad->nr_copii; i++)
        cout<<rad->copii[i]->value<<' ';
    cout<<'\n';
    arb.delete_node(n2);
    cout<<"Dupa stergerea lui 20, copiii radacinii sunt: ";
    for(int i=0; i<rad->nr_copii; i++)
        cout<<rad->copii[i]->value<<' ';
    cout<<'\n';
    (void)n3;
    return 0;
}
