#include<iostream>
using namespace std;

class queue
{
    public:
        int front;
        int rear;
        int size;
        int *a;
};


void enqueue(queue *q, int x)
{
    if(q->rear == q->size-1)
    {
        cout<<"queue underflow"<<endl;
        return;
    }
    else
    {
        q->rear++;
        q->a[q->rear] = x;
    }
}


void display(queue *q1,queue *q2,queue *q3) 
{
    int temp ;
    temp = q1->front + 1;
    while(temp <= q1->rear)
    {
        cout<<q1->a[temp]<<" ";
        temp++;
    }
    temp = q2->front + 1;
    while(temp <= q2->rear)
    {
        cout<<q2->a[temp]<<" ";
        temp++;
    }
    temp = q3->front + 1;
    while(temp <= q3->rear)
    {
        cout<<q3->a[temp]<<" ";
        temp++;
    }
    cout<<endl;
}


int main()
{
    queue *q1 = new queue;
    queue *q2 = new queue;
    queue *q3 = new queue;
    q1->rear = q2->rear = q3->rear = q1->front = q2->front = q3->front = -1;
    ;
    int s;
    cin>>s;
    q1->size  = q2->size = q3->size = s;
    q1->a = new int[q1->size];
    q2->a = new int[q2->size];
    q3->a = new int[q3->size];

    int x,p;
    while(1)
    {
        cout<<"enter the element and priority (x,p): "<<endl;
        cin>>x>>p;
        if(p == 1)
        {
            enqueue(q1,x);
        }
        else if(p == 2)
        {
            enqueue(q2,x);
        }
        else if(p == 3)
        {
            enqueue(q3,x);
        }
        display(q1,q2,q3);
    }

    return 0;
}
