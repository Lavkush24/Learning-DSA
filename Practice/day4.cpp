#include<iostream>
using namespace std;
#include<vector>
#include<stack>



class Mystack {
    vector<int> s;
    public: int top = -1;

    public: 
        Mystack();
        void push(int data);
        int pop();
        bool isEmpty();
        void display();
};

Mystack::Mystack() {};

void Mystack::push(int data) {
    s.push_back(data);
    top++;
}

int Mystack::pop() {
    int temp;
    try {
        if(isEmpty()) {
            throw -1;
        }
        temp = s[top];
        s.pop_back();
        top--;
    }
    catch (int e) {
        cout<<"Stack is Empty: "<<e<<endl;
    }
    return temp;
}

bool Mystack::isEmpty() {
    return top == -1 ? true : false;
}

void Mystack::display() {
    for(int i =0; i<s.size(); i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}



/* two sum input array */


int main() {
    stack<int> ss;
    Mystack *s = new Mystack();

    s->pop();
    s->push(45);
    s->push(67);
    s->display();
    cout<<s->pop()<<endl;
    s->display();

    return 0;
}


