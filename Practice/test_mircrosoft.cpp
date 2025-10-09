#include<iostream>
using namespace std;
#include<vector>


vector<int> threeSum(vector<int> arr,int size) {
    vector<int> res;
    
    for(int i=0; i<size-2; i++) {
        for(int j=i+1; j<size-1; j++) {
            for(int k=j+1; j<size; j++) {
                res.push_back(arr[i]+arr[j]+arr[k]);
            }
        }
    }
    return res;
}



int main() {
    int size;
    cin>>size;
    vector<int> arr(size);

    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    vector<int> res = threeSum(arr,size);

    for(int i=0; i<res.size(); i++) {
        if(res[i]%3 == 0) {
            cout<<res[i];
        }
    }
    cout<<endl;

    return 0;
}