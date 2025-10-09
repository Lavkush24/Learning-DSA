#include<iostream>
using namespace std;
#include<queue>
#include<vector>



class Node {
    public: 
        int data;
        Node *left,*right;

        Node(int val) {
            data = val;
            left = right = NULL;
        }
};


Node* create() {
    queue<Node*> q;
    Node *root = NULL;

    int d,e;
    cin>>d;
    Node *n = new Node(d);
    if(root == NULL) {
        root = n;
    }
    q.push(root);

    while(!q.empty()) {
        cin>>d>>e;
        Node *t = q.front(); q.pop();

        if(d != -1) {
            t->left = new Node(d);
            q.push(t->left);
        }

        if(e != -1) {
            t->right = new Node(e);
            q.push(t->right);
        }
    }

    return root;
}


void level(queue<Node*>& q) {

    while(!q.empty()) {
        Node *root = q.front(); q.pop();
        cout<<root->data;
        level(q);
        level(q);
        q.push(root->left);
        q.push(root->right);
    }
}



void knap(vector<int> val,vector<int> w,vector<vector<int>>& x,int size,int col,int cap) {
    for(int i=1; i<size; i++) {
        for(int j=1; j<cap; j++) {
            if((cap-w[i-1]) >= 0) {
                x[i][j] = max(x[i-1][j], val[i-1] + x[i-1][cap-w[i-1]]);
            }
        }
    }
}



int main() {
    
    // Node *root = create();

    // int l,r;
    // cin>>l>>r;

    // queue<Node*> q;
    // q.push(root);

    // level(q);


    const int size = 3;
    const int col = 4;
    int res[size][col] = {0};

    for(int i=0; i<size; i++) {
        for(int j=0; j<col; j++) {
            if(i==0 || j==0) {
                res[i][j] = 0;
            }
        }
    }

    cout<<res[0][0]<<endl;

    return 0;
}