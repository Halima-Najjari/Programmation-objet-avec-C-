#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "common.h"

class Complexe {
    float re, im;

public:
    Complexe(float reel, float imaginaire = 0);
    float real();
    float imag();
    float norme();
    Complexe conjugue();
    Complexe somme(Complexe &);
    Complexe difference(Complexe &);
    Complexe produit(Complexe &);
    void affiche();
};

#endif // COMPLEXE_H
