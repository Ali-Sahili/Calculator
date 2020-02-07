#include <iostream>
#include "Matrice.h"
#include "Vector.h"
#include <cmath>
#include <iomanip>
using namespace std;

Matrice::Matrice(float T[dim][dim],int m,int n)
{
    this->m=m;
    this->n=n;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            Mat[i][j]=T[i][j];
}

Matrice::Matrice()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            Mat[i][j]=0;
        }
    n=dim;
    m=dim;
}

Matrice Matrice::Input_Matrice(int n,int m)
{
    Matrice T;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cout <<"donner:";
            cin >>T.Mat[i][j];
        }
    T.n=n;
    T.m=m;
    return T;
}

void Matrice::Mineur_Matrice(Matrice A,Matrice &M,int i,int j)
{
    int a,b,k=0,p=0;
    for(a=0;a<A.n;a++)
    {
        for(b=0;b<A.n;b++)
            if(a!=i&&b!=j)
                M.Mat[k][p++]=A.Mat[a][b];
        if(a!=i)
        {
            k++;
            p=0;
        }
        M.n=A.n-1;
        M.m=A.m-1;
    }
}

void Matrice::Rend_fract(float *a,int *i)//this function transform a decimal number into a fraction
{
    float x=*a*(*i);
    while(x!=int(x))
    {
        (*i)++;
        x=*a*(*i);
    }
    *a=x;
}

void Matrice::Affiche()const
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout <<Mat[i][j]<<" ";
        cout <<endl;
    }
    cout <<"*******************************"<<endl;
}

void Matrice::Affiche2()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int k=1;
            float a=Mat[i][j];
            if(a==int(a))
                cout <<setw(15)<<int(Mat[i][j]);
            else
            {
                Rend_fract(&a,&k);
                cout <<setw(15)<<int(Mat[i][j])<<"/"<<k;
            }
        }
        cout <<endl;
    }
    cout <<"*******************************"<<endl;
}

void Matrice::Det_Matrice(Matrice A,int k,int i,int j,float s,float *p,float *l)const
{
    Matrice B;
    if(A.n==2)
        *l+=s*(A.Mat[0][0]*A.Mat[1][1]-A.Mat[1][0]*A.Mat[0][1]);
    if(j<A.n&&A.n!=2)
    {
        A.Mineur_Matrice(A,B,i,j);
        s=pow(-1,i+j)*A.Mat[i][j] ;
        s*=*p;
        A.Det_Matrice(A,n,i,j+1,s,p,l);
        *p=s;
        A.Det_Matrice(B,n-1,0,0,*p,p,l);
    }
}

void Matrice::Adjoint_Cofactor(Matrice &Adj,Matrice &Cofactor)
{

    Matrice M;
    float p,l;
    if(n==2)
    {
        Cofactor.Mat[0][0]=Mat[1][1];
        Cofactor.Mat[0][1]=-Mat[1][0];
        Cofactor.Mat[1][0]=-Mat[0][1];
        Cofactor.Mat[1][1]=Mat[0][0];
        Adj.Mat[0][0]=Cofactor.Mat[0][0];
        Adj.Mat[0][1]=Cofactor.Mat[1][0];
        Adj.Mat[1][0]=Cofactor.Mat[0][1];
        Adj.Mat[1][1]=Cofactor.Mat[1][1];
    }
    else
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                p=1;
                l=0;
                this->Mineur_Matrice(*this,M,i,j);
                this->Det_Matrice(M,n-1,0,0,1,&p,&l);
                Cofactor.Mat[i][j]=pow(-1,i+j)*l;
               // Adj.Mat[i][j]=Cofactor.Mat[j][i];
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                Adj.Mat[i][j]=Cofactor.Mat[j][i];
    }
    Adj.n=n;
    Adj.m=m;
    Cofactor.n=n;
    Cofactor.m=m;
}

Matrice Matrice::Add_Matrices(Matrice M)
{
    Matrice T;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            T.Mat[i][j]=Mat[i][j]+M.Mat[i][j];
    T.n=n;
    T.m=m;
    return T;
}

Matrice Matrice::Mines_Matrices(Matrice M)
{
    Matrice T;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            T.Mat[i][j]=Mat[i][j]-M.Mat[i][j];
    T.n=n;
    T.m=m;
    return T;
}

Matrice Matrice::Product_Matrices(Matrice M)
{
    Matrice P;
    if(m==M.n)
    {
        for(int i=0;i<n;i++)
            for(int d=0;d<M.m;d++)
                for(int j=0;j<m;j++)
                    P.Mat[i][d]+=Mat[i][j]*M.Mat[j][d];
        P.n=n;
        P.m=M.m;
        for(int i=0;i<n;i++)
            for(int d=0;d<M.m;d++)
                if(P.Mat[i][d]<0.00001)
                    P.Mat[i][d]=0;
        return P;
    }
    else
    {
        cout <<"it is impossible to calculate the product of these 2 matrices."<<endl;;
    }
}

Matrice Matrice::Div_Matrices(Matrice M)
{
    Matrice P;
    if(m==M.n)
    {
        for(int i=0;i<n;i++)
            for(int d=0;d<M.m;d++)
                for(int j=0;j<m;j++)
                    P.Mat[i][d]+=Mat[i][j]/M.Mat[j][d];
        P.n=n;
        P.m=M.m;
        return P;
    }
    else
    {
        cout <<"it is impossible to calculate the division of these 2 matrices."<<endl;;
    }
}

Matrice Matrice::Inverse_Matrice()
{
    Matrice Inverse,Cofactor,Adjoint;
    float p=1,l=0;
    this->Adjoint_Cofactor(Adjoint,Cofactor);
    this->Det_Matrice(*this,n,0,0,1,&p,&l);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            Inverse.Mat[i][j]=(Adjoint.Mat[i][j])/l;
    Inverse.n=n;
    Inverse.m=m;
    return Inverse;
}


