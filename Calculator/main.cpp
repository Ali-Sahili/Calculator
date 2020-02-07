#include <iostream>
#include <windows.h>
#include <cstdio>
#include <conio.h>
#include "Matrice.h"
#include "Vector.h"
#include "Gauss.h"
#define dim 100
using namespace std;

Vector Product_Mat_Vect(const Matrice &M,Vector V)
{
    Vector res;
    if(M.m==V.d)
    {
        for(int i=0;i<M.n;i++)
            for(int j=0;j<M.m;j++)
                res.Vect[i]+=M.Mat[i][j]*V.Vect[j];
        res.d=M.n;
        return res;
    }
    else
    {
        cout <<"the product of this matrix and this vector is not available."<<endl;
        return res;
    }
}

void Rend_fract(float *a,int *i)//this function transform a decimal number into a fraction
{
    float x=*a*(*i);
    while(x!=int(x))
    {
        (*i)++;
        x=*a*(*i);
    }
    *a=x;
}

int main()
{
    HANDLE  screen=GetStdHandle(STD_OUTPUT_HANDLE);//windows
    int f=0;
    char c,cc;
    while(1)
    {
        system("CLS");
        SetConsoleTextAttribute(screen,10);
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tWelcome to AliSahili's calculator");
        cc=getch();
        if(cc==13) break;//enter
    }
    while(f!=8)
    {
        f=1;
        while(1)
        {
            system("CLS");
            fflush(stdin);
            if(f==1)
            {
                SetConsoleTextAttribute(screen,12);
                printf("\n\n\n\t\t1-solve a system of equations");
            }
            else
            {
                SetConsoleTextAttribute(screen,4);
                printf("\n\n\n\t\t1-solve a system of equations");
            }

            if(f==2)
            {
                SetConsoleTextAttribute(screen,12);
                printf("\n\n\n\t\t2-operations on matrices");
            }
            else
            {
                SetConsoleTextAttribute(screen,4);
                printf("\n\n\n\t\t2-operations on matrices");
            }

            if(f==3)
            {
                SetConsoleTextAttribute(screen,12);
                printf("\n\n\n\t\t3-determinent");
            }
            else
            {
                SetConsoleTextAttribute(screen,4);
                printf("\n\n\n\t\t3-determinent");
            }

            if(f==4)
            {
                SetConsoleTextAttribute(screen,12);
                printf("\n\n\n\t\t4-Inverse of a matrix");
            }
            else
            {
                SetConsoleTextAttribute(screen,4);
                printf("\n\n\n\t\t4-Inverse of a matrix");
            }

            if(f==5)
            {
                SetConsoleTextAttribute(screen,12);
                printf("\n\n\n\t\t5-Cofactor of a matrix");
            }
            else
            {
                SetConsoleTextAttribute(screen,4);
                printf("\n\n\n\t\t5-Cofactor of a matrix");
            }

            if(f==6)
            {
                SetConsoleTextAttribute(screen,12);
                printf("\n\n\n\t\t6-Adjoint of a matrix");
            }
            else
            {
                SetConsoleTextAttribute(screen,4);
                printf("\n\n\n\t\t6-Adjoint of a matrix");
            }

            if(f==7)
            {
                SetConsoleTextAttribute(screen,12);
                printf("\n\n\n\t\t7-roots of an equation");
            }
            else
            {
                SetConsoleTextAttribute(screen,4);
                printf("\n\n\n\t\t7-roots of an equation");
            }

            if(f==8)
            {
                SetConsoleTextAttribute(screen,12);
                printf("\n\n\n\t\t\t\t\tQuit");
            }
            else
            {
                SetConsoleTextAttribute(screen,4);
                printf("\n\n\n\t\t\t\t\tQuit");
            }
            cc=getch();
            if(cc==13) break;//enter
            if(cc==72) f--;//up
            if(cc==80) f++;//down
            if(f==9) f=1;//return to the beginning
            if(f==0) f=8;//go to the end
        }
        if(f==1)
        {
            int m,n;
            cout <<"Enter the number of equations:";
            cin >>m;
            cout <<"Enter the number of variables:";
            if(n>m)
                cout <<"Infinity of solutions."<<endl;
            else if(m>n)
                cout <<"Impossible."<<endl;
            else
            {
                float t[n][n],a[n];
                Matrice M(t,n,n);
                Vector V(a,n);
                Gauss G(M,V);
                M.Input_Matrice(n,n);
                V.Input_Vector(n);
                G.Solution();

            }
        }
    }
    system("CLS");
	SetConsoleTextAttribute(screen,10);
    printf("Thank you for your visit!\n");
    SetConsoleTextAttribute(screen,2);
    printf("\n\t\t\t\t\t\t\tCreated by:****Ali Sahili****");
	SetConsoleTextAttribute(screen,0);
    return 0;
}
