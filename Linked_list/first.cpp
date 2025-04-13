#include<iostream>
#include<climits>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL;

void create(int a[], int size) 
{
    struct node *n,*last;
    first = new struct node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    for(int i=1; i<size; i++)
    {
        n = new struct node;
        n->data = a[i];
        n->next = NULL;
        last->next = n;
        last = n;
    }
}

void display(struct node *temp)
{
    cout<<"Linked list"<<endl;
    while(temp != NULL)
    {
        if(temp->next != NULL){
            cout<<temp->data<<"->";
        }
        else
        {
            cout<<temp->data;
        }
        temp = temp->next;
    }
    cout<<endl;
}


void display_recursive(struct node *p)
{
    if(p == NULL) 
    {
        return ;
    }
    display_recursive(p->next);
    cout<<p->data<<" ";
}


int count_nodes(struct node *p)
{
    int c=0;
    while(p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int Rcount(struct node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else 
    {
        return Rcount(p->next)+1;
    }
}

int sum(struct node *p)
{
    int sum =0;
    while(p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Rsum(struct node *p)
{
    if(p == NULL)
    {
        return 0;
    }
    else
    {
        return Rsum(p->next)+p->data;
    }
}

int RRsum(struct node *p)
{
    int sum =0;
    if(p == NULL)
    {
        return sum;
    }
    else
    {
        sum = RRsum(p->next);
        return sum+p->data;
    }
}


int max(struct node *p)
{
    int max = INT16_MIN;
    while(p!= NULL)
    {
        if(max < p->data){
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int Rmax(struct node *p)
{
    int x = 0;
    if(p == NULL)
    {
        return INT16_MIN;
    }
    else 
    {
        x = Rmax(p->next);
        return x>p->data?x:p->data;
    }
}

struct node* search(struct node *p,int key)
{
    while(p != NULL)
    {
        if(key == p->data)
            return p;
        p=p->next;
    }
    return NULL;
}

struct node* Rsearch(struct node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return Rsearch(p->next,key);
}

struct node* Imsearch(struct node *p, int key)
{
    struct node *q=NULL;
    while(p!= NULL)
    {
        if(key == p->data && q != NULL)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    int a[] = {144,5,8,2,9,20};
    create(a,6);
    display(first);
    display_recursive(first);
    cout<<"Number of nodes : "<<count_nodes(first)<<endl;
    cout<<"Number of nodes : "<<Rcount(first)<<endl;
    cout<<"Sum of elements: "<<sum(first)<<endl;
    cout<<"Sum of elements: "<<Rsum(first)<<endl;
    cout<<"Sum of elements: "<<RRsum(first)<<endl;
    cout<<"Maximum element : "<<max(first)<<endl;
    cout<<"Maximum element : "<<Rmax(first)<<endl;
    cout<<"search of element: "<<search(first,8)<<endl;
    cout<<"search of element: "<<Rsearch(first,8)<<endl;
    cout<<"search of element: "<<Imsearch(first,8)<<endl;
    cout<<"search of element: "<<Imsearch(first,5)<<endl;
    display(first);
    return 0;
}
