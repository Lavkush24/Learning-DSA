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



int main() {
    Tree t;
    t.create();
    t.inorderTraversal(t.getRoot());
    cout<<RsearchTree(t.getRoot(),12)<<endl;
    cout<<iterativeSearch(t.getRoot(),34)<<endl;
    return 0;
}