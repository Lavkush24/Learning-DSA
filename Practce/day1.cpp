#include<iostream>
#include<vector>
using namespace std;


// find the minimum swap in the array to place all the one at one place 
// [0,1,0,1,1,0,0,1,0]

int count(vector<int>& arr,int c,int s,int n) {
    int count = 0;
    for(int i =s; i<n; i++) {
        if(arr[i] == c) {
            count++;
        }
    }
    return count;
}

int minSwap(vector<int> arr) {
    int window = count(arr,1,0,arr.size());
    int zeroCount = 23859;
    int i =0 , j = window;

    while(j < arr.size()) {
        int k = count(arr,0,i,i+window);
        if(k < zeroCount) {
            zeroCount = k;
        }
        i++,j++;
    }

    return zeroCount; 
} 


vector<int> takeInputarr() {
    int s;
    cout<<"Enter the size of array: ";
    cin>>s;
    vector<int> arr(s);
    cout<<"Enter the element of the array: "<<endl;
    for(int i=0; i<s; i++) {
        cin>>arr[i];
    }

    return arr;
}




///using sliding window  (combine all one's together)
int slideSwapCount(vector<int> arr) {
    int s=0,e=0;
    int n = arr.size();
    
    int countzero = 0;
    for(int i = 0; i<n; i++) {
        if(arr[i] == 1) {
            e++;
        }
    }   
     
    for(int i=s; i<e; i++) {
        if(arr[i] == 0) {
            countzero++;
        }
    }
    
    int min = countzero;
    while(s < n) {
        if(arr[s] == 0 && arr[e] == 1) {
            countzero--;
        }else if(arr[s] == 1 && arr[e] == 0) {
            countzero++;
        }

        if(countzero < min) {
            min = countzero;
        }
        s++;
        e = (e+1)%n;
    }
    return min;
}

int main() {

    cout<<slideSwapCount(takeInputarr())<<endl;
    return 0;
}

