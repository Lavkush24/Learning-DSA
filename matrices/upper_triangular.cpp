#include<iostream>
using namespace std;

//using row major representation
class Upper
{
    private:
        int n;
        int *a;

    public:
        Upper(int n = 4)
        {
            this->n = n;
            a = new int[n*(n+1) / 2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~Upper() { delete [] a; };
};


void Upper::set(int i, int j, int x)
{
    if(i <= j)
    {
        a[n*(i-1)-(i-2)*(i-1)/2-(j-i)] = x;
    }
}

int Upper::get(int i, int j)
{
    if(i <= j) return a[n*(i-1)-(i-2)*(i-1)/2-(j-i)];
    else return 0;
}

void Upper::display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i<=j) cout<<a[n*(i-1)-(i-2)*(i-1)/2-(j-i)]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}


/// using column major representation
class UpperCol
{
    private:
        int n;
        int *a;

    public:
        UpperCol(int n = 4)
        {
            this->n = n;
            a = new int[n*(n+1) / 2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~UpperCol() { delete [] a; };
};


void UpperCol::set(int i, int j, int x)
{
    if(i <= j)
    {
        a[j*(j-1)/2 + (i-1)] = x;
    }
}

int UpperCol::get(int i, int j)
{
    if(i <= j) return a[j*(j-1)/2 + (i-1)];
    else return 0;
}

void UpperCol::display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i<=j) cout<<a[j*(j-1)/2 + (i-1)]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    int n;
    cout<<"Enter the size of matrix: ";
    cin>>n;
    UpperCol l(n);
    cout<<"Enter the Element of the matrix: "<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int x;
            cin>>x;
            l.set(i,j,x);
        }
    }
    cout<<endl;
    cout<<endl;
    l.display();
    return 0;
}