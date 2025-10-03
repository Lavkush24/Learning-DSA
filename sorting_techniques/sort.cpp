#include<iostream>
using namespace std;
#include<climits>
#include<list>


void bubble_sort(int arr[],int s) {
    int flag;
    for(int i=0; i<s-1; i++){
        flag = 0;
        for(int j=0; j<s-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag=1;
            }
        }
        if(flag == 0) break;
    }
}

void insertion_sort(int arr[],int s) {
    for(int i=1; i<s; i++) {
        int j = i-1;
        int x = arr[i];
        while(j>-1 && x < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x; 
    }
}

void selection_sort(int arr[],int s) {
    for(int i=0; i<s-1; i++) {
        int k ,j;
        k = j = i; 
        while(j < s) {
            if(arr[j] < arr[k]) {
                k = j;
            }
            j++;
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a  = *b;
    *b = temp;
}

int partition(int arr[],int l, int h) {
    int pivot = arr[l];
    int i=l, j=h;

    do {
        do { i++; } while(arr[i] <= pivot);
        do { j--; } while(arr[j] > pivot);

        if(i < j) swap(&arr[i], &arr[j]);
    }while(i < j);

    swap(&arr[j],&arr[l]);
    return j;
}

void quick_sort(int arr[], int l, int h) {
    if(l<h) {
        int p = partition(arr,l,h);
        quick_sort(arr,l,p);
        quick_sort(arr,p+1,h);
    }
}


int* merging_list(int l1[],int l2[],int n,int m) {
    int *l3 = new int[n+m];
    int i=0,j=0,k=0;
    while(i < n && j < m) {
        if(l1[i] <= l2[j]) {
            l3[k] = l1[i];
            i++,k++;
        }
        else if(l1[i] > l2[j]) {
            l3[k] = l2[j];
            j++,k++;
        }
    }

    for( ; i<n; i++) { l3[k++] = l1[i]; }
    for( ; j<m; j++) { l3[k++] = l2[j]; }

    return l3;
}

void merge_single(int l[],int s,int mid,int h) {
    int i,j,k;
    i=s,j=mid+1,k=0;
    int *l2 = new int[h+1];

    while(i <= mid && j <= h) {
        if(l[i] < l[j]) {
            l2[k++] = l[i++];
        }else {
            l2[k++] = l[j++];
        }
    }

    for(;i<=mid;i++) { l2[k++] = l[i];}
    for(;j<=h;j++) { l2[k++] = l[j];}

    k = 0 ;
    for(i=s; i<=h; i++) {
        l[i] = l2[k++];
    }

    delete[] l2 ;
}


void iterative_merge_sort(int arr[],int n) {
    int p,i,l,mid,h;

    for(p=2; p<=n; p=p*2) {
        l = 0, h = l+p-1;
        mid = (l+h)/2;
        while(h < n) {
            merge_single(arr,l,mid,h);
            if(n % p > 0) {
                merge_single(arr,0,h,n-1);
            }
            l = h+1;
            h = l+p-1;
            mid = (l+h)/2;
        }

    }
}


void recursive_merge_sort(int arr[],int l,int h) {
    if(l<h) {
        int mid = (l+h)/2;
        recursive_merge_sort(arr,l,mid);
        recursive_merge_sort(arr,mid+1,h);
        merge_single(arr,l,mid,h);
    }

}

int max(int arr[],int s) {
    int c = INT_MIN;
    for(int i=0;i<s; i++) {
        if(c < arr[i]) {
            c = arr[i];
        }
    }
    return c;
}

void count_sort(int arr[],int s) {
    int m = max(arr,s);

    int *temp = new int[m+1];

    for(int i=0; i<m+1; i++) {
        temp[i] = 0;
    }

    for(int i=0; i<s; i++) {
        temp[arr[i]]++;
    }

    int i = 0;
    for(int j=0; j<=m; j++) {
        while(temp[j] > 0) {
            arr[i] = j;
            i++,temp[j]--;
        }
    }

    delete[] temp;
}






/*----------------------------------- BUCKET SORT  and RADIX SORT   ---------------------*/

void bucket_sort(int arr[],int n) {
    int m = max(arr,n);

    list<int> *a = new list<int>[m+1];

    // for(int i=0; i<m+1; i++) {
    //     a[i].push_back();
    // }

    for(int i=0; i<n; i++) {
        a[arr[i]].push_back(arr[i]);
    }

    int j=0;
    for(int i=0; i<m+1; i++) {
        while(!a[i].empty()) {
            arr[j] = a[i].front();
            a[i].pop_front(); 
            j++;
        }
    }

    delete[] a;
}


int count_digit(int m) {
    int count = 0;
    while(m > 0) {
        count++;
        m = m/10;
    }
    return count;
}

void radix_sort(int arr[],int n) {
    int m = max(arr,n);

    int pass = count_digit(m);
    list<int> *a = new list<int>[10];

    int div = 1;
    while(pass > 0) {
        for(int i=0; i<n; i++) {
            int k = (arr[i]/div) % 10;
            a[k].push_back(arr[i]);
        }

        int j=0;
        for(int i=0; i<10; i++) {
            while(!a[i].empty()) {
                arr[j] = a[i].front();
                a[i].pop_front(); 
                j++;
            }
        }
        div = div*10;
        pass--;
    }

}




void print(int arr[],int s) {
    for(int i =0; i<s-1; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<arr[s-1]<<endl;
}

int main() {
    
    int l[] = {4,6,7,81,2,3,4,22};
    int t = sizeof(l)/sizeof(l[0]);
    
    radix_sort(l,t);
    print(l,t);
    return 0;
}

