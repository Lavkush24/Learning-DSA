#include<iostream>
using namespace std;


int binary_search(int arr[],int l,int h,int key) {
    if(l > h) {
        return -1;
    }

    int mid = (l+h)/2;

    if(arr[mid] == key) {
        return mid;
    }

    else if(arr[mid] > key) {
        return binary_search(arr,l,mid-1,key);
    }
    else {
        return binary_search(arr,mid+1,h,key);
    }
}


void input_array(int *a,int s) {
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<s; i++) {
        cin>>a[i];
    }
}


int * merging(int a[],int b[],int n,int m) {
    int *c = new int[n+m];
    int i = 0,j=0,k=0;
    while(i < n && j < m) {
        if(a[i] < a[j]) {
            c[k] = a[i];
            k++,i++;
        }
        else {
            c[k] = b[j];
            k++,j++;
        }
    }

    for(;i<n; i++) { c[k++] = a[i];}
    for(;j<m; j++) { c[k++] = b[j];} 
    return c;
}

void merging_single(int a[],int l,int m,int h) {
    int i =l,j=m+1;
    
    int *c = new int[h+1];
    int k =l;
    while(i <= m && j<=h) {
        if(a[i] < a[j]) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = a[j++];
        }
    }

    for(;i<=m; i++) { c[k++] = a[i];}
    for(;j<=h; j++) { c[k++] = a[j];} 

    for(int i=l; i<h+1; i++) {
        a[i] = c[i];
    }

    delete[] c;
}

int main() {
    cout<<"enter the array size: ";
    int s;
    cin>>s;
    int *arr = new int[s];
    input_array(arr,s);
    
    cout<<binary_search(arr,0,s,1)<<endl;
    delete[] arr;
    return 0;
}