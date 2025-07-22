
#ifndef HASHING_H
#define HASHING_H

#include<iostream>
using namespace std;

class HashTable {
    public:
        int *hash;
        int keys;

        HashTable() {
            hash = new int[keys*2];
            for(int i=0; i<keys*2; i++) {
                *(hash+i) = -1;
            }
        }

        HashTable(int k) {
            keys = k;
            hash = new int[keys*2];
            for(int i=0; i<keys*2; i++) {
                *(hash+i) = -1;
            }
        } 

        void setKeys(int k) {
            keys = k;
        }

        virtual int hashFunction(int c,int prob);

        void insert(int c) {
            int i=0;
            while(i<=keys*2) {
                int idx = hashFunction(c,i);
                if(*(hash+idx) == -1) {
                    *(hash+idx) = c;
                    break;
                }
                i++;
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


#endif