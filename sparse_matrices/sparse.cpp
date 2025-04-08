#include<iostream>
using namespace std;

struct Element 
{
    int r;
    int c;
    int x;
};


struct sparse
{
    int row;
    int col;
    int num;
    struct Element *e;
};

void create(struct sparse *s)
{
    cout<<"Enter (row,col,non-zero-element): ";
    cin>>s->row>>s->col>>s->num;
    s->e = new struct Element[s->num];
    cout<<"Enter Element (row,col,value) "<<endl;
    for(int i=0; i<s->num; i++)
    {
        cin>>s->e[i].r>>s->e[i].c>>s->e[i].x;
    }
}

struct sparse * add_sparse(struct sparse *s, struct sparse *p)
{
    struct sparse *sum;
    // if(s->row != p->row || s->col != p->col)
    //     exit(0);

    sum = new struct sparse;
    sum->row = s->row, sum->col = s->col;
    sum->e = new struct Element[s->num + p->num];

    int i=0, j=0, k=0;
    while(i<s->num && j<p->num)
    {
        if(s->e[i].r < p->e[j].r)
        {
            sum->e[k++] = s->e[i++]; 
        }
        else if(s->e[i].r > p->e[j].r)
        {
            sum->e[k++] = p->e[j++];
        }
        else 
        {
            if(s->e[i].c < p->e[j].c)
            {
                sum->e[k++] = s->e[i++];
            }
            else if(s->e[i].c > p->e[j].c)
            {
                sum->e[k++] = p->e[j++];
            }
            else 
            {
                sum->e[k] = s->e[i];
                sum->e[k++].x += p->e[j++].x;
            }
        }
    }
    for(;i < s->num;i++) sum->e[k++] = s->e[i];
    for(;j < p->num;j++) sum->e[k++] = s->e[j];
    sum->num = k;
    return sum;
}

void display(struct sparse s)
{
    cout<<"Sparse matrix "<<endl;
    int i,j,k=0;
    for(i=0; i<s.row ; i++)
    {
        for(j=0; j<s.col; j++)
        {
            if(i==s.e[k].r && j==s.e[k].c)
            {
                cout<<s.e[k++].x<<" ";
            }
            else 
            {
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    
}


int main()
{
    struct sparse s,p,*r;
    create(&s);
    create(&p);
    display(s);
    display(p);
    cout<<"Addition of s and p "<<endl;
    r = add_sparse(&s,&p);
    display(*r);
    return 0;
}