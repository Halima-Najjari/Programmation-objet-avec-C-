#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction {
int num, den; // Numérateur et dénominateur
// Fonction pour calculer le PGCD de deux nombres
int pgcd(int x, int y) {
while (y != 0) {
int temp = y;
y = x % y;
x = temp;
}
return x;
}
// Fonction pour normaliser la fraction (rendre irréductible)
void normalise() {
int diviseur = pgcd(abs(num), abs(den));

num /= diviseur;
den /= diviseur;
if (den < 0) { // S'assurer que le dénominateur est positif
num = -num;
den = -den;
}
}
public:
// Constructeurs
Fraction(){ // Initialisation à 0/1
num = 0;
den = 1;
}
Fraction(int i){ // Initialisation à un entier
num = i;
den = 1;
}
Fraction(int n, int d) {
if(d!=0){
num = n;
den = d;
normalise();
}
else{
cout<<"PAS POSSIBLE"<<endl;
num = 0;
den = 1;
}
}
Fraction(const Fraction &f) {
num = f.num;

den = f.den;
normalise();
}

// Destructeur
~Fraction() {}
// Affichage de la fraction
void affiche() {
if (den == 1) {
cout << num;
} else {
cout << num << "/" << den;
}
}
// Opérations sur les fractions
Fraction somme(const Fraction &f) {
return Fraction(num * f.den + f.num * den, den * f.den);
}
Fraction difference(const Fraction &f) {
return Fraction(num * f.den - f.num * den, den * f.den);
}
Fraction produit(const Fraction &f) {
return Fraction(num * f.num, den * f.den);
}
Fraction division(const Fraction &f) {
if (f.num == 0) {
cout << "Erreur : Division par zéro !" << endl;
return Fraction(0, 1);
}
return Fraction(num * f.den, den * f.num);
}
};

#endif // FRACTION_H
