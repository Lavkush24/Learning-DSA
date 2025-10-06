#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Node {
    public: 
        int data;
        Node *left,*right;

        Node(int val) {
            data = val ;
            left = right = NULL;
        }
};



Node *BT(int arr[],int m) {
    queue<Node*> q;
    Node *root = NULL;

    Node *n = new Node(arr[0]);
    root = n;
    q.push(root);
    int i=1;
    while(i<m && !q.empty()) {
        Node *t = q.front(); q.pop();
        
        if(i < m) {
            Node *l = new Node(arr[i++]);
            q.push(l);
            t->left = l;
        }

        if(i < m) {
            Node *r = new Node(arr[i++]);
            q.push(r);
            t->right = r;
        }
    }

    return root;
}


void inorder(Node *root,vector<int> & arr) {
    if(root == NULL) {
        return;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}


int main() {
    int m;
    cin>>m;
    int arr[m];
    for(int i=0; i<m; i++) {
        cin>>arr[i];
    }

    Node *root = BT(arr,m);

    vector<int> in;

    inorder(root,in);
    
    for(int i=0; i<in.size(); i++) {
        cout<<in[i]<<" ";
    }

    return 0;
}


