#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

#include <iostream>
#include <stdexcept>

using namespace std;

class CompteBancaire {
    private:
        int numero;

        float solde;
    public:
     CompteBancaire(int n, float s): numero(n) ,solde(s) {}

    void deposer(float montant) {
        if (montant < 0) {
            throw invalid_argument("Le montant du depot ne peut pas etre negatif");
        }
        solde += montant;
    }
    bool retirer(float montant) {
        if (montant < 0) {
            throw invalid_argument("Le montant du retrait ne peut pas etre negatif");
        }
        if (montant > solde) {
            cerr << "Fonds insuffisants (solde: " << solde << ", demande: " << montant << ")" << endl;
            return false;
        }
        solde -= montant;
        return true;
    }
    void afficher() {
        cout << "Numero: " << numero << ", Solde: " << solde << endl;
    }
    bool virement(CompteBancaire &dest, float montant) {
        if (montant < 0) {
            throw invalid_argument("Le montant du virement ne peut pas etre negatif");
        }
        if (montant > solde) {
            cerr << "Fonds insuffisants pour le virement (solde: " << solde << ", demande: " << montant << ")" << endl;
            return false;
        }
        solde -= montant;
        dest.deposer(montant);
        return true;
    }

};


#endif // COMPTEBANCAIRE_H
