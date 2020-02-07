#ifndef GAUSS_H
#define GAUSS_H


class Gauss:public Matrice,public Vector
{
    Matrice Mat_G;
    Vector Vect_G;
    public:
        Gauss(Matrice ,Vector );
        float Sum(int );
        void Convergence(int);
        void Affiche();
        void Solution();
        void Gauss_Method();
        void Rend_fract(float *a,int *i);
};

#endif // GAUSS_H
