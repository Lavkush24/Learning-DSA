#include<iostream>
#include<queue>
using namespace std;

class node 
{
    public:
        int data;
        node *Lchild;
        node *Rchild;
}*root = NULL;

void create()
{
    node *p, *n;
    queue<node *> q;
    int x;
    cout<<"Enter root node: ";
    cin>>x;
    root = new node;
    root->data = x;
    root->Lchild = root->Rchild = NULL;
    q.push(root);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        cout<<"Enter left child "<<p->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            n = new node;
            n->data = x;
            n->Lchild = n->Rchild = NULL;
            p->Lchild = n;
            q.push(n);
        }
        
        cout<<"Enter right child "<<p->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            n = new node;
            n->data = x;
            n->Lchild = n->Rchild = NULL;
            p->Rchild = n;
            q.push(n);
        }
    }
}


void preorder(node *p) 
{
    if(!p)
    {
        return ;
    }
    cout<<p->data<<" ";
    preorder(p->Lchild);
    preorder(p->Rchild);
}

int main()
{
    create();
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    return 0;
}