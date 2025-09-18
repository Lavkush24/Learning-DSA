#include<iostream>
#include<vector>
#include<climits>
using namespace std;


/*   LINKED LIST */

class Node {
    public:

        int data ;
        Node *next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};


class LinkedList {
    public:     
        Node *head = NULL;

        void insertIn(int data) {

            Node *n = new Node(data);

            if(head == NULL) {
                head = n;
                return ;
            }

            if(data < head->data) {
                n->next = head;
                head = n;
                return ;
            }

            Node *temp = head,*prev = head;
            while(temp != NULL && data >= temp->data) {
                prev = temp;
                temp = temp->next;
            }

            prev->next = n;
            n->next = temp;
        }


        void reverseList() {
            
            if(head == NULL || head->next == NULL) {
                return;
            }

            Node *temp = head,*newHead = NULL;

            while(temp != NULL) {
                head = head->next;
                temp->next = newHead;
                newHead = temp;
                temp = head;
            }
            head = newHead;
        }

        void reverseList(int m,int n) {

            if(n == 0) {
                return ;
            }

            if(head == NULL || head->next == NULL) {
                return;
            }

            Node *startRef = NULL,*temp = head;
            while(m > 0) {
                startRef = temp;
                temp = temp->next;
                m--;
            }

            Node *endRef = temp, *help = NULL,*newHead = NULL;

            while(n > 0) {
                help = temp->next;
                temp->next = newHead;
                newHead = temp;
                temp = help;
                n--;
            }
            
            if(m == 0) {
                endRef->next = help;
                head = newHead;
                return;
            }

            startRef->next = newHead;
            endRef->next = help;
        }


        void display() {
            Node *temp = head;
            while(temp != NULL) {
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"null"<<endl;
        }
};





int minimumNeg(vector<int> arr,int s,int k) {
        int key = INT_MIN;
        
        for(int i=s; i<k; i++) {
            if(arr[i] < 0 && arr[i] > key) {
                key = arr[i];
            }
        }
        
        return  key == INT_MIN  ? 0 : key;
}


int main() {
    // LinkedList *l = new LinkedList();

    // l->insertIn(34);
    // l->insertIn(16);
    // l->insertIn(56);
    // l->insertIn(6);
    // l->display();
    // // l->reverseList();
    // // l->display();
    // l->reverseList(0,4);
    // l->display();

    vector<int> arr={12, -1, -7, 8, -15, 30, 16, 28};

    cout<<minimumNeg(arr,2,5)<<endl;

    return 0;
}

