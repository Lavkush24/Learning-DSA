#include<iostream>
using namespace std;

class node 
{
    public:
        int data;
        node *next;
};


class stack
{
    private:
        node *top;

    public:
        stack();
        void push(int x);
        int pop();
        int peek(int pos);
        int length(node *t);
        void display();
};

stack::stack()
{
    top = NULL;
}

int stack::length(node *t)
{
    int l=0;
    while(t !=NULL)
    {
        l++;
        t = t->next;
    }
    return l;
}

void stack::push(int x)
{
    node *n = new node;
    if(n == NULL)
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        n->data = x;
        n->next = top;
        top = n; 
    }
}

int stack::pop()
{
    int x = -1;
    node *t;
    t = top;
    if(top == NULL)
    {
        cout<<"stack underflow"<<endl;
    }
    else
    {
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

int stack::peek(int pos)
{
    node *t;
    t = top;
    int x = -1;
    if(pos < 1 || pos > length(t))
    {
        cout<<"invalid position ";
        return x;
        cout<<endl;
    }
    if(top == NULL)
    {
        cout<<"stack underflow"<<endl;
    }
    else
    {
        while(pos > 1 && t->next != NULL)
        {
            t = t->next;
            pos--;
        }
        x = t->data;
    }
    return x;
}

void stack::display()
{
    node *t = top;
    while(t != NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}

int main()
{
    stack *s = new stack();
    s->push(45);
    s->push(7);
    s->push(5);
    cout<<s->pop()<<endl;
    cout<<s->peek(3)<<endl;
    s->display();
    return 0;
}