#include<iostream>
using namespace std;



int main() 
{
    //creatign 2d array in the stack 
    int a[3][4] = {{2,3,4,4},{4,5,6,7},{1,3,5,6}};

    //creation of array inside stack and heap 
    int *b[4] ;
    b[0] = new int[4];
    b[1] = new int[4];
    b[2] = new int[4];


    ///creation of array inside heap only
    int **c;
    c = new int*[3];
    c[0] = new int[4];
    c[1] = new int[4];
    c[2] = new int[4];


    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {

            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    
}