#include<iostream>
using namespace std;

struct array
{
    int A[20];
    int size;
    int length;
};

//display element 
void display(struct array arr)
{
    int i;
    cout<<"Element of arrays are : ";
    for(i=0; i<arr.length; i++)
    {
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}


//append or add new element 
void append(struct array *arr, int x)
{
    arr->A[arr->length] = x;
    arr->length = arr->length + 1;
}


//insert an element at an index
void insert(struct array *arr, int index, int x)
{
    if(index >= 0 && index <= arr->length) {
        int i;
        for(i=arr->length; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length += 1;
    }else {
        cout<<"Invalid index"<<endl;
    }
}


//deleting element of array
void del(struct array *arr,int index)
{
    if(index >= arr->length || index < 0) {
        cout<<"invalid index"<<endl;
    }else{
        int i;
        for(i=index; i<arr->length; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}

//linear search in the array
int linear_search(struct array arr,int key)
{
    int i;
    for(i=0; i<arr.length-1; i++)
    {
        if(key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//improved linear search (transposition)
int advance_linear(struct array arr, int key)
{
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(key == arr.A[i])
        {
            swap(&arr.A[i], &arr.A[i-1]);
            return i-1;
        }
    }
    return -1;
}


//binary search
int binary_search(struct array arr, int key, int low, int high)
{
    while(low <= high)
    {
        int mid = (low+high) / 2;
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

//recursive binary
int recursive_binary(struct array arr,int key,int low ,int high)
{
    int mid;
    if(low <= high){
        mid = (low+high)/2;
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            return recursive_binary(arr,key,low,mid-1);
        }else
        {
            return recursive_binary(arr,key,mid+1,high);
        }
    }
    return -1;
}

//get operation in the array 
int get(struct array arr, int index)
{
    int i;
    if(index >= 0 && index < arr.length)
    {
        for(i=0; i<arr.length; i++)
        {
            if(index == i)
                return arr.A[i];
        }
    }
    return -1;
}

//set operation in the array (Replaces the value at indexes)
void set(struct array *arr,int index,int x)
{
    int i;
    if(index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
} 

//find average of the array
int avg(struct array arr)
{
    int i,average,sum=0;
    for(i=0; i<arr.length; i++)
    {
        sum += arr.A[i];
        average = sum/(arr.length);
    }
    return average;
}

//find maximum of the array
int max(struct array arr)
{
    int i,max = arr.A[0];
    for(i=1; i<arr.length; i++)
    {
        if(max < arr.A[i])
            max = arr.A[i];
    }
    return max;
}


//find minimum of the array
int min(struct array arr)
{
    int i,min = arr.A[0];
    for(i=1; i<arr.length; i++)
    {
        if(min > arr.A[i])
            min = arr.A[i];
    }
    return min;
}


int main()
{
    struct array arr = {{3444,326,568,88,99},20, 4};
    display(arr);
    cout<<"insert 104 in array"<<endl;
    append(&arr,104);
    append(&arr,450);
    display(arr);
    cout<<"insert 150 at index 5"<<endl;
    insert(&arr,5,150);
    display(arr);
    cout<<"Delete element from index 5"<<endl;
    del(&arr,5);
    display(arr);
    cout<<"Search for element(Linear search)"<<endl;
    cout<<"Index of key element : "<<advance_linear(arr,88)<<endl;
    display(arr);
    cout<<"Search for element(Binary search)"<<endl;
    cout<<"Index of key element : "<<binary_search(arr,104,0,arr.length)<<endl;
    cout<<"Search for element(Recursive Binary search)"<<endl;
    cout<<"Index of key element : "<<recursive_binary(arr,450,0,arr.length)<<endl;
    display(arr);
    cout<<"find element at index 4: "<<get(arr,4)<<endl;
    cout<<"Set index 4 to 134"<<endl;
    set(&arr,4,134);
    display(arr);
    cout<<"Average of arrays element: "<<avg(arr)<<endl;
    cout<<"Maximum of the array: "<<max(arr)<<endl;
    cout<<"Minimum of the array: "<<min(arr)<<endl;
    return 0;
}