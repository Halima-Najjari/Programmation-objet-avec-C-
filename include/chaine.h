#ifndef CHAINE_H
#define CHAINE_H

#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

class chaine {
private:
    int longueur;
    char *texte;

public:
    // Constructeur par defaut
    chaine() {
        longueur = 0;
        texte = new char[1];
        texte[0] = '\0';
    }

    // Constructeur par parametre
    chaine(const char *s) {
        if (s == nullptr) {
            throw invalid_argument("Le pointeur de texte ne peut pas etre null");
        }
        longueur = strlen(s);
        texte = new char[longueur + 1];
        strcpy(texte, s);
    }

    // Constructeur de copie (copie profonde)
    chaine(const chaine &c) {
        longueur = c.longueur;
        texte = new char[longueur + 1];
        strcpy(texte, c.texte);
    }

    // Destructeur
    ~chaine() {
        delete[] texte;
    }

    // Affectation
    void affectation(const chaine &c) {
        if (this != &c) {
            delete[] texte;
            longueur = c.longueur;
            texte = new char[longueur + 1];
            strcpy(texte, c.texte);
        }
    }

    // Comparaison
    void comparaison(const chaine &c) {
        if (strcmp(texte, c.texte) == 0) {
            cout << "Les chaines sont egales." << endl;
        } else {
            cout << "Les chaines sont differentes." << endl;
        }
    }

    // Concatenation
    void concatenation(const chaine &c) {
        int nouvelleLongueur = longueur + c.longueur;
        char *nouveauTexte = new char[nouvelleLongueur + 1];

        strcpy(nouveauTexte, texte);
        strcat(nouveauTexte, c.texte);

        delete[] texte;
        texte = nouveauTexte;
        longueur = nouvelleLongueur;
    }

    // Acces a un caractere par index
    char acces(int i) {
        if (i < 0 || i >= longueur) {
            throw out_of_range("Index hors limites (index: " + to_string(i)
                + ", longueur: " + to_string(longueur) + ")");
        }
        return texte[i];
    }

    // Affichage
    void afficher() const {
        cout << "Texte: " << texte << " | Longueur: " << longueur << endl;
    }
};


#endif
