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
};

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

    return 0;
}