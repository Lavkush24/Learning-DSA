#include<iostream>
using namespace std;


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

void print(int arr[],int s) {
    for(int i =0; i<s-1; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<arr[s-1]<<endl;
}

int main() {
    int arr[] = {8,5,7,3,2};
    int s = 5;

    insertion_sort(arr,s);

    print(arr,s);
    return 0;
}

