#include<iostream>
using namespace std;
#include "Tree.h"


bool RsearchTree(node* t,int key) {
    if(t == NULL) {
        return 0;
    }
    else if(key == t->data) {
        return 1;
    }
    else if(key < t->data) {
        return RsearchTree(t->Lchild,key);
    }
    else {
        return RsearchTree(t->Rchild,key);
    }
}


bool iterativeSearch(node *t, int key) {
    while(t != NULL) {
        if(key == t->data) {
            return 1;
        }
        else if(key < t->data) {
            t = t->Lchild;
        }
        else {
            t = t->Rchild;
        }
    }
    return 0;
}


void insert(node *p,int key) {
    node *t = NULL;
    while(p != NULL) {
        t = p;
        if(p->data == key ) {
            return ;
        }
        else if(p->data > key) {
            p = p->Lchild;
        }
        else {
            p = p->Rchild;
        }
    }

    node *n = new node;
    n->data = key;
    n->Lchild = n->Rchild = NULL;
    if(key < t->data) {
        t->Lchild = n;
    }
    else {
        t->Rchild = n;
    }
}


node* createByInsert(node *p, int key) {
    node *n;

    if(p == NULL) {
        n = new node;
        n->data = key ;
        n->Lchild = n->Rchild = NULL;
        return n;
    }
    if(key < p->data) {
        p->Lchild = createByInsert(p->Lchild,key);
    }
    else {
        p->Rchild = createByInsert(p->Rchild,key);
    }
    return p;
}


void inorder(node *p) {
    if(!p) {
        return ;
    }
    else {
        inorder(p->Lchild);
        cout<<p->data<<" ";
        inorder(p->Rchild);
    }
}

 
int main() {
    Tree t;
    // t.create();
    // t.inorderTraversal(t.getRoot());
    // cout<<RsearchTree(t.getRoot(),12)<<endl;
    // cout<<iterativeSearch(t.getRoot(),34)<<endl;
    // insert(t.getRoot(), 56);

    
    node *root = createByInsert(t.getRoot(),34);
    createByInsert(root,23);
    createByInsert(root,67);
    createByInsert(root,2);
    createByInsert(root,93);
    t.inorderTraversal(root);
    return 0;
}