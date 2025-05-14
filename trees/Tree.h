#include<iostream>
#include<queue>
using namespace std;
#ifndef TREE_H
#define TREE_H


class node {
    public:
        int data;
        node * Lchild;
        node * Rchild;
};


class Tree {
    private:
        node *root;

    public:
        Tree() { root = NULL;};
        node* getRoot() { return root; }; 
        void create();
        void inorder(node *t);
        void inorderTraversal(node *t);
};

void Tree::create() {
    node * n = new node;
    queue<node *> q;
    cout<<"Enter the root node: ";
    cin>>n->data;
    n->Lchild = n->Rchild = NULL;
    root = n;
    q.push(n);
    
    while(!q.empty()) {
        node *temp = q.front();
        q.pop();
        int x;

        cout<<"Enter the left node "<<temp->data<<" :";
        cin>>x;
        if(x != -1) {
             n = new node;
             n->data = x;
             temp->Lchild = n;
             n->Lchild = n->Rchild = NULL;
             q.push(n);
        }

        cout<<"Enter the right node "<<temp->data<<" :";
        cin>>x;
        if(x != -1) {
             n = new node;
             n->data = x;
             temp->Rchild = n;
             n->Lchild = n->Rchild = NULL;
             q.push(n);
        }
    }
}

void Tree::inorder(node *t) {
    if(t==NULL) {
        return ;
    }
    else {
        inorder(t->Lchild);
        cout<<t->data<<" ";
        inorder(t->Rchild);
    }
}

void Tree::inorderTraversal(node *t) {
    inorder(t);
    cout<<endl;
}

#endif