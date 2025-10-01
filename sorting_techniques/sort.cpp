#include<iostream>
using namespace std;
#include<climits>


void bubble_sort(int arr[],int s) {
    int flag;
    for(int i=0; i<s-1; i++){
        flag = 0;
        for(int j=0; j<s-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag=1;
            }
        }
        if(flag == 0) break;
    }
}

void insertion_sort(int arr[],int s) {
    for(int i=1; i<s; i++) {
        int j = i-1;
        int x = arr[i];
        while(j>-1 && x < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x; 
    }
}

void selection_sort(int arr[],int s) {
    for(int i=0; i<s-1; i++) {
        int k ,j;
        k = j = i; 
        while(j < s) {
            if(arr[j] < arr[k]) {
                k = j;
            }
            j++;
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a  = *b;
    *b = temp;
}

int partition(int arr[],int l, int h) {
    int pivot = arr[l];
    int i=l, j=h;

    do {
        do { i++; } while(arr[i] <= pivot);
        do { j--; } while(arr[j] > pivot);

        if(i < j) swap(&arr[i], &arr[j]);
    }while(i < j);

    swap(&arr[j],&arr[l]);
    return j;
}

void quick_sort(int arr[], int l, int h) {
    if(l<h) {
        int p = partition(arr,l,h);
        quick_sort(arr,l,p);
        quick_sort(arr,p+1,h);
    }
}


void print(int arr[],int s) {
    for(int i =0; i<s-1; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<arr[s-1]<<endl;
}

int main() {
    int arr[] = {8,5,7,3,2};
    int s = 5;

    quick_sort(arr,0,5);

    print(arr,s);
    return 0;
}

