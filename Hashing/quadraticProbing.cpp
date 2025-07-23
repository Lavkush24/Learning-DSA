#include<iostream>
using namespace std;
#include<string>

class QuadraticProbingHashTable {
    public:
        int *hash;
        int keys;

        QuadraticProbingHashTable(int k) {
            keys = k;
            hash = new int[keys*2];
            for(int i=0; i<keys*2; i++) {
                *(hash+i) = -1;
            }
        } 

        int hashFunction(int c,int prob) {
            prob = prob*prob;
            int hash = c % 10;
            int r = (hash + prob) % 10;
            return r;
        }

        void insert(int c) {
            int i=0;
            int idx = hashFunction(c,i);
            while(*(hash+idx) != -1) {
                idx = hashFunction(c,i++);
            }

            *(hash+idx) = c;
        }

        void display(string message) {
            cout<<message<<endl;
            for(int i=0; i<keys*2; i++) {
                cout<<"["<<i<<"]: ";
                if(*(hash+i) == -1) {
                    cout<<endl;
                    continue;
                }
                cout<<*(hash+i)<<endl;
            }
        }

        int search(int k) {
            int idx = hashFunction(k,0);
            while(idx <= keys*2) {
                if(*(hash+idx) == -1) {
                    return -1;
                }

                if(*(hash+idx) == k) {
                    return idx;
                }
                idx = (idx+1) % (keys*2);
            }
            return -1;
        }

};


int main() {
    QuadraticProbingHashTable qh(5);

    qh.insert(34);
    qh.insert(2);
    qh.insert(4);
    qh.insert(24);
    qh.insert(14);

    qh.display("Hash Table <-------Quadratic Probing-------->");
    cout<<"Key found at index: "<<qh.search(9)<<endl;
    return 0;
}