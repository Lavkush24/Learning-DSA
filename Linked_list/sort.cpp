#include<iostream>
#include<climits>
using namespace std;

class node 
{
    public:
        int data;
        node *next;

        node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
}*first=NULL,*last=NULL;


void insert_last(int x)
{
    node *n = new node(x);
    if(first == NULL) {
        first = last = n;
    }
    else 
    {
        last->next = n;
        last = n;
    }
}

void display(node *p) 
{
    cout<<"List: ";
    while(p != NULL) 
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

bool increasing_order(node *p)
{
    int min = INT_MIN;
    while(p != NULL)
    {
        if(p->data < min) 
        {
            return false;
        }
        min = p->data;
        p = p->next;
    }
    return true;
}

bool decreasing_order(node *p) 
{
    int max = INT_MAX;
    while(p != NULL) 
    {
        if(max < p->data)
        {
            return false;
        }
        max = p->data;
        p = p->next;
    }
    return true;
}


void remove_duplicate(node *p)
{
    node *q;
    q = p->next;
    while(q != NULL)
    {
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main() 
{
    int n;
    cout<<"Enter size of list: ";
    cin>>n;
    cout<<"Enter the value of element: ";
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        insert_last(x);
    }
    display(first);
    remove_duplicate(first);
    display(first);
    return 0;
}
