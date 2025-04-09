#include<iostream>
using namespace std;

class Element
{
    public: 
        int r;
        int c;
        int x;

    
};

class Sparse
{
    private:
        int row;
        int col;
        int nz;
        Element *e;

    public:
        Sparse(int n,int m,int i)
        {
            this->row = n;
            this->col = m;
            this->nz = i;
            e = new Element[this->nz];
        }
        friend istream & operator>>(istream &is, Sparse &s);
        friend ostream & operator<<(ostream & os, Sparse &s);
        Sparse operator+(Sparse &s);
        ~Sparse(){ delete e; }
};

istream & operator>>(istream &is, Sparse &s)
{
    cout<<"Enter non zero Elelments(row,col,value)"<<endl;
    for(int i=0; i<s.nz; i++)
    {
        cin>>s.e[i].r>>s.e[i].c>>s.e[i].x;
    }
    return is;
}

ostream & operator<<(ostream &os, Sparse &s)
{
    cout<<"_____________Sparse matrix_____________"<<endl;
    int i,j,k=0;
    for(i=0;i<s.row;i++)
    {
        for(j=0;j<s.col;j++)
        {
            if(i == s.e[k].r && j == s.e[k].c)
            {
                cout<<s.e[k++].x<<" ";
            }
            else {
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return os;
}

Sparse Sparse::operator+(Sparse &s)
{
    Sparse sum(s.row,s.col,s.nz+nz);

    if(row != s.row || col != s.col)
    {
        throw invalid_argument("Matrices dimensions do not match for addition.");
    }

    int i=0,j=0,k=0;
    while(i < nz && j < s.nz)
    {
        if(e[i].r < s.e[j].r)
        {
            sum.e[k++] = e[i++];
        }
        else if (e[i].r > s.e[j].r)
        {
            sum.e[k++] = s.e[j++];
        }
        else 
        {
            if(e[i].c < s.e[j].c)
            {
                sum.e[k++] = this->e[i++];
            }
            else if(e[i].c > s.e[j].c)
            {
                sum.e[k++] = s.e[j++];
            }
            else 
            {
                sum.e[k] = e[i++];
                sum.e[k++].x += s.e[j++].x;
            }
        }
    }
    for(;i < nz; i++){sum.e[k++] = e[i];}
    for(;j < s.nz; j++){sum.e[k++] = s.e[j];}
    sum.nz = k;
    return sum;
}


int main() 
{
    Sparse s(5,5,5),p(5,5,6);
    cin>>s>>p;
    cout<<s<<p;
    Sparse t = s + p;
    cout<<t;
    return 0;
}