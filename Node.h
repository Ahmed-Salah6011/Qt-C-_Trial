#ifndef NODE_H
#define NODE_H
#include<iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

template <class Ktype , class Vtype>
class Node
{
    Ktype key;
    Vtype value;
    Node<Ktype, Vtype>* left;
    Node<Ktype, Vtype>* right;

public:
    Node();
    void set_key(Ktype k);
    void set_value(Vtype v);
    void set_left_ptr(Node<Ktype, Vtype>* l);
    void set_right_ptr(Node<Ktype, Vtype>* l);
    Ktype get_key();
    Vtype get_value();
    Node<Ktype, Vtype>* get_right_ptr();
    Node<Ktype, Vtype>* get_left_ptr();
    //friend class Dict;
};


template <class Ktype, class Vtype>
void Node<Ktype, Vtype>::set_left_ptr(Node<Ktype, Vtype>* l)
{
    this->left = l;
}

template <class Ktype, class Vtype>
void Node<Ktype, Vtype>::set_right_ptr(Node<Ktype, Vtype>* l)
{
    this->right = l;
}

template <class Ktype, class Vtype>
Node<Ktype, Vtype>* Node<Ktype, Vtype>::get_right_ptr()
{
    return this->right;
}

template <class Ktype, class Vtype>
Node<Ktype, Vtype>* Node<Ktype, Vtype>::get_left_ptr()
{
    return this->left;
}

template <class Ktype, class Vtype>
Node<Ktype, Vtype>::Node()
{

}

template <class Ktype, class Vtype>
void Node<Ktype, Vtype>::set_key(Ktype k)
{
    this->key = k;
}

template <class Ktype, class Vtype>
void Node<Ktype, Vtype>::set_value(Vtype v)
{
    this->value = v;
}

template <class Ktype, class Vtype>
Ktype Node<Ktype, Vtype>::get_key()
{
    return this->key;
}

template <class Ktype, class Vtype>
Vtype Node<Ktype, Vtype>::get_value()
{
    return this->value;
}
#endif // NODE_H
