#ifndef FRACTION_H
#define FRACTION_H

#include "common.h"

class Fraction {
    int num, den;

    int pgcd(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    void normalise() {
        int diviseur = pgcd(abs(num), abs(den));
        num /= diviseur;
        den /= diviseur;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Fraction() : num(0), den(1) {}

    Fraction(int i) : num(i), den(1) {}

    Fraction(int n, int d) {
        if (d != 0) {
            num = n;
            den = d;
            normalise();
        } else {
            cout << "PAS POSSIBLE" << endl;
            num = 0;
            den = 1;
        }
    }

    Fraction(const Fraction &f) : num(f.num), den(f.den) {
        normalise();
    }

    ~Fraction() {}

    void affiche() {
        if (den == 1) {
            cout << num;
        } else {
            cout << num << "/" << den;
        }
    }

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
            cout << "Erreur : Division par zero !" << endl;
        }
        return Fraction(num * f.den, den * f.num);
    }
};

#endif // FRACTION_H
