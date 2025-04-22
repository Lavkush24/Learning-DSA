#include<iostream>
using namespace std;

//Implementaion  circular queue using arrays 
 

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
    if((q->rear+1)%q->size == q->front)
    {
        cout<<"queue overflow"<<endl;
        return;
    }
    else
    {
        q->rear = (q->rear+1) % q->size;
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
        q->front = (q->front+1)%q->size;
        x = q->a[q->front];
    }
    return x;
}

void display(queue *q)
{
    cout<<"Queue : ";
    int i = q->front + 1;
    do 
    {
        cout<<q->a[i]<<" ";
        i = (i+1) % q->size;
    }while(i != (q->rear+1)%q->size);
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
    display(q);
    cout<<dequeue(q)<<endl;
    enqueue(q,34);
    enqueue(q,12);
    display(q);
    return 0;
}

