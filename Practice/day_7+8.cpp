#include<iostream>
using namespace std;
#include<queue>

class Node {
    public: 

        int data;
        Node *left;
        Node *right;

        Node() {};
        Node(int v) {
            data = v;
            left = NULL;
            right = NULL;
        };
};

class BinaryTree {
    public: 
        Node *root = new Node(30);
        queue<Node*> q;

        BinaryTree() {
            Node *n = new Node(15);
            Node *m = new Node(40);
            Node *l = new Node(12);
            Node *p = new Node(32);
            Node *q = new Node(31);
            root->left = n;
            root->right = m;
            n->right = l;
            m->left = p;
            p->right = q;   
        }


        /**********************       DAY (7+8) (BINARY TREE)  ***************************/
        // change node value such that every parent has value equal to all child nodes--------

        // find the mirror tree --------------------------------------------------------------

        // conversion from Binary tree to doubly linked list----------------------------------

        // invert binary tree ----------------------------------------------------------------

        // check mirror or not ---------------------------------------------------------------

        // print all the path of the Binary tree ---------------------------------------------

        // traverse in level order -----------------------------------------------------------

        // print all the levels in different lines--------------------------------------------

        // print level in the spiral order----------------------------------------------------

        // if structure of node is change such that add one extra pointer that point next element of the level  (using extra space and without extra space)

        // print left view ------------------------------------------------------------------

        // print top view -------------------------------------------------------------------
        
        // print right view -----------------------------------------------------------------

        // print bottom view ----------------------------------------------------------------

        // vertical level of the node -------------------------------------------------------

        // vertical order traversal ---------------------------------------------------------

};



int main() {
    BinaryTree *b = new BinaryTree() ;


    return 0;
}