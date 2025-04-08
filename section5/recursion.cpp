#include<iostream>
using namespace std;


//static variable in the recursion

//without static variable
int fun(int n)
{
    if(n>0)
    {
        return fun(n-1)+n;
    }
    return 0;
}

//with static variable 
int fun2(int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return fun2(n-1)+x;
    }
}


//tree recursion
void tree(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        tree(n-1);
        tree(n-1);
    }
}

//indirect recursion 
void funB(int n);
void funA(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        funB(n-1);
    }
}

void funB(int n) 
{
    if(n>1)
    {
        cout<<n<<" ";
        funA(n/2);
    }
}


//nested recursion 
int func(int n)
{
    if(n > 100) {
        return n-10;
    }else {
        return func(func(n+11));
    }
}


int main()
{
    int n = 3; 
    // cout<<"Result for fun(5): "<<fun(n)<<endl;
    // cout<<"Result for fun2(5): "<<fun2(n)<<endl;
    // cout<<"Result for fun2(5): "<<fun2(n)<<endl;
    // tree(n);
    funA(20);
    cout<<endl;
    cout<<"Result of nested recursion: "<<func(120)<<endl;
    
    return 0;
}