#include<iostream>
using namespace std;


//dynamic array
struct arrayADT
{
    int *a;
    int size;
    int length;
};

//static array
struct array
{
    int a[20];
    int size;
    int length;
};


void display(struct arrayADT arr)
{
    int i;
    cout<<"Element of arrays are: ";
    for(i=0; i<arr.length; i++)
    {
        cout<<arr.a[i]<<" ";
    }
}

void display(struct array arr)
{
    int i;
    cout<<"Element of arrays are: ";
    for(i=0; i<arr.length; i++)
    {
        cout<<arr.a[i]<<" ";
    }
}


int main() 
{
    //intialization of static array
    struct array ar = {{3,4,5,6,8},20,5};
    cout<<"Element of dyanamic array"<<endl;
    display(ar);
    cout<<endl;

    //intialization of dyanmic array
    struct arrayADT arr ;
    cout<<"Enter size of an array: ";
    cin>>arr.size; 
    arr.a = new int[arr.size];
    arr.length = 0;

    int n;
    cout<<"Enter number of element of arrays: ";
    cin>>n;
    cout<<"Enter all element of array: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr.a[i];
    }
    arr.length = n;

    //for display using fucntion 
    display(arr);

    return 0;
}
