#include<iostream>
using namespace std;
#include<vector>

void swap(double *a,double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

double knapsack(double obj[][7],int n,double c) {
    

    // first sort the 2d array on the basis of obj[i][0]/obj[i][1] for every column
    for(int i=0; i<6; i++) {
        for(int j=0; j<6-i; j++) {
            if((obj[0][j]/obj[1][j]) < (obj[0][j+1]/obj[1][j+1])) {
                swap(obj[0][j],obj[0][j+1]);
                swap(obj[1][j],obj[1][j+1]);
            } 
        }
    } 


    double x[7] = {0};
    double profit = 0.0;

    for(int i=0; i<7; i++) {
        if(obj[1][i] <= c) {
            profit += obj[0][i];
            c -= obj[1][i];
            x[i] = 1;
        }
        else {
            profit += obj[0][i]*(c/obj[1][i]);
            x[i] = c/obj[1][i];
            c = 0;
            break;
        }
    }
    return profit;
}


int main() {
    int m = 7;
    double obj[2][7] = {
        {12,17,9,7,5,21,8},
        {2,5,7,3,1,4,1}
    };

    double capacity = 15;
    cout<<knapsack(obj,2,capacity)<<endl;

    return 0;
}