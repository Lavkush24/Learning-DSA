#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node 
{
    public:
        int data;
        node *Lchild;
        node *Rchild;
}*root=NULL;


void create() 
{
    node *n;
    queue<node *> q;
    int x;
    n = new node;
    cout<<"Enter root node: ";
    cin>>n->data;
    root = n;
    root->Lchild = root->Rchild = NULL;
    q.push(root);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout<<"Enter the left child of "<<temp->data<<": ";
        cin>>x;
        if(x != -1)
        {
            n = new node;
            n->data = x;
            n->Lchild = n->Rchild = NULL;
            temp->Lchild = n;
            q.push(n);
        }
        cout<<"Enter the right child of "<<temp->data<<": ";
        cin>>x;
        if(x != -1)
        {
            n = new node;
            n->data = x;
            n->Lchild = n->Rchild = NULL;
            temp->Rchild = n;
            q.push(n);
        }
    }
} 

void preOrder(node *p)
{
    if(!p)
    {
        return ;
    }
    else
    {
        cout<<p->data<<" ";
        preOrder(p->Lchild);
        preOrder(p->Rchild);
    }
}


//iterative preorder
void iterativePreorder(node *t)
{
    stack<node*> st;
    while(t != NULL || !st.empty()) 
    {
        if(t != NULL)
        {
            cout<<t->data<<" ";
            st.push(t);
            t = t->Lchild;
        }
        else
        {
            node *temp = st.top();
            st.pop();
            t = temp->Rchild;
        }
    }
    cout<<endl;
}

void iterativeInorder(node *t) 
{
    stack<node*> st;
    while(t != NULL || !st.empty()) 
    {
        if(t != NULL)
        {
            st.push(t);
            t = t->Lchild;
        }
        else
        {
            node *temp = st.top();
            st.pop();
            cout<<t->data<<" ";
            t = temp->Rchild;
        }
    }
    cout<<endl;
}

void iterativePostorder(node *t) 
{
    stack<node*> st;
    long int temp;
    while(t != NULL || !st.empty()) 
    {
        if(t != NULL)
        {
            st.push(t);
            t = t->Lchild;
        }
        else
        {
            node *p = st.top();
            temp = (long)st.top();
            st.pop();
            if(temp > 0)
            {
                st.push((node *)(-temp));
                t = p->Rchild;
            }
            else
            {
                cout<<((node*)temp)->data<<" ";
                t = NULL;
            }

        }
    }
    cout<<endl;
}

int main() 
{
    create();
    preOrder(root);
    cout<<endl;
    iterativePreorder(root);
    iterativePostorder(root);
    return 0;
}


