#include<iostream>
using namespace std;

struct arr 
{
    int *A;
    int length;
    int size;
};

void display(struct arr a)
{
    cout<<"Element of arr : ";
    for(int i=0; i<a.length; i++)
    {
        cout<<a.A[i]<<" ";
    }
    cout<<endl;
}

//for input arr element 
void inArray(struct arr *a)
{
    cout<<"Enter element of the arr: ";
    for(int i=0; i<a->length; i++)
    {
        cin>>a->A[i];
    }
}


/* Finding dublicate element in the arr and count them */

//new approach (for sorted arr) ,
void duplicated(struct arr a)
{
    cout<<"Duplicate element in arr : ";
    int d = 0;
    for(int i=0; i<a.length; i++)
    {
        if(a.A[i] == a.A[i+1]) 
        {
            if(a.A[i] != d)
            {
                d = a.A[i];
                cout<<d<<" ";
            }
        }
    }
    cout<<endl;
}

void count_duplicate(struct arr a)
{
    for(int i=0; i<a.length-1; i++)
    {
        if(a.A[i] == a.A[i+1])
        {
            int j = i+1;
            while(a.A[j] == a.A[i]) j++;
            cout<<a.A[i]<<" is appearing "<<j-i<<" times."<<endl;
            i = j-1;
        }
    }
}


//counting duplicate and finding in single iteration using (hash-table / bitset)
void duplicate2(struct arr a)
{
    int m = a.A[a.length-1] + 1;
    int b[m] = {0};
    //stroing result in the new arr 
    for(int i=0; i<a.length; i++)
    {
        b[a.A[i]]++;
    }

    //printing result
    for(int i=0; i<m; i++)
    {
        if(b[i] > 1)
        {
            cout<<i<<" is appearing "<<b[i]<<" times."<<endl;
        }
    }
}

//for unsorted arr
void duplicate(struct arr a)
{
    int c;
    for(int i=0; i<a.length-1; i++)
    {
        c = 1;
        for(int j=i+1; j<a.length; j++)
        {
            if(a.A[i] == a.A[j] && a.A[i] != -1)
            {
                c++;
                a.A[j] = -1;
            }
        }
        if(c > 1)
        {
            cout<<a.A[i]<<" is appear "<<c<<" times."<<endl;
        }
    }
}



//finding pair of element whose sum is eaqual sum 
void findPair(struct arr a, int sum)
{
    cout<<"Pair whose sum is equal to sum: ";
    for(int i=0; i<a.length-1; i++)
    {
        for(int j=i+1; j<a.length; j++)
        {
            if(a.A[i]+a.A[j] == sum)
            {
                cout<<"("<<a.A[i]<<","<<a.A[j]<<") , ";
            }
        }
    }
}

//same problem using hash-table/bitset
void find_pair(struct arr a, int maxx, int sum)
{
    cout<<"Pair whose sum is equal to sum: ";
    int arr[maxx] = {0};
    for(int i=0; i<a.length; i++)
    {
        int j = sum - a.A[i];
        arr[a.A[i]] = 1;

        if(arr[j] == 1 && j != a.A[i])
        {
            cout<<"("<<a.A[i]<<","<<j<<") ";
        }
    }
}


//finding pair in the sorted arr (increasing order)
void pair_sort(struct arr a, int sum)
{
    cout<<"Pair whose sum is equal to sum: ";
    int i=0; 
    int j=a.length-1;
    while(i < j)
    {
        int c = a.A[i]+a.A[j];
        if(c == sum)
        {
            cout<<"("<<a.A[i]<<","<<a.A[j]<<") ";
            i++;
            j--;
        }
        else if(c > sum)
        {
            j--;
        }
        else 
        {
            i++;
        }
    }
}


///finding min and  max in single scan 
void min_max(struct arr a)
{
    int min,max;
    min=max=a.A[0];

    for(int i=1; i<a.length; i++)
    {
        if(a.A[i] > max)
        {
            max = a.A[i];
        }
        else if(a.A[i] < min)
        {
            min = a.A[i];
        }
    }
    cout<<"Minimum is : "<<min<<" Maximum is : "<<max<<endl; 
}

int main() 
{
    struct arr arr;
    cout<<"Enter size of arr : ";
    cin>>arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;
    cout<<"Enter length: ";
    cin>>arr.length;
    inArray(&arr);
    
    // duplicated(arr);
    // count_duplicate(arr);
    // duplicate(arr);
    // pair_sort(arr,10);
    min_max(arr);
    return 0;
}