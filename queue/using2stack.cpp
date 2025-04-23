#include<iostream>
using namespace std;

class stack
{
    public:
        int top;
        int size;
        int *a;
};

void push(stack *s, int x)
{
    if(s->top == s->size-1)
    {
        cout<<"stack overflow"<<endl;
        return ;
    }
    else 
    {
        s->top++;
        s->a[s->top] = x;
    }
}

int pop(stack *s)
{
    int x=-1;
    if(s->top == -1)
    {
        cout<<"stack underflow"<<endl;
        return -1;
    }
    else
    {
        x = s->a[s->top];
        s->top--;
    }
    return x;
}


void enqueue(stack *s1,int x)
{
    if(s1->top == s1->size-1)
    {
        cout<<"queue is full"<<endl;
        return ;
    }
    else
    {
        push(s1,x);
    }
}

int dequeue(stack *s1,stack *s2)
{
    int x=-1;
    if(s2->top == -1)
    {
        if(s1->top == -1)
        {
            cout<<"queue is empty"<<endl;
            return -1;
        }
        else 
        {
            while(s1->top != -1)
            {
                push(s2,pop(s1));
            }
        }
    }
    else 
    {
        x = pop(s2);
    }
    return x;
}

void display(stack *s1, stack *s2)
{
    cout << "Queue: ";

    // Print elements from s2 (already in correct order)
    for (int i = 0; i <= s2->top; i++)
    {
        cout << s2->a[i] << " ";
    }

    // Print elements from s1 in reverse order
    for (int i = s1->top; i >= 0; i--)
    {
        cout << s1->a[i] << " ";
    }

    cout << endl;
}


int main()
{
    stack *s1 = new stack;
    stack *s2 = new stack;
    int s;
    cin>>s;
    s1->size = s2->size = s;
    s1->top = s2->top = -1;

    s1->a = new int[s];
    s2->a = new int[s];
    enqueue(s1,23);
    enqueue(s1,23);
    enqueue(s1,23);
    enqueue(s1,23);
    dequeue(s1,s2);
    dequeue(s1,s2);
    dequeue(s1,s2);
    dequeue(s1,s2);
    display(s1,s2);
    return 0;
};