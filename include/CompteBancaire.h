#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H


class CompteBancaire {
    private:
        int numero;

        float solde;
    public:
     CompteBancaire(int n, float s): numero(n) ,solde(s) {}

    void deposer(float montant) {
        solde += montant;
    }
    void retirer(float montant) {
        if (montant <= solde) {
            solde -= montant;
        } else {
            cout << "Fonds insuffisants" << endl;
        }
    }
    void afficher() {
        cout << "Numero: " << numero << ", Solde: " << solde << endl;
    }
    void virement(CompteBancaire &dest, float montant) {
        if (montant <= solde) {
            solde -= montant;
            dest.deposer(montant);
        } else {
            cout << "Fonds insuffisants pour le virement" << endl;
        }
    }

};


#endif // COMPTEBANCAIRE_H
