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

        void printLeaf(Node *root) {
            if(root == NULL) return;
            if(root->left == NULL && root->right == NULL) { cout<<root->data<<" " ; }

            if(root->left != NULL)
                printLeaf(root->left);

            if(root->right != NULL)
                printLeaf(root->right);
        }

        int countNode(Node *root) {
            if(root == NULL) {
                return 0;
            }

            //left nodes
            int x = countNode(root->left);
            //right nodes
            int y = countNode(root->right);

            return x+y+1;
        }

        bool searchNode(Node *root,int key) {
            if(root == NULL) return false;
            if(root->data == key) return true;

            //call for left side
            bool x = searchNode(root->left, key);
            bool y = searchNode(root->right, key);

            return x || y;
        }

        int levelOfTree(Node *root) {
            if(root == NULL) {
                return -1;
            }

            //for left tree
            int x = levelOfTree(root->left);
            int y = levelOfTree(root->right);

            return x >= y ? x+1 : y+1;
        }


        /*  DATE  20 Sep (Day 6)*/

        int getLevel(Node *root, int val, int currLevel) {
            if(root == NULL) return -1;
            if(root->data == val ) return currLevel;

            // for the left subtree
            int x = getLevel(root->left,val, currLevel+1);
            if(x != -1) return x;
            int y = getLevel(root->right,val,currLevel+1);
            if(y != -1) {
                return y;
            }else {
                return -1;
            }
        }
        
        
        int getLevel(Node *root, int val) {
            if(root == NULL) return -1;
            if(root->data == val ) return 0;

            // for the left subtree
            int x = getLevel(root->left,val);
            if(x != -1) return x+1;
            int y = getLevel(root->right,val);
            if(y != -1) return y+1;

            return x>=y ? x: y;
        }
};



int main() {
    BinaryTree *b = new BinaryTree() ;

    b->printLeaf(b->root);
    cout<<endl;
    // cout<<b->getLevel(b->root,12,0)<<endl;
    cout<<b->getLevel(b->root,30)<<endl;

    return 0;
}