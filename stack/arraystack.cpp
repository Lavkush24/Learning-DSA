#include<iostream>
using namespace std;

class stack
{
    private:
        int size;
        int *a;
        int top;

    public:
        stack()
        {
            size = 5;
            a = new int[size];
            top = -1;
        }
        stack(int s);
        bool isEmpty();
        bool isFull();
        void push(int x);
        int pop();
        int peek(int index);
        int stackTop();
        void display();
        ~stack();
};

stack::stack(int s)
{
    this->a = new int[s];
    top = -1;
    size = s;
}

bool stack::isEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool stack::isFull()
{
    if(top == size-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void stack::push(int x)
{
    if(isFull())
    {
        cout<<"stack is overflow"<<endl;
        return ;
    }
    else
    {
        top++;
        a[top]  = x;
    }
}

int stack::pop()
{
    if(isEmpty())
    {
        cout<<"Stack is underflow"<<endl;
        return 0;
    }
    else
    {
        return a[top--];
    }
}

int stack::peek(int pos)
{
    if(pos < 0 || pos > top+1)
    {
        cout<<"Invalid index"<<endl;
        return -1;
    }
    return a[top-pos+1];
}


int stack::stackTop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return a[top];
    }
}


void stack::display()
{
    int p = top;
    while(p != -1)
    {
        cout<<a[p]<<" ";
        p--;
    }
    cout<<endl;
}

stack::~stack()
{
    delete a;
}


int main()
{
    int s;
    cout<<"Enter size of stack: ";
    cin>>s;
    stack *st = new stack(s);
    st->push(8);
    st->push(34);
    st->push(35);
    st->push(89);
    st->push(12);
    st->display();
    st->pop();
    st->display();
    cout<<st->stackTop()<<endl;
    cout<<st->peek(5)<<endl;
    return 0;
}