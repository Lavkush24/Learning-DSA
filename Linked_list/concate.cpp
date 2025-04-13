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
}*first=NULL,*last=NULL,*second=NULL,*third=NULL,*clast;

void create(node **p,int x)
{
    node *n = new node(x);
    if(*p == NULL)
    {
        *p = clast = n;
    }
    else 
    {
        clast->next = n;
        clast = n;
    }
}

void display(node *p)
{
    cout<<"List : ";
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}


void concate(node *p,node *q)
{
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(node *p,node *q)
{
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p){ 
        last->next = p ;
    }
    else 
    {
        last->next = q;
    }

}


bool isloop(node *l)
{
    node *p,*q;
    p = q = l;
    do
    {
        p = p->next;
        q = q->next;
        q = q!=NULL ? q->next: NULL;
    } while (p && q && p!=q);
    
    return p==q? true: false;
}

int main() 
{
    node *t;
    int n,m;
    cout<<"Enter size of both list: ";
    cin>>n>>m;
    cout<<"Enter element of first list : ";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        create(&first,x);
    }
    cout<<"Enter element of second list : ";
    for(int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        create(&second,x);
    }
    display(first);
    display(second);
    // concate(first,second);
    merge(first,second);
    display(third);
    // t = first->next->next;
    // last->next = t;              //for making loop in the first linked list; 
    cout<<isloop(first)<<endl;
    return 0;
}