#include<iostream>
using namespace std;


class node 
{
    public:
        int data;
        node *next;
}*front=NULL,*rear=NULL;


void enqueue(int x)
{
    node *n ;
    n = new node;
    n->data = x;
    n->next = NULL;
    if(!n)
    {
        cout<<"queue overflow";
        return ;
    }
    else 
    {
        if(front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue()
{
    int x=-1;
    node *temp;
    if(front == rear)
    {
        cout<<"queue underflow"<<endl;
        return -1;
    }
    else
    {
        temp = front;
        front = front->next;
        x = temp->data;
        delete temp;
    }
    return x;
}


void display()
{
    node *temp;
    temp = front;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{
    enqueue(45);
    // enqueue(67);
    // enqueue(80);
    // enqueue(23);
    // display();
    dequeue();
    dequeue();
    display();
    return 0;
}