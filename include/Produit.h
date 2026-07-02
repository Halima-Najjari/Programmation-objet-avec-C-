#ifndef PRODUIT_H
#define PRODUIT_H

#include "common.h"

class Produit {
private:
    int ref;
    float puht;
    int quantite;

public:
    Produit(int r = 0, float p = 0, int q = 0)
        : ref(r), puht(p), quantite(q) {}

    void afficher() {
        cout << "Reference : " << ref << endl;
        cout << "Prix Unitaire HT : " << puht << endl;
        cout << "Quantite : " << quantite << endl;
    }

    float calculerPrixTTC() {
        return puht * 1.2;
    }

    float prix_total() {
        return puht * quantite;
    }

    void retirer(int n) {
        quantite -= n;
    }

    void ajouter(int n) {
        quantite += n;
    }
};

#endif // PRODUIT_H
