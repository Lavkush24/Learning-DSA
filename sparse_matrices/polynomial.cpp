#include<iostream>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};


void create(struct Poly *p)
{
    cout<<"Enter number of terms: ";
    cin>>p->n;
    p->t = new Term[p->n];
    cout<<"Enter the term (coeff,exp)"<<endl;
    for(int i=0; i<p->n; i++)
    {
        cout<<"enter term "<<i+1<<": ";
        cin>>p->t[i].coeff>>p->t[i].exp;
    }
}

void display(struct Poly p)
{
    cout<<"Polynomial"<<endl;
    for(int i=0; i<p.n; i++)
    {
        if(i != p.n-1) {
            cout<<p.t[i].coeff<<"x^"<<p.t[i].exp<<" + ";
        }
        else 
        {
            cout<<p.t[i].coeff<<"x^"<<p.t[i].exp<<endl;
        }
    }
}

int pow(int a, int b)
{
    int r = 1;
    for(int i=0; i<b; i++)
    {
        r *= a;
    }
    return r;
}

int solve(struct Poly p, int x)
{
    int sum = 0;
    for(int i=0; i<p.n; i++)
    {
        sum += p.t[i].coeff*pow(x,p.t[i].exp);
    }
    return sum;
}

struct Poly * add(struct Poly *p,struct Poly *q)
{
    struct Poly *sum = new struct Poly;
    sum->t = new struct Term[p->n + q->n];
    int i=0,j=0,k=0;
    while(i < p->n && j < q->n)
    {
        if(p->t[i].exp < q->t[j].exp)
        {
            sum->t[k++] = q->t[j++];
        }
        else if(p->t[i].exp > q->t[j].exp)
        {
            sum->t[k++] = p->t[i++]; 
        }
        else 
        {
            sum->t[k].exp = p->t[i].exp;
            sum->t[k++].coeff = p->t[i++].coeff + q->t[j++].coeff;
        }
    }

    for(;i < p->n; i++){ sum->t[k++] = p->t[i]; };
    for(;j < q->n; j++){ sum->t[k++] = q->t[j]; };
    sum->n = k;
    return sum;
}


int main()
{
    struct Poly p,q,*r;
    create(&p);
    display(p);
    create(&q);
    display(q);
    // int x;
    // cout<<"Enter value of x: ";
    // cin>>x;
    // cout<<"Solution of equation at x="<<x<<": "<<solve(p,x)<<endl;
    r = add(&p,&q);
    display(*r);
    return 0;
}