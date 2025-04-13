#include<iostream>
#include<climits>
using namespace std;

class node 
{
    public:
        int data;
        node *next;
};

class list 
{
    private:
        node *first,*last;

    public:
        list() { first = NULL; };
        list(int arr[], int size);
        ~list();
        node *getFirst() { return first; };
        void display();
        void Rdisplay(node *p);
        int length();
        void create(int x);
        void insert(int x,int i);
        int sum();
        int max();
        int min();
        bool search(int x);
        int remove(int i);
};


list::list(int arr[],int size)
{
    node *last,*n;
    first = new node;
    first->data = arr[0];
    first->next = NULL;
    last = first;
    for(int i=1; i<size; i++)
    {
        n = new node;
        n->data = arr[i];
        last->next = n;
        last = n;
    }
}

void list::display()
{
    node *p = first;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void list::Rdisplay(node *p)
{
    if(p)
    {
        Rdisplay(p->next);
        cout<<p->data<<" ";
    }
    else 
    {
        return ;
    }
}

int list::length()
{
    node *p = first;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

void list::create(int x)
{
    node *n = new node;
    n->data = x;
    n->next = NULL;
    if(first == NULL)
    {
        first = last = n;
    }
    else 
    {
        last->next = n;
        last = n;
    }
}

void list::insert(int x,int i)
{
    node *p=first,*n = new node;
    n->data = x;
    n->next = NULL;

    if(first == NULL)
    {
        first = n;
        return ;
    }
    if(i < 0  || i > length()+1)
    {
        return ;
    }
    else if(i == 0)
    {
        n->next = first;
        first = n;
        return ;
    }
    for(int j=1; j<i-1; j++)
    {
        p = p->next;
    }
    n->next = p->next;
    p->next = n;
    
}

int list::sum()
{
    node *p = first;
    int sum = 0;
    while(p!=NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int list::max()
{
    int max = INT_MIN;
    node *p = first;
    while(p!=NULL)
    {
        if(max < p->data)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int list::min()
{
    int min = INT_MAX;
    node *p = first;
    while(p!=NULL)
    {
        if(p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

bool list::search(int x)
{
    node *p = first;
    while(p!=NULL)
    {
        if(p->data == x)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

int list::remove(int i)
{
    node *temp=NULL,*p = first;
    int x;
    if(p == NULL)
    {
        return -1;
    }
    if(i == 1)
    {
        temp = first;
        first = first->next;
        x = temp->data;
        delete temp;
        return x;
    }

    if(i < 1 || i>length())
    {
        return -1;
    }

    while(i > 2 && p)
    {
        p = p->next;
        i--;
    }
    temp = p->next;
    p->next = temp->next;
    x = temp->data;
    delete temp;
    return x;
}

list::~list()
{
    node *p = first;
    while(first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}



int main()
{
    list *l = new list();
    l->create(4);
    l->create(5);
    l->create(6);
    l->insert(3,3);
    l->display();
    cout<<"Sum of elements: "<<l->sum()<<endl;
    cout<<"Number of elements: "<<l->length()<<endl;
    cout<<"Maximum element: "<<l->max()<<endl;
    cout<<"Minimum element: "<<l->min()<<endl;
    cout<<"search for 4: "<<l->search(3)<<endl;
    cout<<"removed element: "<<l->remove(3)<<endl;
    l->display();
    l->Rdisplay(l->getFirst());
    cout<<endl;
    return 0;
}
