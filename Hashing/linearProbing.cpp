#include<iostream>
using namespace std;

class LinearProbingHashTable {
    public:
        int *hash;
        int keys;

        LinearProbingHashTable(int k) {
            keys = k;
            hash = new int[keys*2];
            for(int i=0; i<keys*2; i++) {
                *(hash+i) = -1;
            }
        } 

        int hashFunction(int c,int prob) {
            int hash = c % 10;
            int r = (hash + prob) % 10;
            return r;
        }

        void insert(int c) {
            for(int i=0; i<=keys*2; i++) {
                int idx = hashFunction(c,i);
                if(*(hash+idx) == -1) {
                    *(hash+idx) = c;
                    break;
                }
            }
        }

        void display() {
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
    LinearProbingHashTable lh(5);

    lh.insert(34);
    lh.insert(23);
    lh.insert(2);
    lh.insert(4);
    lh.insert(28);
    lh.insert(19);
    lh.insert(9);

    lh.display();
    cout<<"Key found at index: "<<lh.search(9)<<endl;
    return 0;
}