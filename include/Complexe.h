#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <iostream>
#include <cmath>
using namespace std;

class Complexe {
float re, im; // Partie réelle et imaginaire
public:
// Constructeur
Complexe(float reel, float imaginaire = 0);
float real();
float imag();
float norme();
Complexe conjugue();
Complexe somme(Complexe &);
Complexe difference(Complexe &);
Complexe produit(Complexe &);
// Affichage
void affiche();
};

#endif // COMPLEXE_H
