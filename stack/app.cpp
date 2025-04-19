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
    if(st->top == st->size-1)
    {
        cout<<"stack overflow"<<endl;
        return ;
    }
    else
    {
        st->top++;
        st->c[st->top] = cc;
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

char peek(stack *st)
{
    if(isEmpty(st))
    {
        return -1;
    }
    else
    {
        return st->c[st->top];
    }
}



bool valid_exp(char exp[])
{
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
                return false;
            }
            else
            {
                pop(st);
            }
        }
    }
    return isEmpty(st)? true : false;
}


bool adv_valid_exp(char exp[])
{
    stack *st = new stack;
    st->top = -1;
    st->size = strlen(exp);
    st->c = new char[st->size];

    for(int i=0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') 
        {
            push(st,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty(st))
            {
                return false;
            }
            else
            {
                if(exp[st->top]-exp[i] == -1 || exp[st->top]-exp[i] == -2)
                {
                    pop(st);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return isEmpty(st)? true : false;
}


bool isOperand(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')')
        return false;
    else 
        return true;
}

int precedence(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char * infixToPostfix(char exp[])
{
    stack *st = new stack;
    st->size = strlen(exp);
    st->top = -1;
    st->c = new char[st->size];

    char *postfix = new char[st->size + 1];
    int i=0,j=0;
    while(exp[i] != '\0')
    {
        if(isOperand(exp[i]))
        {
            postfix[j++] = exp[i++];
        }
        else
        {
            if(precedence(exp[i]) > precedence(peek(st)))
            {
                push(st,exp[i++]);
            }
            else
            {
                postfix[j++] = pop(st);
            }
        }
    }

    while(!isEmpty(st))
    {
        postfix[j++] = pop(st);
    }
    postfix[j] = '\0';
    return postfix;
}


int preOutStack(char c)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 3;
    }
    else if(c=='^')
    {
        return 6;
    }
    else if(c=='(')
    {
        return 7;
    }
    else if(c==')')
        return 0;
    else
        return -1;
}

int preInStack(char c)
{
    if(c=='+' || c=='-')
    {
        return 2;
    }
    else if(c=='*' || c=='/')
    {
        return 4;
    }
    else if(c=='^')
    {
        return 5;
    }
    else if(c=='(')
    {
        return 0;
    }
    else
        return -1;
}


char * adv_infixToPostfix(char exp[])
{
    stack *st = new stack;
    st->size = strlen(exp);
    st->top = -1;
    st->c = new char[st->size];

    char *postfix = new char[st->size + 1];
    int i=0,j=0;
    while(exp[i] != '\0')
    {
        if(isOperand(exp[i]))
        {
            postfix[j++] = exp[i++];
        }
        else
        {
            if(preOutStack(exp[i]) > preInStack(peek(st)))
            {
                push(st,exp[i++]);
            }
            else if(preOutStack(exp[i]) == preInStack(peek(st)))
            {
                pop(st);
                i++; 
            }
            else
            {
                postfix[j++] = pop(st);
            }
        }
    }

    while(!isEmpty(st))
    {
        postfix[j++] = pop(st);
    }
    postfix[j] = '\0';
    return postfix;
}

int evaluation(char exp[])
{
    stack *st = new stack;
    st->size = strlen(exp);
    st->top = -1;
    st->c = new char[st->size];
    int r,x1,x2,o;
    for(int i=0; exp[i] != '\0'; i++)
    {
        if(isOperand(exp[i]))
        {
            push(st,exp[i]-'0');
        }
        else
        {
            x2 = (int)pop(st);
            x1 = (int)pop(st);
            switch(exp[i])
            {
                case '+': 
                    r = x1 + x2;
                    break;
                case '-':
                    r = x1 - x2;
                    break;
                case '*':
                    r = x1*x2;
                    break;
                case '/':
                    r = x1/x2;
                    break;
            }
            push(st,r);
        }
    }
    return peek(st);
}

int main()
{
    char exp[] = "((2+3)*4-7)";
    cout<<adv_valid_exp(exp)<<endl;
    cout<<adv_infixToPostfix(exp)<<endl;
    cout<<evaluation(adv_infixToPostfix(exp))<<endl;
    
    return 0;
}