#include<iostream>
using namespace std;

class node 
{
    public:
        int data;
        node *next;

        node(int x)
        {
            this->data = x;
            this->next = NULL;
        }
}*first=NULL,*last=NULL;


void create(int x)
{
    node *n = new node(x);
    if(first == NULL)
    {
        first = last = n;
    }
    last->next = n;
    last = n;
}

void display(node *l)
{
    cout<<"List : ";
    while(l != NULL)
    {
        cout<<l->data<<" ";
        l = l->next;
    }
    cout<<endl;
}


int count(node *l)
{ 
    int x = 0;
    while(l != NULL)
    {
        x++;
        l = l->next;
    }
    return x;
}

/* reverse with the help of (auxillary array) extra   array (reverse element)*/
void reverse(node *p)
{
    int n = count(first);
    int arr[n];
    for(int i=0; p != NULL; i++)
    {
        arr[i] = p->data;
        p = p->next;
    }
    p = first;
    for(int i=n-1; i>=0 && p; i--)
    {
        p->data = arr[i];
        p = p->next;
    }
}


/* Implementation of the reverse links (using sliding pointers)*/
void Preverse(node *p)
{
    node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}


/* Reverse using the recursive function */
void reverse(node *q,node *p)
{
    if(p)
    {
        reverse(p,p->next);
        p->next = q; 
    }
    else 
    {
        first = q;
    }
}

int main() 
{
    int n;
    cout<<"Enter size of list: ";
    cin>>n;
    cout<<"Enter the element: ";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x; 
        create(x);
    }
    display(first);
    // reverse(first);
    // Preverse(first);
    reverse(NULL,first);
    display(first);
    return 0;
}