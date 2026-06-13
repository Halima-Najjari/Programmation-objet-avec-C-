#ifndef COMPLEXE_H
#define COMPLEXE_H

class Complexe {
float re, im; // Partie réelle et imaginaire
public:
// Constructeur
Complexe(float reel, float imaginaire = 0);
float real();
float imag();
float norme();
Complexe conjugue();
Complexe somme(Complexe &amp;);
Complexe difference(Complexe &amp;);
Complexe produit(Complexe &amp;);
// Affichage
void affiche();
};

#endif // COMPLEXE_H
