#include<iostream>
#include<vector>
using namespace std;


int minPlatform(vector<int> arrive, vector<int> depart) {
    int platform = 1,count = 1;
    int max = depart[0];

    int i = 1;
    while(i<arrive.size()) {
        if(arrive[i] < max && arrive[i] < depart[i-1]) {
            count++;
        }

        if(platform < count) {
            platform = count;
        }
        if(max < depart[i]) {
            max = depart[i];
            count = 1;
        }
        i++;
    }
    return platform;
}





/* RECURSION */


// print all the  subsequence for [1,2,3]

void subSeqence(int arr[],int size,int i,int ss[],int len) {

    if(i == size) {
        for(int j =0; j<len; j++) {
            cout<<ss[j];
        }
        cout<<endl;
        return ;
    }
    // if included 
    ss[len] = arr[i];
    subSeqence(arr,size,i+1,ss,len+1);

    //if not included
    subSeqence(arr,size,i+1,ss,len);
}



//print pattern like repalce ABC by 1 at laest one character

void pattern(string s,int i,string ss) {

    //base case
    if(i >= s.length()) {
        cout<<ss<<endl;
        return ;
    }
    string temp = ss;
    //If change to one
    pattern(s,i+1,ss+='1');

    //if not change 
    ss = temp;
    pattern(s,i+1,ss+=s[i]);
}


void pattern2(string s,int i,string ss) {

    //base case
    if(i >= s.length()) {
        cout<<ss<<endl;
        return ;
    }
    string temp = ss;
    //If change to one
    pattern2(s,i+1,ss+=s[i]);

    //if not change 
    ss = temp;
    pattern2(s,i+1,ss);
}


int main() {
    // cout<<minPlatform({100,300,600,700,800,820,820},{500,400,800,720,830,900})<<endl;
    // cout<<minPlatform({1000,935,1100},{1200,1240,1130})<<endl;

    // int ss[10];
    // int arr[3] = {1,2,3};
    // subSeqence(arr,3,0,ss,0);
    string s = "";
    pattern2("abc",0,s);
    return 0;
}