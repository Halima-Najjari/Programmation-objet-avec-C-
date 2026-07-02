#ifndef CERCLE_H
#define CERCLE_H

#include "common.h"
#include "MathConstants.h"

class Cercle {
private:
    float rayon;
    float abscisse;
    float ordonnee;

public:
    Cercle(float r = 0, float x = 0, float y = 0)
        : rayon(r), abscisse(x), ordonnee(y) {}

    float calculerSurface() {
        return MathConstants::PI * rayon * rayon;
    }

    float calculerPerimetre() {
        return 2 * MathConstants::PI * rayon;
    }

    void afficher() {
        cout << "Rayon: " << rayon << ", Abscisse: " << abscisse
             << ", Ordonnee: " << ordonnee << endl;
    }

    void deplacer(float dx, float dy) {
        abscisse += dx;
        ordonnee += dy;
    }

    void agrandir(float facteur) {
        rayon *= facteur;
    }
};

#endif // CERCLE_H
