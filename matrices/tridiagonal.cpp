#include<iostream>
using namespace std;

class Tridiagonal
{
    private:
        int *a;
        int n;

    public:
        Tridiagonal(int n = 4)
        {
            this->n = n;
            a = new int[3*n-2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~Tridiagonal() { delete []a ; };
};

void Tridiagonal::set(int i,int j,int x)
{
    int t = i-j;
    if(t == 1)
    {
        a[i-2] = x;
    }
    else if(t == 0)
    {
        a[n+i-2] = x;
    }
    else if(t == -1)
    {
        a[2*n+i-2] = x;
    }
}

int Tridiagonal::get(int i,int j)
{
    int t = i-j;
    if(t == 1)
    {
        return a[i-2];
    }
    else if(t == 0)
    {
        return a[n+i-2];
    }
    else if(t == -1)
    {
        return a[2*n+i-2];
    }
    else
    {
        return 0;
    }
}

void Tridiagonal::display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int t = i-j;
            if(t == 1)
            {
                cout<<a[i-2]<<" ";
            }
            else if(t == 0)
            {
                cout<<a[n+i-2]<<" ";
            }
            else if(t == -1)
            {
                cout<<a[2*n+i-2]<<" ";
            }
            else
            {
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}


int main() 
{
    int n;
    cout<<"Enter size of array: " ;
    cin>>n;
    Tridiagonal s(n);
    cout<<"Enter matrix: "<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int x;
            cin>>x;
            s.set(i,j,x);
        }
    }
    cout<<endl;
    cout<<endl;
    s.display();
    return 0;
}