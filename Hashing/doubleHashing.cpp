#include<iostream>
using namespace std;
#include "Hashing.h"


class DoubleHashing : public HashTable {
    public:
        DoubleHashing(int keys) {
            setKeys(keys);
        }

        int secHashFunction(int c,int R) {
            return R-(c%R);
        } 

        int hashFunction(int c,int prob) override {
            int temp = prob*secHashFunction(c,7);
            int first = c%10;
            return (first+temp)%10;
        }
};


int main() {

    DoubleHashing dh(5);
    dh.insert(56);
    dh.display();

    return 0;
}