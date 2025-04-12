#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node * next;
}*first=NULL,*last=NULL;


void create(int x)
{
    struct node *n = new struct node;
    n->data = x;
    n->next = NULL;
    if(first == NULL) {
        first = last = n;
    }
    else {
        last->next = n;
        last = n;
    }
}


int deletion_first()
{
    struct node *p = first;
    int x = p->data;
    first = first->next;
    delete p;
    return x;
}

int deletion_index(int i)
{
      struct node *p=first,*q=NULL;
      int x;
      if(i == 1)
      { 
        first = first->next;
        x = p->data;
        delete p;
        return x;
      }

      while(i > 1 && p)  
      /* if i use p->next it stop one value before last so when we pass index larger 
      than index it remove last element and in case of p program execution is stop without any error */   
      {
        q = p;
        p = p->next;
        i--;
      }
      if(p){  /* this handle the termination of program in case of p */
          q->next = p->next;
          x = p->data;
          delete p;
          return x;
      }
      else 
      {
        return -1;
      }
}

void display(struct node *p)
{
    cout<<"Linked List : ";
    while(p != NULL) 
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
} 


int main() 
{
    int n;
    cout<<"Enter size of list: ";
    cin>>n;
    cout<<"Enter the element of list: ";
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        create(x);
    }
    display(first);
    cout<<"Deleted Element "<<deletion_first()<<endl;
    display(first);
    int i;
    cout<<"enter index to delete: ";
    cin>>i;
    cout<<"Deleted Element "<<deletion_index(i)<<endl;
    display(first);
    return 0;
}