#ifndef CERCLE_H
#define CERCLE_H


class Cercle {
 private:
    float rayon;
    float abscisse;
    float ordonnée;
 public:

    float calculerSurface() {
        return 3.14159 * rayon * rayon;
    }
    float calculerPerimetre() {
        return 2 * 3.14159 * rayon;
    }
    void initialiser(float r, float x, float y) {
        rayon = r;
        abscisse = x;
        ordonnée = y;
    }
    void afficher() {
        cout << "Rayon: " << rayon << ", Abscisse: " << abscisse << ", Ordonnée: " << ordonnée << endl;
    }
     void deplacer(float dx, float dy) {
        abscisse += dx;
        ordonnée += dy;
    }
    void agrandir(float facteur) {
        rayon *= facteur;
    }

};


#endif // CERCLE_H
