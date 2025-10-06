#include<iostream>
using namespace std;
#include<vector>


class Node {
    public: 
        char data;
        Node *left,*right;

        Node(char val) {
            data = val;
            left = right = NULL;
        }
};


void insert(Node **root, int val) {
    
    Node *n = new Node(val);

    if(*root == NULL) {
        *root = n;
        return;
    }

    Node *temp = *root;
    Node *prev = NULL;
    while(temp != NULL) {
        prev = temp;
        if(temp->data < val) {
            temp = temp->right;
        }else {
            temp = temp->left;
        }
    }


    if(prev->data > val) {
        prev->left = n;
    }else {
        prev->right = n;
    }
}


void preOrder(Node *root) {
    if(root == NULL) {
        return ;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}



int main() {
    int size;
    cin>>size;
    Node* root = NULL;
    vector<char> arr(size);

    for(int i=0; i<size;i++) {
        cin>>arr[i];
        insert(&root,arr[i]);
    }

    preOrder(root);
    return 0;
}