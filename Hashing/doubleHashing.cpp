#include<iostream>
using namespace std;


class DoubleHashing {
    public:
        int *hash;
        int keys;

        DoubleHashing(int k) {
            keys = k;
            hash = new int[keys*2];
            for(int i=0; i<keys*2; i++) {
                *(hash+i) = -1;
            }
        } 

        int hashHelperFunction(int c,int r) {
            return r - (c % r);
        }

        int hashFunction(int c,int prob) {
            prob = prob * hashHelperFunction(c,7);
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

        void display() {
            cout<<"Hash Table <-----Double Hashing------>"<<endl;
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

    DoubleHashing dh(5);
    dh.insert(5);
    dh.insert(15);
    dh.insert(25);
    dh.insert(28);
    dh.insert(35);
    dh.display();

    return 0;
}