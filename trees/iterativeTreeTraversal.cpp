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


//here there is an error in the storing the type casting 
void iterativePostorder(node *t) 
{
    stack<long int> st;
    long int temp;
    while(t != NULL || !st.empty()) 
    {
        if(t != NULL)
        {
            st.emplace((long int)t);
            t = t->Lchild;
        }
        else
        {
            temp = st.top();
            st.pop();
            if(temp > 0)
            {
                st.emplace(-temp);
                t = ((node*)temp)->Rchild;
            }
            else
            {
                cout<<((node*) (-1 * temp))->data<<" ";
                t = NULL;
            }

        }
    }
    cout<<endl;
}


//levelorder tarversal 
void levelorder(node* t) 
{
    queue<node *> q;
    cout<<t->data<<" ";
    q.push(t);
    while(!q.empty()) 
    {
        t = q.front();
        q.pop();
        if(t->Lchild) 
        {
            cout<<t->Lchild->data<<" ";
            q.push(t->Lchild);
        }
        if(t->Rchild)
        {
            cout<<t->Rchild->data<<" ";
            q.push(t->Rchild);
        }
    }
    cout<<endl;
}


//generate the tree from inorder and preorder traversal 
int searchInorder(int inArr[],int start, int end,int data) 
{
    for(int i=start; i<=end; i++) {
        if(inArr[i] == data) {
            return i;
        }
    }
    return -1;
}

node * generateFromTraversal(int *inorder, int *preorder, int start, int end) {
    static int preIndex = 0;

    if(start > end) {
        return nullptr;
    }

    node * n = new node();
    n->Lchild = n->Rchild = NULL;
    n->data = preorder[preIndex++];

    if( start == end) {
        return n;
    }

    int splitIndex = searchInorder(inorder, start, end,n->data);
    n->Lchild = generateFromTraversal(inorder, preorder, start, splitIndex-1);
    n->Rchild = generateFromTraversal(inorder,preorder,splitIndex+1,end);

    return n;
}


int height(node *t) 
{
    int x,y;
    if(t != NULL) {
        x = height(t->Lchild);
        y = height(t->Rchild);
        if(x > y) {
            return x+1;
        }
        else {
            return y+1;
        }
    }
    return 0;
}

int count(node *t) {
    if(t !=NULL){
        return count(t->Lchild) + count(t->Rchild) + 1;
    }
    return 0;
}

int leafNodes(node *t) {
    int x, y;
    if(t != NULL) {
        x = leafNodes(t->Lchild);
        y = leafNodes(t->Rchild);
        if((t->Lchild == NULL || t->Rchild == NULL) && !(t->Lchild == NULL && t->Rchild)) {
            return x+y+1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}

int main() 
{
    create();
    // preOrder(root);
    // cout<<endl;
    // iterativePreorder(root);
    // iterativePostorder(root);
    // levelorder(root);
    // int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    // int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
 
 
    // node *bt = generateFromTraversal(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    // preOrder(bt);

    cout<<count(root)<<endl;
    cout<<leafNodes(root)<<endl;
    return 0;
}


