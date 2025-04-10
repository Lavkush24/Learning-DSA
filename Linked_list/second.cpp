#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
}*first=NULL;


void create(int a[], int size)
{
    struct node *p,*last;
    first = new struct node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for(int i=1; i<size; i++)
    {
        p = new struct node;
        p->data = a[i];
        last->next = p;
        p->next = NULL;
        last = p;
    }
}

int count(struct node *p)
{
    int c=0;
    while(p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void insert_at_begin(struct node *p,int x)
{
    struct node *n = new struct node;
    n->data = x;
    n->next = first;
    first = n;
}

void insert_at_index(struct node *p,int x,int pos)
{
    struct node *n,*temp;
    n = new struct node;
    n->data = x;
    temp = first;
    if(pos < 0 || pos > count(first))
    {
        return ;
    }
    else if(pos == 0)
    {
        insert_at_begin(first,x);
        return ;
    }
    for(int i=1; i<pos && temp; i++)
    {
        temp = temp->next;
    }
    n->next = temp->next; 
    temp->next = n;
}



void display(struct node *p)
{
    cout<<"________LINKED LIST__________"<<endl;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}




int main()
{
    int a[] = {4,6,2,1,8};
    create(a,5);
    display(first);
    insert_at_begin(first,9);
    display(first);
    insert_at_index(first,10,6);
    display(first);
    return 0;
}