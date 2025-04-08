#include<iostream>
using namespace std;

class Diagonal_matrix
{
    private:
        int n;
        int *arr;

    public:
        Diagonal_matrix(int n = 4)
        {
            this->n = n;
            arr = new int[n];
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
        ~Diagonal_matrix();
};

void Diagonal_matrix::set(int i,int j, int x)
{
    if(i == j)
        arr[i-1] = x;
}

int Diagonal_matrix::get(int i, int j)
{
    if(i == j) return arr[i-1];
    else return 0;
}

void Diagonal_matrix::display()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                cout<<arr[i]<<" ";
            }
            else 
            {
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

Diagonal_matrix::~Diagonal_matrix()
{
    delete []arr;
}



int main()
{
    Diagonal_matrix d;
    d.set(1,1,5);
    d.set(2,2,1);
    d.set(3,3,9);
    d.set(4,4,7);
    d.set(5,5,3);
    d.display();
    return 0;
}