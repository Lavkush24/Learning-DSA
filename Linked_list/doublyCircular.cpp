#include<iostream>
using namespace std;

// class node 
// {
//     public:
//         int data;
//         node *prev;
//         node *next;
// }*head;

// void create(int arr[],int size)
// {
//     node *n,*last;
//     head = new node;
//     head->data = arr[0];
//     head->prev = head->next = head;
//     last = head;
//     for(int i=1; i<size; i++)
//     {
//         n = new node;
//         n->data = arr[i];
//         n->next = head;
//         n->prev = last;
//         last->next = n;
//         head->prev = n;
//         last = n;
//     }
// }

// void display(node *h)
// {
//     do
//     {
//         cout<<h->data<<" ";
//         h = h->next;
//     }while(h != head);
//     cout<<endl;
// }

// int length(node *h)
// {
//     int x = 0;
//     do
//     {
//         x++;
//         h = h->next;
//     } while (h != head);
//     return x;
// }

// void insert(int x, int pos)
// {
//     node *p,*n = new node;
//     n->data = x;
//     p = head;
//     if(pos < 1 || pos > length(head)+1)
//     {
//         return ;
//     }
//     if(pos == 1)
//     {
//         if(head == NULL)
//         {
//             head = n;
//             head->next = head->prev = head;
//         }
//         else 
//         {
//             n->next = head;
//             n->prev = head->prev;
//             head->prev->next = n;
//             head->prev = n;
//             head = n;
//         }
//     }
//     else 
//     {
//         for(int i=1; i<pos-1; i++)
//         {
//             p = p->next;
//         }
//         n->next = p->next;
//         n->prev = p;
//         p->next->prev = n;
//         p->next = n;
//     }
// }

// int Delete(int pos)
// {
//     node *temp,*p;
//     temp = head;
//     int x;
//     p = head;
//     if(pos < 1 || pos > length(head))
//     {
//         return -1;
//     }
//     if(pos == 1)
//     {
//         if(head == NULL)
//         {
//             x = head->data;
//             head = NULL;
//             return x;
//         }
//         else
//         {
//             temp = head;
//             head = head->next;
//             head->prev = temp->prev;
//             temp->prev->next = head;
//             x = temp->data;
//             delete temp;
//             return x;
//         }
//     }
//     else
//     {
//         for(int i=1; i<pos-1; i++)
//         {
//             p = p->next;
//         }
//         temp = p->next;
//         p->next = temp->next;
//         temp->next->prev = p;
//         x = temp->data;
//         delete temp;
//         return x;
//     }
// }



//class for doubly circular

class node 
{
    public:
        int data;
        node *next;
        node *prev;
    
        node(int x)
        {
            data = x;
            next = prev = NULL;
        }
};


class list
{
    private:
        node *head;
    
    public:
        list();
        list(int arr[],int size);
        void insert(int x,int pos);
        int remove(int pos);
        void display();
        int length();
        ~list();
};

list::list(int arr[], int size)
{
    node *last,*n = new node(arr[0]);
    last = head = n;
    head->next = head->prev = head;

    for(int i=1; i<size; i++)
    {
        n = new node(arr[i]);
        n->next = head;
        n->prev = last;
        last->next = n;
        head->prev = n;
        last = n;
    }
}

int list::length()
{
    int l=0;
    node *temp = head;
    do
    {
        l++;
        temp = temp->next;
    } while (temp != head);
    return l;
}

void list::insert(int x,int pos)
{
    node *temp,*n = new node(x);
    int l=0;
    temp = head;
    do
    {
        l++;
        temp = temp->next;
    } while (temp != head);

    if(pos < 1 || pos > l)
    {
        cout<<"Not a valid position"<<endl;
        return ;
    }
    if(pos == 1)
    {
        n->next = head;
        n->prev = head->prev;
        head->prev->next = n;
        head = n;
    }
    else if(head == NULL)
    {
        head = temp = n;
        head->next = head->prev = head;
        return ;
    }
    else
    {
        temp = head;
        while(pos != 2)
        {
            temp = temp->next;
            pos--;
        }
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }
}

int list::remove(int pos)
{
    node *temp,*p;
    temp = head;
    int x,l=0;
    p = head;

    do
    {
        l++;
        temp = temp->next;
    } while (temp != head);

    if(pos < 1 || pos > l)
    {
        return -1;
    }
    if(pos == 1)
    {
        if(head == NULL)
        {
            x = head->data;
            head = NULL;
            return x;
        }
        else
        {
            temp = head;
            head = head->next;
            head->prev = temp->prev;
            temp->prev->next = head;
            x = temp->data;
            delete temp;
            return x;
        }
    }
    else
    {
        for(int i=1; i<pos-1; i++)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        temp->next->prev = p;
        x = temp->data;
        delete temp;
        return x;
    }
}

void list::display()
{
    node *temp;
    temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}

int main()
{
    // int arr[] = {45,23,67,89,12};
    // create(arr,5);
    // display(head);
    // while(1)
    // {
    //     int pos;
    //     cin>>pos;
    //     Delete(pos);
    //     display(head);
    // }
    // insert(233,3);
    // display(head);

    int arr[] = {4,5,6,7};
    list *l = new list(arr,4);

    l->display();
    l->insert(45,0);
    l->display();
    l->remove(5);
    l->display();
    return 0;
}