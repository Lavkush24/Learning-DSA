#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node * next;
}*head; 

void create(int arr[], int size)
{
    node *n,*last;
    head = new node;
    head->data = arr[0];
    head->next = head;
    last = head;

    for(int i=1; i<size; i++)
    {
        n = new node;
        n->data = arr[i];
        n->next = last->next;
        last->next = n;
        last = n;
    }
}

void display(node *p)
{
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p != head);
    cout<<endl;
}

void Rdisplay(node *h)
{
    static int flag = 0;
    if(h != head || flag == 0)
    {
        flag = 1;
        h = h->next;
        Rdisplay(h->next);
        cout<<h->data<<" ";
    }
    flag = 0;
}

int length(node *p)
{
    int c=0;
    do
    {
        c++;
        p = p->next;
    }while(p!=head);
    return c;
}

void insert(int x,int i)
{
    node *p,*n = new node;
    n->data = x;
    if(i<0 || i>length(head)) 
    {
        return ;
    }
    if(i == 0)
    {
        if(head == NULL)
        {
            head = n;
            head->next = head;
        }
        else
        {
            p = head;
            while(p->next != head)
            {
                p = p->next;
            }
            p->next = n;
            n->next = head;
            head = n;
        }
    }
    else 
    {
        p = head;
        for(int j=1; j<i; j++)
        {
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
    }
    
}


int Delete(int pos)
{
    node *temp,*p;
    p = head;
    int x;
    if(pos < 1 || pos > length(head))
    {
        return -1;
    }
    if(pos == 1)
    {
        temp = head;
        while(p->next != head)
        {
            p = p->next;   
        }
        head = head->next;
        p->next = head;
        x = temp->data;
        delete temp;
        return x;
    }
    else
    {
        for(int i=0; i<pos-2; i++)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        x = temp->data;
        delete temp;
        return x;
    }
}

int main() 
{
    int arr[] = {34,56,67,23,12};
    create(arr,5);
    display(head);
    Rdisplay(head);
    cout<<endl;
    insert(33,2);
    display(head);
    cout<<Delete(7)<<endl;
    display(head);
    return 0;
}