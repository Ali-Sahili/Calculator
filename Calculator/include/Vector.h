#ifndef VECTOR_H
#define VECTOR_H
#define dim 100
#include "Matrice.h"
class Vector
{
    public:
        int d;
        float Vect[dim];
        Vector(float V[dim],int );
        Vector();
        Vector Input_Vector(int );
        void Affiche_Vector();
        Vector Add_Vectors(Vector );
        Vector Mines_Vectors(Vector );
        friend void Rend_fract(float *a,int *i);
};

#endif // VECTOR_H
