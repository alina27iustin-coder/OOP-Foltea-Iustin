#pragma once
template <class T>
class TreeNode{
public:
    T value;
    TreeNode<T>* parent;
    TreeNode<T>** copii;
    int nr_copii;
    TreeNode(const T& val, TreeNode<T>* p=nullptr)
    {
        value=val;
        parent=p;
        copii=nullptr;
        nr_copii=0;
    }
    ~TreeNode(){
        delete[] copii;
    }
};
template <class T>
class Tree{
private:
    TreeNode<T>* rad;
    TreeNode<T>* find_rec(TreeNode<T>* node, const T& val, bool (*compare)(const T&, const T&)){
        //val=val pe care o caut; node->value=valoarea din nod
        if(node==nullptr)
            return nullptr;
        bool ok=false;
        if(compare)
            ok=compare(node->value, val);
        else ok=(node->value==val);
        if(ok)
            return node;
        for(int i=0;i<node->nr_copii;i++)
        {
            TreeNode<T>* gasit=find_rec(node->copii[i], val, compare);
            if(gasit) return gasit;
        }
        return nullptr;
    }
    int nr_rec(TreeNode<T>* nod){//nr de descendenti
        if(nod==nullptr)
            return 0;
        int total=0;
        for(int i=0; i<nod->nr_copii; i++)
            total+=1+nr_rec(nod->copii[i]);
        return total;
    }
    void sterge_subTree(TreeNode<T>* nod){
        if(nod==nullptr)
            return;
        for(int i=0; i<nod->nr_copii; i++)
            sterge_subTree(nod->copii[i]);
        delete nod;
    }
public:
    Tree() { rad=nullptr; }
    ~Tree() { sterge_subTree(rad); }

    TreeNode<T>* get_rad(){
        return rad;
    }
    TreeNode<T>* add_nod(TreeNode<T>* parent, const T& value)//adauga nod la final copii
    {
        if(parent==nullptr)
        {
            if(rad!=nullptr)
                return nullptr;
            rad=new TreeNode<T>(value, nullptr);
            return rad;
        }
        TreeNode<T>* nou=new TreeNode<T>(value, parent);
        TreeNode<T>** v_nou=new TreeNode<T>*[parent->nr_copii+1];
        for (int i=0; i<parent->nr_copii; i++)
            v_nou[i]=parent->copii[i];
        v_nou[parent->nr_copii]=nou;
        delete[] parent->copii;
        parent->copii=v_nou;
        parent->nr_copii++;
        return nou;
    }
    TreeNode<T>* get_nod(TreeNode<T>* parent, int x)
    {
        if(parent==nullptr)
            return rad;
        if(x<0 || x>=parent->nr_copii)
            return nullptr;
        return parent->copii[x];
    }
    void delete_node(TreeNode<T>* node)
    {
        if(node==nullptr)
            return;
        if(node==rad)
        {
            sterge_subTree(rad);
            rad=nullptr;
            return;
        }
        TreeNode<T>* p=node->parent;
        int poz=-1;
        for(int i=0; i<p->nr_copii; i++)//pozitia nodului pe care vrem sa il stergem
            if(p->copii[i]==node){
                poz=i;
                break;
            }
        TreeNode<T>** v_nou=new TreeNode<T>*[p->nr_copii-1];
        int k=0;
        for(int i=0; i<p->nr_copii; i++)
            if(i!=poz)
            {
                v_nou[k]=p->copii[i];
                k++;
            }
        delete[] p->copii;
        p->copii=v_nou;
        p->nr_copii--;
        sterge_subTree(node);
    }
    TreeNode<T>* find(const T& val, bool (*compare)(const T&, const T&))
    {
        return find_rec(rad, val, compare);
    }
    TreeNode<T>* insert(TreeNode<T>* parent, int x, const T& val)
    {
        if(parent==nullptr)
        {
            if(rad!=nullptr)
                return nullptr;
            rad=new TreeNode<T>(val, nullptr);
            return rad;
        }
        TreeNode<T>* nou=new TreeNode<T>(val, parent);
        TreeNode<T>** v_nou=new TreeNode<T>*[parent->nr_copii+1];
        for(int i=0; i<x; i++)
            v_nou[i]=parent->copii[i];
        v_nou[x]=nou;
        for(int i=x; i<parent->nr_copii; i++)
            v_nou[i+1]=parent->copii[i];
        delete[] parent->copii;
        parent->copii=v_nou;
        parent->nr_copii++;
        return nou;
    }
    void sort(TreeNode<T>* node, bool (*compare)(const T&, const T&)=nullptr)
    {
        if (node==nullptr)
            return;
        for (int i=0; i<node->nr_copii-1; i++)
            for (int j=i+1; j<node->nr_copii; j++)
            {
                bool ok;
                if(compare!=nullptr)
                    ok=compare(node->copii[j]->value, node->copii[i]->value);
                else
                    ok=(node->copii[j]->value < node->copii[i]->value);
                if(ok)
                {
                    TreeNode<T>* aux=node->copii[i];
                    node->copii[i]=node->copii[j];
                    node->copii[j]=aux;
                }
            }
    }
    int count(TreeNode<T>* nod = nullptr)
    {
        if(nod==nullptr)
            nod=rad;
        return nr_rec(nod);
    }
};
