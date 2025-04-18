#include<iostream>
#include<string.h>
using namespace std;

class stack
{
    public:
        int size;
        int top;
        char *c;
};


void push(stack *st,char cc)
{
    if(st->top == st->size)
    {
        cout<<"stack overflow"<<endl;
        return ;
    }
    else
    {
        st->top++;
        st->c[st->top] == cc;
    }
}

char pop(stack *st)
{
    char x;
    if(st->top == -1)
    {
        cout<<"stack underflow ";
        return -1;
        cout<<endl;
    }
    else
    {
        x = st->c[st->top];
        st->top--;   
    }
    return x;
}


bool isEmpty(stack *st)
{
    if(st->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool isFull(stack *st)
{
    if(st->top == st->size)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    char exp[] = {'(','(','3','+','6',')','*','(','4','/','6',')'};
    stack *st = new stack;
    st->top = -1;
    st->size = strlen(exp);
    st->c = new char[st->size];

    for(int i=0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(') 
        {
            push(st,exp[i]);
        }
        else if(exp[i] == ')')
        {
            if(isEmpty(st))
            {
                cout<<"false"<<endl;
            }
            else
            {
                pop(st);
            }
        }
    }
    
    isEmpty(st)?cout<<"true"<<endl : cout<<"false"<<endl;
}