#include<iostream>
using namespace std;


struct matrix
{
    int a[15];
    int n;
};

void set_diagonal(struct matrix &arr, int i, int j, int x)
{
    if(i == j)
    {
        arr.a[i-1] = x;
    }
}

int get_diagonal(struct matrix arr, int i, int j)
{
    if(i == j) return arr.a[i-1];
    else return 0;
}

void display(struct matrix arr)
{
    for(int i=0; i<arr.n; i++)
    {
        for(int j=0; j<arr.n; j++)
        {
            if(i == j)
            {
                cout<<arr.a[i]<<" ";
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
    struct matrix diag = {0};
    diag.n = 4;
    set_diagonal(diag, 1,1, 5);
    set_diagonal(diag, 2,2, 9);
    set_diagonal(diag, 3,3, 8);
    set_diagonal(diag, 4,4, 18);
    display(diag);
    cout<<get_diagonal(diag, 2,2)<<endl;
    return 0;
}