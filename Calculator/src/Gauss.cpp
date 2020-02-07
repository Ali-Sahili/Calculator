#include <iostream>
#include "Matrice.h"
#include "Vector.h"
#include "Gauss.h"
#define dim 100
using namespace std;

Gauss::Gauss(Matrice Mat,Vector Vect)
{
    for(int i=0;i<Mat_G.n;i++)
    {
        for(int j=0;j<Mat_G.m;j++)
            Mat_G.Mat[i][j]=Mat.Mat[i][j];
        Vect_G.Vect[i]=Vect.Vect[i];
    }
    Mat_G.n=Mat.n;
    Mat_G.m=Mat.m;
    Vect_G.d=Vect.d;
}
void Gauss::Rend_fract(float *a,int *i)
{
    float x=*a*(*i);
    while(x!=int(x))
    {
        (*i)++;
        x=*a*(*i);
    }
    *a=x;
}

float Gauss::Sum(int i)
{
    float s=0;
    for(int j=(Mat_G.n)-1;j>i;j--)
        s+=(Vect_G.Vect[j])*(Mat_G.Mat[i][j]);
    return s;
}

void Gauss::Convergence(int m)
{

    int i,j;
    float max=Mat_G.Mat[m][m],temp;
    for(i=m;i<Mat_G.n;i++)
        if(Mat_G.Mat[i][m]>=max)
        {
            j=i;
            max=Mat_G.Mat[i][m];
        }
    temp=this->Vect_G.Vect[m];
    this->Vect_G.Vect[m]=this->Vect_G.Vect[j];
    this->Vect_G.Vect[j]=temp;
    for(i=0;i<Mat_G.n;i++)
    {
        temp=this->Mat_G.Mat[m][i];
        this->Mat_G.Mat[m][i]=this->Mat_G.Mat[j][i];
        this->Mat_G.Mat[j][i]=temp;
    }
}


void Gauss::Affiche()
{
    for(int i=0;i<Mat_G.n;i++)
    {
        for(int j=0;j<Mat_G.m;j++)
            cout <<Mat_G.Mat[i][j]<<" ";
        cout <<Vect_G.Vect[i];
        cout <<endl;
    }
    cout <<"********************"<<endl;
}

void Gauss::Solution()
{

    Vector T;
    int i,j;
    int n=T.d;
    T.Vect[n-1]=Vect_G.Vect[n-1]/(Mat_G.Mat[n-1][n-1]);
    for(i=n-2;i>=0;i--)
        T.Vect[i]=(Vect_G.Vect[i]-Sum(i))/(Mat_G.Mat[i][i]);
    cout <<"the solution is:"<<endl;
    T.Affiche_Vector();
    /*for(i=0;i<n;i++)
    {
        if(T.Vect[i]==int(T.Vect[i]))
            cout <<" "<<int(T.Vect[i])<<endl;
        else
        {
            j=1;
            this->Rend_fract(&(T.Vect[i]),&j);
            cout <<" "<<int(T.Vect[i])/j<<endl;
        }
     }*/
}

void Gauss::Gauss_Method()
{
    int i,j,n=Vect_G.d,k,l,c=0;
    for(i=0;i<n;i++)
    {
        this->Convergence(i);
        if(Mat_G.Mat[i][i]==0)
        {
            cout <<"infinity of solutions."<<endl;
            c=1;
            break;
        }
        for(k=i+1;k<n;k++)
        {
            for(l=i+1;l<n;l++)
                Mat_G.Mat[k][l]-=(Mat_G.Mat[k][i]*Mat_G.Mat[i][l])/(Mat_G.Mat[i][i]);
            Vect_G.Vect[k]-=(Vect_G.Vect[i]*Mat_G.Mat[k][i])/(Mat_G.Mat[i][i]);
        }
        for(j=i+1;j<n;j++)
            Mat_G.Mat[j][i]=0;
    }
    if(c==0)
      this->Solution();
}
