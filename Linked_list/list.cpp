#include<iostream>
using namespace std;

class list 
{
    private:
        int data;
        list *next;

    public:
        list();
        list(int arr[], int size);
        void display(list *l);
        void Rdisplay(list *l);
        void count_node(list *l);
        void insert_begin(int x);
        void insert_index(int x,int i);
        int sum(list *l);
        int max(list *l);
        int min(list *l);
        int search(list *l,int x);
        int delete_first();
        int delete_index();
};