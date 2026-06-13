#ifndef FRACTION_H
#define FRACTION_H

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
if (den &lt; 0) { // S&#39;assurer que le dénominateur est positif
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
cout&lt;&lt;&quot;PAS POSSIBLE&quot;&lt;&lt;endl;
}
normalise();
}
Fraction(const Fraction &amp;f) {
num = f.num;

den = f.den;
normalise();
}

// Destructeur
~Fraction() {}
// Affichage de la fraction
void affiche() {
if (den == 1) {
cout &lt;&lt; num;
} else {
cout &lt;&lt; num &lt;&lt; &quot;/&quot; &lt;&lt; den;
}
}
// Opérations sur les fractions
Fraction somme(const Fraction &amp;f) {
return Fraction(num * f.den + f.num * den, den * f.den);
}
Fraction difference(const Fraction &amp;f) {
return Fraction(num * f.den - f.num * den, den * f.den);
}
Fraction produit(const Fraction &amp;f) {
return Fraction(num * f.num, den * f.den);
}
Fraction division(const Fraction &amp;f) {
if (f.num == 0) {
cout &lt;&lt; &quot;Erreur : Division par zéro !\n&quot;;
}
return Fraction(num * f.den, den * f.num);
}
};

#endif // FRACTION_H
