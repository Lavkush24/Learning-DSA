#include<iostream>
#include"../mylibrary/Queue.h"
using namespace std;


int main()
{
    Queue<string> q ;
    q.enqueue("hello");
    q.enqueue("hi");
    q.enqueue("by");
    q.display();
    return 0;
}