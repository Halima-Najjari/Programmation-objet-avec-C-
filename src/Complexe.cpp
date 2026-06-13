#include "Complexe.h"

Complexe::Complexe(float reel, float imaginaire) {
re = reel;
im = imaginaire;
}
float Complexe::real() {
return re;
}
float Complexe::imag() {
return im;
}

float Complexe::norme() {
return sqrt(re * re + im * im);
}
Complexe Complexe::conjugue() {
return Complexe(re, -im);
}
Complexe Complexe::somme(Complexe &c) {
return Complexe(re + c.re, im + c.im);
}
Complexe Complexe::difference(Complexe &c) {
return Complexe(re - c.re, im - c.im);
}
Complexe Complexe::produit(Complexe &c) {
return Complexe(re * c.re - im * c.im, re * c.im + im * c.re);
}
void Complexe::affiche() {
    if (im >= 0)
        cout << re << " + " << im << "i" << endl;
    else
        cout << re << " - " << -im << "i" << endl;
}
