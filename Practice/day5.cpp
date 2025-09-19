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
            left = NULL;
            right = NULL;
        };
};

class BinaryTree {
    public: 
        Node *root;
        queue<Node*> q;

        void printLeaf(Node *root) {
            if(root == NULL) return;
            if(root->left == NULL && root->right == NULL) { cout<<root->data<<" " ; }

            if(root->left != NULL)
                printLeaf(root->left);

            if(root->right != NULL)
                printLeaf(root->right);
        }

        void create() {
            Node * n = new Node;
            queue<Node *> q;
            cout<<"Enter the element in level order: ";
            cin>>n->data;
            n->left = n->right = NULL;
            root = n;
            q.push(n);
            
            while(!q.empty()) {
                Node *temp = q.front();
                q.pop();
                int x;
                ;
                cin>>x;
                if(x != -1) {
                    n = new Node;
                    n->data = x;
                    temp->left = n;
                    n->left = n->right = NULL;
                    q.push(n);
                }

                cin>>x;
                if(x != -1) {
                    n = new Node;
                    n->data = x;
                    temp->right = n;
                    n->left = n->right = NULL;
                    q.push(n);
                }
            }
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
};



int main() {
    BinaryTree *b = new BinaryTree();

    b->create();
    b->printLeaf(b->root);
    cout<<b->countNode(b->root)<<endl;
    cout<<b->searchNode(b->root,32)<<endl;
    cout<<"Level of tree: "<<b->levelOfTree(b->root)<<endl;

    return 0;
}