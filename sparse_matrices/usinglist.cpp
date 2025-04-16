#include<iostream>
using namespace std;

class node 
{
    public:
        int val;
        int col;
        node *next;
};


// void create(node *a[],int m,int n)
// {
//     for(int i=0; i<m; i++)
//     {
//         node *last = NULL;
//         int z;
//         cout<<"non zero element: ";
//         cin>>z;
//         cout<<"Enter matrix: ";
//         for(int j=0; j<z; j++)
//         {
//             int val,col;
//             cin>>val>>col;
//             // if(val != 0)
//             // {
//                 node *n = new node;
//                 n->val = val;
//                 n->col = col;
//                 n->next = NULL;
//                 if(a[i] == NULL)
//                 {
//                     a[i] = n;
//                 }
//                 else
//                 {
//                     last->next = n;
//                 }
//                 last = n;
//             // }

            
//         }
//     }
// }


void create(node *a[],int m,int n)
{
    for(int i=0; i<m; i++)
    {
        node *last = NULL;
        cout<<"Enter matrix: ";
        for(int j=0; j<n; j++)
        {
            int val;
            cin>>val;
            if(val != 0)
            {
                node *n = new node;
                n->val = val;
                n->col = j;
                n->next = NULL;
                if(a[i] == NULL)
                {
                    a[i] = n;
                }
                else
                {
                    last->next = n;
                }
                last = n;
            }

            
        }
    }
}


void display(node *arr[],int m,int n)
{
    node *t;
    for(int i=0; i<m; i++)
    {
        t = arr[i];
        for(int j=0; j<n; j++)
        {
            if(t != NULL && t->col == j)
            {
                cout<<t->val<<" ";
                t = t->next;
            }
            else 
            {
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}


int main() 
{
    int m,n;
    cin>>m>>n;
    node *a[m] = {nullptr};
    create(a,m,n);
    display(a,m,n);
    return 0;
}