#include<iostream>
using namespace std;
#include "Tree.h"
#include<stack>
#include<climits>


node* inOrderPredecessor(node *c) {
    while(c &&  c->Rchild != NULL) {
        c = c->Rchild;
    }
    return c;
}

node* inOrderSuccessor(node *c) {
    while(c && c->Lchild != NULL) {
        c = c->Lchild;
    }
    return c;
}

int height(node *c) {
    int x,y;
    if(c != NULL) {
        x = height(c->Lchild);
        y = height(c->Rchild);
        if(x > y) {
            return x+1;
        }else {
            return y+1;
        }
    }
    return 0;
}

node *deleteNode(node *p,int key) {
    node *temp;
    if(p == NULL) {
        return NULL;
    }
    

    if(key < p->data) {
        p->Lchild = deleteNode(p->Lchild,key);
    }
    else if(key > p->data){
        p->Rchild = deleteNode(p->Rchild,key);
    }
    else 
    {
        if(p->Lchild == NULL && p->Rchild == NULL) {
            delete p;
            return NULL;
        }

        if(height(p->Lchild) > height(p->Rchild)) {
            temp = inOrderPredecessor(p->Lchild);
            p->data = temp->data;
            p->Lchild = deleteNode(p->Lchild,temp->data);
        }
        else {
            temp = inOrderSuccessor(p->Rchild);
            p->data = temp->data;
            p->Rchild = deleteNode(p->Rchild,temp->data);
        }
    }
    return p;
} 

 

void generateFromPreorder(int pre[], int n,node* &root) {
    stack<node *> st;
    int i=0; 
    node *temp,*c;
    if( root == NULL)
        root = new node;
        
    root->data = pre[i++];
    root->Lchild = root->Rchild = NULL;
    c = root;

    while(i < n) {
        temp = new node;
        temp->Lchild = temp->Rchild = NULL;
        
        if(c->data > pre[i]) {
            temp->data = pre[i++];
            c->Lchild = temp;
            st.push(c);
            c = temp;
        }
        else 
        {
            int d;
            if(st.empty()) {
                d = INT_MAX;
            }
            else {
                d = (st.top())->data;
            }
            
            if(pre[i] > c->data && pre[i] < d) {
                temp->data = pre[i++];
                c->Rchild = temp;
                c = temp;
            }
            else {
                c = st.top();
                st.pop();
            }
        }
    }
}


int main() {
    Tree t;
    // t.create();
    // t.inorderTraversal(t.getRoot());
    // deleteNode(t.getRoot(),45);
    // t.inorderTraversal(t.getRoot());
    node *root = NULL;
    int pre[] = {30,20,10,15,25,40,50,45};
    generateFromPreorder(pre,8,root);
    t.inorderTraversal(root);
    return 0;
}