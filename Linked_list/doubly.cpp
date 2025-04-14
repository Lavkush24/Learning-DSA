#include<iostream>
using namespace std;

class node 
{
    public:
        int data;
        node *prev;
        node *next;
}*first=NULL;

void create(int arr[], int size)
{
    node *last,*n = new node;
    first = n;
    first->data = arr[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;
    for(int i=1; i<size; i++)
    {
        n = new node;
        n->data = arr[i];
        n->next = last->next;
        n->prev = last;
        last->next = n;
        last = n;
    }
}

void display(node *p)
{
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int length(node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}

void insert(int x,int pos)
{
    node *p,*n;
    n = new node;
    n->data = x;
    p = first;
    if(pos < 1 || pos > length(first)+1)
    {
        return ;
    }
    if(pos == 1)
    {
        if(first == NULL)
        {
            first = n;
            first->next = first->prev = NULL;
            return ;
        }
        else
        {
            n->next = first;
            n->prev = NULL;
            first->prev = n;
            first = n;
        }
    }
    else
    {
        for(int i=1; i<pos-1; i++)
        {
            p = p->next;
        }
        n->next = p->next;
        n->prev = p;
        if(p->next)
        {
            p->next->prev = n;
        }
        p->next = n;
    }
}


int Delete(int pos)
{
    node *p,*temp;
    p = first;
    int x;
    if(pos < 1 || pos > length(first))
    {
        return -1;
    }
    if(pos == 1)
    {
        if(p->next == NULL)
        {
            temp = p;
            x = temp->data;
            delete temp;
            return x;
        }
        else 
        {
            temp = first;
            first = first->next;
            x = temp->data;
            delete temp;
            if(first){ first->prev = NULL; }
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
        if(temp->next)
        {
            temp->next->prev = p;
        }
        x = temp->data;
        delete temp;
        return x;
    }
}


void reverse(node *p)
{
    node *temp;
    while(p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    int a[] = {45,67,32,23};
    create(a,4);
    cout<<"Length of list: "<<length(first)<<endl;
    display(first);

    reverse(first);
    display(first);
    // while(1)
    // {
    //     int pos;
    //     cin>>pos;
    //     Delete(pos);
    //     display(first);
    // }
    return 0;
}