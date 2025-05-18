#include<iostream>
using namespace std;
#include "Tree.h"


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


int main() {
    Tree t;
    t.create();
    t.inorderTraversal(t.getRoot());
    deleteNode(t.getRoot(),45);
    t.inorderTraversal(t.getRoot());
    return 0;
}