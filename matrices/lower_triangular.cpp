#include<iostream>
using namespace std;

//using row major representation
class Lower
{
    private:
        int n;
        int *a;

    public:
        Lower(int n = 4)
        {
            this->n = n;
            a = new int[n*(n+1) / 2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~Lower() { delete [] a; };
};


void Lower::set(int i, int j, int x)
{
    if(i >= j)
    {
        a[i*(i-1) / 2  + (j-1)] = x;
    }
}

int Lower::get(int i, int j)
{
    if(i >= j) return a[i*(i-1) / 2 + (j-1)];
    else return 0;
}

void Lower::display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>=j) cout<<a[i*(i-1) / 2 + (j-1)]<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
    }
}


/// using column major representation
class LowerCol
{
    private:
        int n;
        int *a;

    public:
        LowerCol(int n = 4)
        {
            this->n = n;
            a = new int[n*(n+1) / 2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~LowerCol() { delete [] a; };
};


void LowerCol::set(int i, int j, int x)
{
    if(i >= j)
    {
        a[n*(j-1)-(j-2)*(j-1)/2+(i-j)] = x;
    }
}

int LowerCol::get(int i, int j)
{
    if(i >= j) return a[n*(j-1)-(j-2)*(j-1)/2+(i-j)];
    else return 0;
}

void LowerCol::display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>=j) cout<<a[n*(j-1)-(j-2)*(j-1)/2+(i-j)]<<" ";
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
    LowerCol l(n);
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