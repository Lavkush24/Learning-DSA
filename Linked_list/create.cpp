#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL;

void insert_begin(int x)
{
    struct node *n = new struct node;
    n->data = x;
    n->next = NULL;
    if(first == NULL)
    {
        first = last = n;
    }
    else 
    {
        n->next = first;
        first = n;
    }
}

void insert_last(int x)
{
    struct node *n = new struct node;
    n->data = x;
    n->next = NULL;
    if(first == NULL)
    {
        first = last = n;
    }
    else
    {
        last->next = n;
        last = n;
    }
}

void display(struct node *p)
{
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

//inserting in the sorted linked list (assuming list in ascending order)
void insert_sort(struct node *p, int x)
{
    struct node *n = new struct node;
    struct node *q = NULL;
    n->data = x;
    n->next = NULL;
    if(x < first->data || first == NULL)
    {
        insert_begin(x);
        return ;
    }
    else 
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        n->next = q->next;
        q->next = n;
    }
}


void insert_sort(int x)
{
    struct node *n = new struct node;
    struct node *q = first;
    n->data = x;
    n->next = NULL;
    if(x < first->data)
    {
        insert_begin(x);
    }
    else 
    {
        while(q->next && q->next->data < x)
        {
            q = q->next;
        }
        n->next = q->next;
        q->next = n;

        if(q->next == NULL)
        {
            last = n;
        }
    }
}


int main() 
{
    int n;
    cout<<"Size of linked list: ";
    cin>>n;
    for(int i=1; i<n+1; i++)
    {
        int x;
        cout<<"Enter the value of "<<i<<" : ";
        cin>>x;
        insert_last(x);
    }
    display(first);
    insert_sort(8);
    display(first);
    return 0;
}