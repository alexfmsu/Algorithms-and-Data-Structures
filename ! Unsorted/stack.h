#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>

class myStack
{
    public:
        myStack();
        T top();
        void pop();
        void push( T );
        bool empty();
        int size();
        void print();
        void link(Node<T> *h, Node<T> *t);
        //void copy(myStack);
        Node<T> *headPtr;
        Node<T> *Top;
        Node<T> *temp;
        
};

#endif

template <typename T>
myStack<T>::myStack()
{
    headPtr = NULL;
    temp = NULL;
    Top = NULL;
}

template <typename T>
T myStack<T>::top()
{
    if(!empty() ) {
        //cout << "top value RETURNED is " << Top->value << endl;
        return Top->value;
    }
}

template <typename T>
void myStack<T>::pop()
{
    Node<T> *iter;
    if (!empty() ) {
        iter = headPtr;
        temp = headPtr;
        if (iter->next == NULL) {
            headPtr = temp = Top = NULL;
            return;
        }
        while (iter->next != NULL) {
            temp = iter;
        //  cout << "*" << iter->value << endl;
            iter = iter->next;
        }
        //cout << "NEW TOP is " << temp->value << endl;
        temp->next = NULL;
        Top = temp;
    }
    else 
        return;
}

template <typename T>
void myStack<T>::push(T val)
{
    temp = new Node<T>;
    temp->next = NULL;
    //cout << "*******add of temp is " << temp << endl;
    if (headPtr == NULL) {
        Top = temp;
        Top->setVal(val);
    //  cout << val << " " << &(Top->value) << endl;
        Top->setNode(NULL);
        headPtr = Top;
        //cout << "head " << &(Top->value) << endl;
        return;
    }
    temp->value = val;
    Top->next = temp;
    Top = temp;
    //cout << "pushed " << val << " " << Top->value << endl;
    //print();
}

template <typename T>
bool myStack<T>::empty()
{
    if (headPtr == NULL) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
int myStack<T>::size()
{
    int counter = 1;
    Node<T> *iter = headPtr;
    if ( empty() ) {
        return 0;
    }
    //cout << "top value is " << Top->value;
    while (iter->next != NULL) {
    //  cout << "here****\n";
        //cout << " **" << iter->value << endl;
        iter = iter->next;
            
        ++counter;
    }
    //cout << "here*\n";
    //cout << "counter is " << counter << endl;
    return counter;
}

template <typename T>
void myStack<T>::print()
{
    Node<T> *iter = headPtr;
    while (iter->next != NULL) {
    //  cout << "here****\n";
        cout << " **" << iter->value << endl;
        iter = iter->next;
    }
    cout << " --" << iter->value << endl;
}

template <typename T>
void myStack<T>::link(Node<T> * n, Node<T> *t)
{
    n->next = t;
}
/*
template <typename T>
void myStack<T>::copy(myStack s)
{
    Node<T> *iter = headPtr;
    s.headPtr = headPtr;
    while (iter->next != NULL) {
        s.Top = iter;
        cout << " **" << iter->value << endl;
        iter = iter->next;
    }
    cout << " **" << iter->value << endl;
}*/