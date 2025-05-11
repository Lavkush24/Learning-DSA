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

void postorder(node *p) 
{
    if(!p)
    {
        return ;
    }
    postorder(p->Lchild);
    postorder(p->Rchild);
    cout<<p->data<<" ";
}

void inorder(node *p) 
{
    if(!p)
    {
        return ;
    }
    inorder(p->Lchild);
    cout<<p->data<<" ";
    inorder(p->Rchild);
}

void leveorder(node *p) 
{
    queue<node*> q;
    node *temp;
    cout<<p->data<<" ";
    q.push(p);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->Lchild)
        {
            cout<<temp->Lchild->data<<" ";
            q.push(temp->Lchild);
        }
        if(temp->Rchild)
        {
            cout<<temp->Rchild->data<<" ";
            q.push(temp->Rchild);
        }
    }
}

int main()
{
    create();
    cout<<"Preorder: ";
    preorder(root);
    cout<<"Postorder: ";
    postorder(root);
    cout<<"Inorder: ";
    inorder(root);
    cout<<"Level order";
    leveorder(root);
    cout<<endl;
    return 0;
}