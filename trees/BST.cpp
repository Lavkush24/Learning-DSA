#include<iostream>
using namespace std;
#include "Tree.h"





int main() {
    Tree t;
    t.create();
    t.inorderTraversal(t.getRoot());
    return 0;
}