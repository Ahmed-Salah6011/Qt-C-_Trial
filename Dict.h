#ifndef DICT_H
#define DICT_H
#include<iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

template <class Ktype, class Vtype>
class Dict
{
    Node<Ktype, Vtype>* root;
    void InOrderAux(Node<Ktype, Vtype> *pn, void(*pf)(string v));
    void printAux(Node<Ktype, Vtype> *pn);
    int s;

public:
    Dict();
    int insert(Ktype key, Vtype value);
    template<typename T>
    int insert_set(Ktype key, T val);

    void InOrder(void(*pf)(string v));
    void printItems();
    int size();
    bool empty();
    Vtype find(Ktype key);
};


template <class Ktype, class Vtype>
Dict<Ktype, Vtype>::Dict()
{
    this->root=nullptr;
    this->s = 0;
}

template <class Ktype, class Vtype>
int Dict<Ktype, Vtype>::size()
{
    return s;
}

template <class Ktype, class Vtype>
bool Dict<Ktype, Vtype>::empty()
{
    return s==0;
}

template <class Ktype, class Vtype>
Vtype  Dict<Ktype, Vtype>::find(Ktype key)
{
    Node<Ktype, Vtype> *curr;
    int flag = 0;
    if (!this->root)
    {
        flag = 1;
    }
    else
    {
        curr = this->root;
        while (curr)
        {
            if (key > curr->get_key())
            {
                curr = curr->get_right_ptr();
            }
            else if (key < curr->get_key())
            {
                curr = curr->get_left_ptr();
            }
            else if (key == curr->get_key())
            {
                return curr->get_value();
            }
        }
        flag = 1;
    }
    if (flag == 1)
    {
        Vtype y;
        return y;
    }
}

template <class Ktype, class Vtype>
void Dict<Ktype, Vtype>::printAux(Node<Ktype, Vtype> *pn)
{
    if (pn)
    {
        printAux(pn->get_left_ptr());
        cout << pn->get_key() << " : " << pn->get_value() << endl;
        printAux(pn->get_right_ptr());
    }
}

template <class Ktype, class Vtype>
void Dict<Ktype, Vtype>::printItems()
{
    cout << "{ ";
    this->printAux(this->root);
    cout << "}" << endl;
}

template <class Ktype, class Vtype>
int Dict<Ktype, Vtype>::insert(Ktype key, Vtype val)
{
    Node<Ktype, Vtype> *curr, *prev = nullptr;
    Node<Ktype, Vtype>* p = new Node<Ktype, Vtype>();
    if (!p){ return -1; }
    p->set_left_ptr(nullptr); p->set_right_ptr(nullptr);
    p->set_key(key); p->set_value(val);


    if (!this->root)
    {
        this->root = p;
        this->s++;
    }
    else
    {
        curr = this->root;
        int equalflag = 0;
        while (curr)
        {
            prev = curr;
            if (key > curr->get_key())
            {
                Node<Ktype, Vtype> *x = curr->get_right_ptr();
                curr=x;
            }
            else if (key < curr->get_key())
            {
                Node<Ktype, Vtype> *x = curr->get_left_ptr();
                curr=x;
            }
            else if (key == curr->get_key())
            {
                curr->set_value(val);
                equalflag = 1;
                break;
            }
        }

        if (equalflag == 1)
        {
            delete p;
        }
        else
        {
            if (key > prev->get_key())
            {
                prev->set_right_ptr(p);
            }
            else if (key < prev->get_key())
            {
                prev->set_left_ptr(p);
            }
            this->s++;
        }

    }
    return 1;
}


template <class Ktype, class Vtype>
template<typename T>
int Dict<Ktype, Vtype>::insert_set(Ktype key, T val)
{
    Node<Ktype, Vtype> *curr, *prev = nullptr;
    Node<Ktype, Vtype>* p = new Node<Ktype, Vtype>();
    if (!p){ return -1; }
    p->set_left_ptr(nullptr); p->set_right_ptr(nullptr);
    p->set_key(key);
    set<T> x;
    x.insert(val);
    p->set_value(x);


    if (this->root == nullptr)
    {
        this->root = p;
        this->s++;
    }
    else
    {
        curr = this->root;
        int equalflag = 0;
        while (curr)
        {
            prev = curr;
            if (key > curr->get_key())
            {
                Node<Ktype, Vtype> *x = curr->get_right_ptr();
                curr = x;
            }
            else if (key < curr->get_key())
            {
                Node<Ktype, Vtype> *x = curr->get_left_ptr();
                curr = x;
            }
            else if (key == curr->get_key())
            {
                Vtype y = curr->get_value();
                y.insert(val);
                curr->set_value(y);
                equalflag = 1;
                break;
            }
        }

        if (equalflag == 1)
        {
            delete p;
        }
        else
        {
            if (key > prev->get_key())
            {
                prev->set_right_ptr(p);
            }
            else if (key < prev->get_key())
            {
                prev->set_left_ptr(p);
            }
            this->s++;
        }

    }
    return 1;
}

template <class Ktype, class Vtype>
void Dict<Ktype, Vtype>::InOrderAux(Node<Ktype, Vtype> *pn, void(*pf)(string v))
{
    if (pn)
    {
        InOrderAux(pn->get_left_ptr(), pf);
        (*pf)(pn->get_key());
        InOrderAux(pn->get_right_ptr(), pf);
    }
}

template <class Ktype, class Vtype>
void Dict<Ktype, Vtype>::InOrder(void(*pf)(string v))
{
    this->InOrderAux(this->root,pf);
}
#endif // DICT_H
