#include<iostream>
using namespace std;

struct array 
{
    int A[20];
    int length;
    int size;
};

//display 
void display(struct array arr)
{
    cout<<"Element of the array are: ";
    for(int i=0 ; i<arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

//reverse an array with the help of second array
void reverse(struct array *arr)
{
    int B[arr->length];
    for(int i=0; i<arr->length; i++)
    {
        B[i] = arr->A[arr->length - i-1];
    }
    for(int i=0; i<arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

//swap function
void swap(int *p,int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

//reverse using interchanging last and first element 
void reverse2(struct array *arr)
{
    int i=0, j=arr->length -1;
    while(i<=j)
    {
        swap(arr->A[i], arr->A[j]);
        i++;
        j--;
    }
}

//left shift
void left_shift(struct array *arr)
{
    for(int i=0; i<arr->length; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
}

void right_shift(struct array *arr)
{
    arr->length++;
    for(int i=arr->length-1; i>=0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
}

//rotation 
void left_rotate(struct array *arr)
{
    int x = arr->A[0];
    left_shift(arr);
    arr->length++;
    arr->A[arr->length-1] = x;
}

void right_rotate(struct array *arr)
{
    int x = arr->A[arr->length-1];
    right_shift(arr);
    arr->length--;
    arr->A[0] = x;
}


int main() 
{
    struct array arr = {{3,4,2,1,7,8},6,20};
    display(arr);
    cout<<"Reverse the array "<<endl;
    reverse(&arr);
    display(arr);
    reverse2(&arr);
    display(arr);
    left_shift(&arr);
    right_shift(&arr);
    display(arr);
    left_rotate(&arr);
    display(arr);
    left_rotate(&arr);
    display(arr);
    left_rotate(&arr);
    display(arr);
    right_rotate(&arr);
    display(arr);
    return 0;
}