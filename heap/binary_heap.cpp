#include<iostream>
using namespace std;

class max_heap {
    public: 
        int *arr;
        int size;

        max_heap() {
            size = 0;
            arr = new int[size];
        }


        void insert(int pos) {
            int temp, i = pos;
            temp = arr[i];

            while(i > 0 && arr[(i-1)/2] < temp) {
                arr[i] = arr[(i-1)/2];
                i = (i-1)/2;
            }
            arr[i] = temp;
        }


        void create_heap() {
            cout<<"Enter the size of the heap: ";
            cin>>size;
            cout<<"Enter the element of the heap: ";
            for(int i=0; i<size; i++) {
                cin>>arr[i];
            }

            for(int j=1; j<size; j++) {
                insert(j);
            }
        }

        void print_heap() {
            cout<<"max heap: ";
            for(int i=0; i<size-1; i++) {
                cout<<arr[i]<<" ";
            }
            cout<<arr[size-1]<<endl;
        }

        int delete_max() {
            int temp = arr[0];
            arr[0] = arr[size-1];
            size--;

            int i =0;
            int j = 2*i + 1;
            while(j < size-1) {
                if(arr[j+1] > arr[j]) {
                    j = j+1;
                }

                if(arr[i] < arr[j]) {
                    int c = arr[i];
                    arr[i] = arr[j];
                    arr[j] = c;
                    i = j;
                    j = 2*i + 1;
                }else {
                    break;
                }
            }
            return temp;
        }

        void heap_sort() {
            int n = size;
            for(int i=0; i<n; i++) {
                int t = delete_max();
                arr[n-i-1] = t;
            }
            size = n;
        }
};




int main() {
    max_heap *mh = new max_heap();

    mh->create_heap();
    mh->heap_sort();
    mh->print_heap();
    return 0;
}