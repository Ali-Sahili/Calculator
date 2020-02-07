#include <iostream>
#include "Matrice.h"
#include "Vector.h"
#include <cmath>
using namespace std;

Vector::Vector(float V[dim],int d)
{
    this->d=d;
    for(int i=0;i<d;i++)
        Vect[i]=V[i];
}

Vector::Vector()
{
    d=dim;
    for(int i=0;i<d;i++)
        Vect[i]=0;
}

Vector Vector::Input_Vector(int d)
{
    Vector V;
    V.d=d;
    for(int i=0;i<d;i++)
    {
        cout <<"Give a number:";
        cin >>V.Vect[i];
    }
    return V;
}

void Vector::Affiche_Vector()
{
    cout <<"the vector is :"<<endl;
    for(int i=0;i<d;i++)
        cout <<Vect[i]<<endl;
}

Vector Vector::Add_Vectors(Vector V)
{
    Vector T;
    for(int i=0;i<d;i++)
        T.Vect[i]=Vect[i]+V.Vect[i];
    T.d=d;
    return T;
}

Vector Vector::Mines_Vectors(Vector V)
{
    Vector T;
    for(int i=0;i<d;i++)
        T.Vect[i]=Vect[i]-V.Vect[i];
    T.d=d;
    return T;
}



