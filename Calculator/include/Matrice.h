#ifndef MATRICE_H
#define MATRICE_H
#define dim 100
#include "Vector.h"
class Matrice
{
    public:
        float Mat[dim][dim];
        int m,n;
        Matrice(float T[dim][dim],int ,int);
        Matrice();
        Matrice Input_Matrice(int ,int );
        void Mineur_Matrice(Matrice ,Matrice &,int ,int);
        void Det_Matrice(Matrice ,int ,int ,int ,float ,float *,float *)const;
        void Affiche()const;
        void Affiche2();
        void Adjoint_Cofactor(Matrice &,Matrice &);
        Matrice Add_Matrices(Matrice );
        Matrice Mines_Matrices(Matrice );
        Matrice Product_Matrices(Matrice );
        Matrice Div_Matrices(Matrice );
        friend Vector Product_Mat_Vect(Matrice ,Vector );
        Matrice Inverse_Matrice();
        void Rend_fract(float *a,int *i);
};

#endif // MATRICE_H
