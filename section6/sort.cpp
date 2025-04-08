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

//inserting an element in the sorted array
void insert_(struct array *arr, int key)
{
    int i = arr->length-1;
    if(arr->length == arr->size)
        return ;
    while(i >= 0 && arr->A[i] > key)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = key;
    arr->length++;
} 

//checking array is sorted or not
bool check_(struct array arr)
{
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i] > arr.A[i+1])
            return false;
    }
    return true;
}

//swap function
void swap(int *p,int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

//-ve number on the left side
void negative_left(struct array *arr)
{
    int j=0;
    for(int i=0; i<arr->length; i++)
    {
        if(arr->A[i] < 0)
        {
            swap(&arr->A[i],&arr->A[j]);
            j++;
        }
    }
}

//another approach
void negative_(struct array *arr)
{
    int i=0,j=arr->length-1;
    while(i < j)
    {
        while(arr->A[i] < 0){ i++; };
        while(arr->A[j] >= 0){ j--; };
        if(i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

//merging two arrays 
 struct array * merge(struct array *a, struct array *b)
 {
    struct array *c = new struct array;
    c->length = 0;
    int i=0,j=0;
    while(i < a->length && j < b->length)
    {
        if(a->A[i] <= b->A[j])
        {
            c->A[c->length++] = a->A[i++]; 
        }
        else{
            c->A[c->length++] = b->A[j++];
        }
    }

    for(; i< a->length; i++)
    {
        c->A[c->length++] = a->A[i];
    }

    for(; j< b->length; j++)
    {
        c->A[c->length++] = b->A[j];
    }

    return c;
 }

int main() 
{
    struct array arr = {{3,6,8,9,23,45,67},7,20};
    struct array a = {{4,5,8,9,14},5,20};
    // display(arr);
    // insert_(&arr,799);
    // display(arr);
    // cout<<check_(arr)<<endl;

    // //-ve number
    // display(a);
    // negative_left(&a);
    // display(a);
    // negative_(&a);
    // display(a);

    struct array *c ;
    c = merge(&a,&arr);
    display(*c);
    return 0;
}