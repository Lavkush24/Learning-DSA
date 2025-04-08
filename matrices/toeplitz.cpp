#include<iostream>
using namespace std;

class Toeplitz
{
    private:
        int *a;
        int n;

    public:
        Toeplitz(int n = 4)
        {
            this->n = n;
            a = new int[2*n-1];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~Toeplitz() { delete []a ; };
};

void Toeplitz::set(int i,int j,int x)
{
    if(i <= j)
    {
        a[j-i] = x;
    }
    else if(i > j)
    {
        a[n+i-j-1] = x;
    }
}

int Toeplitz::get(int i,int j)
{
    if(i <= j)
    {
        return a[j-i];
    }
    else if(i > j)
    {
        return a[n+i-j-1];
    }
    else 
    {
        return 0;
    }
}

void Toeplitz::display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i <= j)
            {
                cout<<a[j-i]<<" ";
            }
            else if(i > j)
            {
                cout<<a[n+i-j-1]<<" ";
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
    Toeplitz s(n);
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