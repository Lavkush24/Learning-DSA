#include<iostream>
using namespace std;

// Defining array 
struct array 
{
    int *A;
    int length;
    int size;
};

// Display array 
void display(struct array a, string str)
{
    cout<<str;
    for(int i=0; i<a.length; i++)
    {
        cout<<a.A[i]<<" ";
    }
    cout<<endl;
}


// Insert element in the array 
void insert(struct array &a,int n)
{
    cout<<"Enter element of the array : ";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.A[a.length] = x;
        a.length++;
    }
}

/* Finding missing elements in the array of sequence of elements */
// 1. single element in the sorted array
int missing(struct array a)
{
    int l = a.A[0];
    for(int i=1; i<a.length; i++)
    {
        if(a.A[i]-i != l)
        {
            return i+l;
        }
    }
    return -1;
}

// 2. Multiple missing values in the sequence
void multi_missing(struct array a)
{
    cout<<"Missing elements: ";
    int l = a.A[0];
    for(int i=1; i<a.length; i++)
    {
        if(a.A[i]-i != l)
        {
            while(l < a.A[i]-i)
            {
                cout<<l+i<<" ";
                l++;
            }
        }
    }
    cout<<endl;
}


//another method to find missing element from a sequence(here we need hash-table/bitset)
void miss(struct array a,int max)
{
    int arr[max] = {0};

    for(int i=0; i<a.length; i++)
    {
        arr[a.A[i]] = 1;
    }

    cout<<"Missing elements are: ";
    for(int i=1; i<max; i++)
    {
        if(arr[i] == 0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main() 
{
    struct array arr;
    int n;
    cout<<"Enter size of array : ";
    cin>>arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;
    cout<<"Enter number of elements: ";
    cin>>n;
    insert(arr,n);
    display(arr,"Element of the array : ");
    // cout<<"Missing element of sequence: "<<missing(arr)<<endl;
    // multi_missing(arr);
    miss(arr,10);
    return 0;
}