#include<iostream>
using namespace std;

struct array 
{
    int A[20];
    int length;
    int size;
};

//display function
void display(struct array a, string str)
{
    cout<<str;
    for(int i=0; i<a.length; i++)
    {
        cout<<a.A[i]<<" ";
    }
    cout<<endl;
}

//union operation    O(n^2)  
struct array * union_(struct array *a, struct array *b)
{
    struct array *c = new struct array;
    c->length = 0;

    //copy the element of array a 
    for(int i=0; i<a->length; i++)
    {
        c->A[i] = a->A[i];
        c->length++;
    }

    //now for array b
    for(int i=0; i<b->length; i++)
    {
        int cc = 0;
        for(int j=0; j<a->length; j++)
        {
            if(b->A[i] == c->A[j])
                cc++;
        } 
        if(cc == 0)
        {
            c->A[c->length++] = b->A[i];
        }
    }
    return c;
}


//union of sorted array   
struct array * union__(struct array *a, struct array *b)
{
    struct array *c = new struct array;
    c->length = 0;

    int i=0,j=0;
    while(i < a->length && j < b->length)
    {
        if(a->A[i] == b->A[j])
        {
            c->A[c->length++] = a->A[i++];
            j++;
        }
        else if(a->A[i] < b->A[j])
        {
            c->A[c->length++] = a->A[i++];
        }else {
            c->A[c->length++] = b->A[j++];
        }
    }

    for(; i<a->length; i++){
        c->A[c->length++] = a->A[i];
    }

    for(; j<b->length; j++){
        c->A[c->length++] = b->A[j];
    }

    return c;
}

//intersection of the sets
struct array * intersection_(struct array *a, struct array *b)
{
    struct array *c = new struct array;
    c->length = 0;
    
    for(int i=0; i<a->length; i++)
    {
        for(int j=0; j<b->length; j++) {
            if(a->A[i] == b->A[j])
                c->A[c->length++] = a->A[i++];
        }
    }
    return c;
}

//intersection of the  sorted sets  takes O(n+m) 
struct array * intersection__(struct array *a, struct array *b)
{
    struct array *c = new struct array ;
    c->length = 0;

    int i=0,j=0;
    while(i < a->length && j < b->length)
    {
        if(a->A[i] == b->A[j])
        {
            c->A[c->length++] = a->A[i++];
            j++;
        }
        else if(a->A[i] < b->A[j])
        {
            i++;
        }
        else {
            j++;
        }
    }
    return c;
}


//difference of the number
struct array * difference_(struct array *a, struct array *b)
{
    struct array *c = new struct array;
    c->length = 0;

    for(int i=0; i<a->length; i++)
    {
        int cc = 0;
        for(int j=0; j<b->length; j++)
        {
            if(a->A[i] == b->A[j])
                cc++;
        }
        if(cc == 0)
            c->A[c->length++] = a->A[i];
    }
    return c;
}

//Difference of number of sorted array
struct array * difference__(struct array *a, struct array *b)
{
    struct array *c = new struct array;
    c->length = 0;
    int i=0,j=0;
    while(i < a->length && j < b->length)
    {
        if(a->A[i] == b->A[j])
        {
            i++; j++;
        }
        else if(a->A[i] < b->A[j])
        {
            c->A[c->length++] = a->A[i++];
        }
        else 
        {
            j++;
        }
    }
    
    for(; i<a->length; i++){
        c->A[c->length++] = a->A[i];
    }
    return c;
}

//set membership operation (to check a element is belong to set or not)
bool isbelong(struct array a,int key) 
{
    for(int i=0; i<a.length; i++)
    {
        if(key == a.A[i])
            return true;
    }
    return false;
}


int main() 
{
    struct array a = {{2,3,4,5,8,12,23,34,44},9,20};
    struct array b = {{2,3,10,12,23,44,45,56,78,98,100},11,20};
    struct array *c,*d;
    display(a, "Element of the array a: ");
    display(b, "Element of the array b: ");
    c = intersection_(&a,&b);
    display(*c,"Intersection of the array a and b: ");
    d = difference__(&a,&b);
    display(*d,"Difference of a and b: ");
    cout<<isbelong(a,44)<<endl;
    return 0;
}