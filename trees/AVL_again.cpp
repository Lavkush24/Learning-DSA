#include<iostream>
using namespace std;


class Node {
    public:    
        Node *left;
        int data;
        int height;
        Node *right;
};


class AVL {
    public:
        Node *root = NULL;

        int height(Node *n) {
            int x,y;
            while(n != NULL) {
                x = height(n->left);
                y = height(n->right);

                if(x > y) {
                    return x+1-y;
                }
                else {
                    return y+1-x;
                }
            }
            return 0;
        } 

        void insert(int key) {
            Node *temp = root;
            
            if(root == NULL) {
                Node *n = new Node;
                n = NULL;
                n->data = key;
                n->height = 1;
                root = n;
                return ;
            }

            while(temp != NULL) {
                if(temp->data == key) {
                    return ;
                }else if(temp->data > key) {
                    temp = temp->left;
                }
                else if(temp->data < key) {
                    temp = temp->right;
                }
            }

            Node *n = new Node;
            n = NULL;
            n->data = key;
            n->height = 1;
            if(temp->data > key) {
                temp->left = n;
            }
            else if(temp->data < key){
                temp->right = n;
            }
        }
};


int main() {

}