#include<iostream>
using namespace std;

//Implementaion using arrays 
 

/* using double pointer */
class queue 
{
    public:
        int size;
        int *a; 
        int rear; 
        int front;
};


void enqueue(queue *q, int x) 
{
    if(q->rear == q->size-1)
    {
        cout<<"queue oveflow"<<endl;
        return;
    }
    else
    {
        q->rear++;
        q->a[q->rear] = x; 
    }
}

int dequeue(queue *q)
{
    int x;
    if(q->rear == q->front)
    {
        cout<<"queue underflow";
        return -1;
        cout<<endl;
    }
    else
    {
        q->front++;
        x = q->a[q->front];
    }
    return x;
}

void display(queue *q)
{
    cout<<"Queue : ";
    while(q->front != q->rear)
    {
        q->front++;
        cout<<q->a[q->front]<<" ";
    }
    cout<<endl;
}

int main() 
{
    queue *q;
    int s ;
    cin>>s;
    q->size = s;
    q->a = new int[q->size];
    q->rear = q->front = -1;
    
    enqueue(q,40);
    enqueue(q,56);
    enqueue(q,45);
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
    display(q);
    return 0;
}

