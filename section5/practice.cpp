#include<iostream>
#include<cmath>
using namespace std;

//sum of n natural numbers
int sum_n_natural(int n)
{
    if(n > 0) {
        return sum_n_natural(n-1)+n;
    }
    return 0;
}

//factorial of a number
int factorial(int n)
{
    if(n < 0) {
        return 0;
    }
    if(n == 0){
        return 1;
    }else {
        return factorial(n-1)*n;
    }
}

//power using recursion
int powerOf(int m , int n) 
{
    if(n < 0) {
        cout<<"Out of scope"<<endl;
        return 0;
    }
    if(n == 0) {
        return 1;
    }else {
        return powerOf(m,n-1)*m;
    }
}

//efficient power function
int power2(int m,int n) 
{
    if(n == 0)
        return 1;
        
    if(n%2 == 0)
        return power2(m*m,n/2);
    return m*power2(m*m,(n-1)/2);
}


//taylor series 
/* if multiple variables are involve in the calculation then we need to use static variable 
because recursive function is only return a single value*/
double e(int x,int n)
{
    static double p = 1, f = 1;
    double sum;
    if(n == 0)
    {
        return 1;
    }else 
    {
        sum = e(x,n-1);
        p *= x;
        f *= n;
        return sum + p/f;   
    }
}


//taylors series using horner's rule

//iterative approach
double taylor(int x, int n)
{
    double r = 1;
    for(;n>0; n--) 
    {
        r = 1 + (double)x/(double)n*r;
    }
    return r;
}

//using recursion 
double taylor2(int x,int n) 
{
    static double s = 1;
    if(n == 0)
        return s;
    s = 1 + (double)x/(double)n*s;
    return taylor2(x, n-1);  
}


/* Fibonacci series using recursion */
int fib(int n) 
{
    if(n <= 1)
        return n;
    return fib(n-2)+fib(n-1);
}


//fibo using iteration
int fibo(int n)
{
    int t=0, t1=1, s;
    if(n<=1) return n;
    for(int i=2; i<=n; i++) {
        s = t + t1;
        t = t1;
        t1 = s;
    }
    return s;
}



//fibonacci series after memoization 
int f[10];
int fibom(int n) 
{
    if(n<=1)
    {
        f[n] = n;
        return n;
    }else
    {
        if(f[n-1] == -1)
        {
            f[n-1] = fibom(n-1);
        }
        if(f[n-2] == -1)
        {
            f[n-2] = fibom(n-2);
        }

        return f[n-2]+f[n-1];
    }
} 


// ncr using recursive (combinational formula) ncr = n!/(n-r)! r!
int c(int n,int r)
{
    int t1,t2,t3;
    t1 = factorial(n);
    t2 = factorial(r);
    t3 = factorial(n-r);
    return t1 / (t2*t3);
}

//ncr using pascals triangle 
int C(int n, int r)
{
    if(r==0 || n==r)
        return 1;
    return C(n-1,r-1)+C(n-1,r);
}


//Tower of hanoi 
void TOH(int n,int a,int b,int c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        cout<<"Move tower : "<<"("<<a<<","<<c<<")"<<endl;
        TOH(n-1,b,a,c);
    }
}


int fu(int n)
{
    int x = 1,k;
    if(n == 1) return x;
    for(k=1; k<n; ++k)
    x = x + fu(k)*fu(n-k);
    return x;
}

int main() 
{
    //array used in the memoization f
    // for(int i=0;i<10; i++)
    // {
    //     f[i] = -1;
    // }
    // int n;
    // cout<<"Enter value of n: ";
    // cin>>n;
    // cout<<"Sum of n natural numbers: "<<sum_n_natural(n)<<endl;
    // cout<<"Factorial of "<<n<<" is: "<<factorial(n)<<endl;
    // cout<<"Power of : "<<power2(2,n)<<endl;

    // cout<<"Taylor series sum of e^4: "<<e(2,10)<<endl;
    // cout<<"Taylor series sum of e^4: "<<taylor(2,10)<<endl;
    // cout<<"Taylor series sum of e^4: "<<taylor2(2,10)<<endl;

    // cout<<"Fiboseries term n: "<<fibo(7)<<endl;
    // cout<<"Fiboseries term n: "<<fib(7)<<endl;
    // cout<<"Fiboseries term n: "<<fibom(7)<<endl;
    // cout<<"Value of n C r: "<<c(5,2)<<endl;
    // cout<<"Value of n C r: "<<C(5,2)<<endl;

    // TOH(4,1,2,3);

    // int p = 5;
    // cout<<fu(p,p)<<endl;
    // int t = 5;
    // int k;
    // for(k=1;k<p;++k);
    // cout<<k<<endl;

    cout<<fu(5)<<endl;
    
    return 0;
}