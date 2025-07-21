#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node *next;

        Node() {
            data = 0;
            next = NULL;
        }

        Node(int c) {
            data = c;
            next = NULL;
        }
};

class LinkedList {
    public:     
        Node *head = NULL;

        void insert(int c);
        int remove(int c);
        void display();
        bool searchNode(int k);
};

int LinkedList::remove(int c) {
    Node *temp = head;
    if(head == NULL) {
        return -1;
    }
    else if(head->next == NULL) {
        int t = head->data;
        head = NULL;
        return t;
    }

    if(temp == head) {
        int t = temp->data;
        head = head->next;
        return t;
    }

    while(temp->next->data != c && temp->next != NULL) {
        temp = temp->next;
    }

    Node *t = temp->next;
    temp->next = temp->next->next;
    int tt = t->data;
    delete t;
    return tt;
}

void LinkedList::insert(int c) {
    Node *n = new Node(c);

    if(head == NULL || c < head->data) {
        n->next = head;
        head = n;
        return;
    }
    
    Node *temp = head;
    while(temp->next != NULL && temp->next->data < c) {
        temp = temp->next;
    }

    n->next = temp->next;
    temp->next = n;

}

bool LinkedList::searchNode(int k) {
    Node *temp = head;
    while(temp != NULL) {
        if(temp->data == k) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void LinkedList::display() {
    Node *t = head;
    while(t != NULL) {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}


class ChainingHashTable {
    public: 
        LinkedList hash[10];

        int hashFunction(int c) {
            int index = c % 10;
            return index;
        }

        void insertInHash(int c) {
            int i = hashFunction(c);
            hash[i].insert(c);
        }

        int deleteFromHash(int c) {
            int i = hashFunction(c);
            int r = hash[i].remove(c);
            return r;
        }

        bool search(int k) {
            int i = hashFunction(k);
            return hash[i].searchNode(k);
        }

        void displayhash() {
            for(int i=0; i<10; i++) {
                cout << "[" << i << "]: ";
                hash[i].display();
            }
        }
};

int main() {

    ChainingHashTable ch;
    ch.insertInHash(46);
    ch.insertInHash(1);
    ch.insertInHash(25);
    ch.insertInHash(3);
    ch.insertInHash(5);
    ch.insertInHash(55);

    ch.displayhash();
    cout<<"delete 5"<<endl;
    ch.deleteFromHash(5);
    ch.displayhash();
    ch.search(30) == 1 ? cout<<"element is found"<<endl : cout<<"Element is not found"<<endl;
    return 0;
}