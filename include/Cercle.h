#ifndef CERCLE_H
#define CERCLE_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Cercle {
 private:
    float rayon;
    float abscisse;
    float ordonnee;
 public:

    float calculerSurface() {
        return 3.14159 * rayon * rayon;
    }
    float calculerPerimetre() {
        return 2 * 3.14159 * rayon;
    }
    void initialiser(float r, float x, float y) {
        if (r < 0) {
            throw invalid_argument("Le rayon ne peut pas etre negatif");
        }
        rayon = r;
        abscisse = x;
        ordonnee = y;
    }
    void afficher() {
        cout << "Rayon: " << rayon << ", Abscisse: " << abscisse << ", Ordonnee: " << ordonnee << endl;
    }
     void deplacer(float dx, float dy) {
        abscisse += dx;
        ordonnee += dy;
    }
    void agrandir(float facteur) {
        if (facteur <= 0) {
            throw invalid_argument("Le facteur d'agrandissement doit etre positif");
        }
        rayon *= facteur;
    }

};


#endif // CERCLE_H
