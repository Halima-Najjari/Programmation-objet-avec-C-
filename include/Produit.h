#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>

using namespace std;

class Produit {

private:
    int ref;
    float puht;
    int quantite;

public:

    // Initialisation
    void initialiser(int r, float p, int q) {
        ref = r;
        puht = p;
        quantite = q;
    }

    // Affichage
    void afficher() {
        cout << "Reference : " << ref << endl;
        cout << "Prix Unitaire HT : " << puht << endl;
        cout << "Quantite : " << quantite << endl;
    }

    // Prix TTC
    float calculerPrixTTC() {
        return puht * 1.2;
    }

    // Prix total du stock
    float prix_total() {
        return puht * quantite;
    }

    // Retirer du stock
    void retirer(int n) {
        if (n <= 0) {
            cout << "La quantite doit etre positive" << endl;
            return;
        }
        if (n > quantite) {
            cout << "Stock insuffisant" << endl;
            return;
        }
        quantite -= n;
    }

    // Ajouter au stock
    void ajouter(int n) {
        if (n <= 0) {
            cout << "La quantite doit etre positive" << endl;
            return;
        }
        quantite += n;
    }
};


#endif // PRODUIT_H
