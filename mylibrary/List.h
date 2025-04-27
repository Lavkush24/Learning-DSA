#include<iostream>
using namespace std;
#ifndef LIST_H
#define LIST_H

template<typename T>
class node 
{
    public:
        T data;
        node<T> *next;
        node<T> *prev;
    
        node(T x)
        {
            data = x;
            next = prev = NULL;
        }
};

template<typename T>
class list
{
    private:
        node<T> *head;
    
    public:
        list();
        list(T arr[],int size);
        void insert(T x,int pos);
        T remove(int pos);
        void display();
        int length();
};

template<typename T>
list<T>::list()
{
    node<T> *last,*n = new node<T>(T());
    last = head = n;
    head->next = head->prev = head;
}

template<typename T>
list<T>::list(T arr[], int size)
{
    node<T> *last,*n = new node(arr[0]);
    last = head = n;
    head->next = head->prev = head;

    for(int i=1; i<size; i++)
    {
        n = new node(arr[i]);
        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
        last = n;
    }
}

template<typename T>
int list<T>::length()
{
    int l=0;
    node<T> *temp = head;
    do
    {
        l++;
        temp = temp->next;
    } while (temp != head);
    return l;
}

template<typename T>
void list<T>::insert(T x,int pos)
{
    node<T> *temp,*n = new node(x);
    int l=0;
    temp = head;
    do
    {
        l++;
        temp = temp->next;
    } while (temp != head);

    if(pos < 1 || pos > l)
    {
        cout<<"Not a valid position"<<endl;
        return ;
    }
    if(pos == 1)
    {
        n->next = head;
        n->prev = head->prev;
        head->prev->next = n;
        head = n;
    }
    else if(head == NULL)
    {
        head = temp = n;
        head->next = head->prev = head;
        return ;
    }
    else
    {
        temp = head;
        while(pos > 2)
        {
            temp = temp->next;
            pos--;
        }
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }
}

template<typename T>
T list<T>::remove(int pos)
{
    node<T> *temp,*p;
    temp = head;
    T x;
    int l=0;
    p = head;

    do
    {
        l++;
        temp = temp->next;
    } while (temp != head);

    if(pos < 1 || pos > l)
    {
        return -1;
    }
    if(pos == 1)
    {
        if(head == NULL)
        {
            x = head->data;
            head = NULL;
            return x;
        }
        else
        {
            temp = head;
            head = head->next;
            head->prev = temp->prev;
            temp->prev->next = head;
            x = temp->data;
            delete temp;
            return x;
        }
    }
    else
    {
        for(int i=1; i<pos-1; i++)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        temp->next->prev = p;
        x = temp->data;
        delete temp;
        return x;
    }
}

template<typename T>
void list<T>::display()
{
    node<T> *temp;
    temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}


#endif