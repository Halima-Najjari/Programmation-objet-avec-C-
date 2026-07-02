#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Produit {

private:
    int ref;
    float puht;
    int quantite;

public:

    // Initialisation
    void initialiser(int r, float p, int q) {
        if (p < 0) {
            throw invalid_argument("Le prix unitaire ne peut pas etre negatif");
        }
        if (q < 0) {
            throw invalid_argument("La quantite ne peut pas etre negative");
        }
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
    bool retirer(int n) {
        if (n < 0) {
            throw invalid_argument("La quantite a retirer ne peut pas etre negative");
        }
        if (n > quantite) {
            cerr << "Stock insuffisant (stock: " << quantite << ", demande: " << n << ")" << endl;
            return false;
        }
        quantite -= n;
        return true;
    }

    // Ajouter au stock
    void ajouter(int n) {
        if (n < 0) {
            throw invalid_argument("La quantite a ajouter ne peut pas etre negative");
        }
        quantite += n;
    }
};


#endif // PRODUIT_H
