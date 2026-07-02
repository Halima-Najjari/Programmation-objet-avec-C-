#ifndef CHAINE_H
#define CHAINE_H

#include "common.h"

class chaine {
private:
    int longueur;
    char *texte;

    // Helper to allocate and copy a C-string (eliminates repeated deep-copy code)
    void copierDepuis(const char *src, int len) {
        longueur = len;
        texte = new char[longueur + 1];
        strcpy(texte, src);
    }

public:
    // 1. Constructeur par defaut
    chaine() {
        longueur = 0;
        texte = new char[1];
        texte[0] = '\0';
    }

    // 2. Constructeur par parametre
    chaine(const char *s) {
        copierDepuis(s, strlen(s));
    }

    // 3. Constructeur de copie (copie profonde)
    chaine(const chaine &c) {
        copierDepuis(c.texte, c.longueur);
    }

    // 4. Destructeur
    ~chaine() {
        delete[] texte;
    }

    // 5. Affectation (copie profonde)
    void affectation(const chaine &c) {
        if (this != &c) {
            delete[] texte;
            copierDepuis(c.texte, c.longueur);
        }
    }

    // 6. Comparaison
    void comparaison(const chaine &c) {
        if (strcmp(texte, c.texte) == 0) {
            cout << "Les chaines sont egales." << endl;
        } else {
            cout << "Les chaines sont differentes." << endl;
        }
    }

    // 7. Concatenation
    void concatenation(const chaine &c) {
        int nouvelleLongueur = longueur + c.longueur;
        char *nouveauTexte = new char[nouvelleLongueur + 1];

        strcpy(nouveauTexte, texte);
        strcat(nouveauTexte, c.texte);

        delete[] texte;
        texte = nouveauTexte;
        longueur = nouvelleLongueur;
    }

    // 8. Acces a un caractere
    char acces(int i) {
        if (i >= 0 && i < longueur) {
            return texte[i];
        } else {
            cerr << "Index out of bounds." << endl;
            exit(1);
        }
    }

    void afficher() const {
        cout << "Texte: " << texte << " | Longueur: " << longueur << endl;
    }
};

#endif // CHAINE_H
