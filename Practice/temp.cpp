#include<iostream>
using namespace std;


int add(int a, int b) {
    static int s1;
    s1 = 7;
    s1++;
    cout<<s1<<endl;
    return a+b;
}

int main() {
    cout<<add(4,5)<<endl;
    // cout<<s1<<endl;
    cout<<add(5,5)<<endl;

    return 0;
}

