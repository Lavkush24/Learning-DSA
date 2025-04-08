#include<iostream>
using namespace std;

class Symmetric
{
    private:
        int *a;
        int n;

    public:
        Symmetric(int n = 4)
        {
            this->n = n;
            a = new int[n*(n+1) / 2];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~Symmetric() { delete []a ; };
};

void Symmetric::set(int i,int j,int x)
{
    if(i>=j)
    {
        a[i*(i-1)/2 + (j-1)] = x;
    }
}

int Symmetric::get(int i,int j)
{
    if(i>=j)
    {
        return a[i*(i-1)/2 + (j-1)];
    }
    else
    {
        return 0;
    }
}

void Symmetric::display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>=j)
            {
                cout<<a[i*(i-1)/2 + (j-1)]<<" ";
            }
            else 
            {
                cout<<a[j*(j-1)/2 + (i-1)]<<" ";
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
    Symmetric s(n);
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