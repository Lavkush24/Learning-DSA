#include<iostream>
using namespace std;
#include "List.h"
#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
    private:
        list<T> l;

    public:
        void enqueue(T x);
        T dequeue();
        bool isEmpty();
        void display();
};



template<typename T>
void Queue<T>::enqueue(T x)
{
    l.insert(x,l.length());
}

template<typename T>
T Queue<T>::dequeue()
{
    T x;
    if(l.length() == 0)
    {
        cout<<"Empty queue"<<endl;
    }
    else
    {
        x = l.remove(1);
    }
    return x;
}

template<typename T>
bool Queue<T>::isEmpty()
{
    if(l.length() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
void Queue<T>::display()
{
    l.display();
}

#endif