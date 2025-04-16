#include<iostream>
using namespace std;

class node
{
    public:
        int coeff;
        int exp;
        node *next;
}*poly=NULL;

void create(node *p)
{
    int n;
    cout<<"Enter number of element : ";
    cin>>n;
    poly = new node;
    cin>>poly->coeff>>poly->exp;
    poly->next = NULL;
    node *last = poly;
    for(int i=1; i<n; i++)
    {
        node *t = new node;
        cin>>t->coeff>>t->exp;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void display(node *p)
{
    while(p!=NULL)
    {
        if(p->next == NULL)
        {
            cout<<p->coeff<<"x^"<<p->exp;
        }
        else
        {
            cout<<p->coeff<<"x^"<<p->exp<<" + ";
        }
        p = p->next;
    }
    cout<<endl;
}


int main()
{
    create(poly);
    display(poly);
    return 0;
}