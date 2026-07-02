#ifndef CHAINE_H
#define CHAINE_H

#include <iostream>
#include <cstring> // S'ta3melnah 3la qbel strlen, strcpy, strcat, strcmp
#include <cstdlib> // S'ta3melnah 3la qbel exit()

using namespace std;
//Objet = instance créée à partir d'une classe.

//Attribut = donnée stockée dans l'objet.

//Méthode = fonction appartenant à la classe.

//objet.attribut  → lire ou modifier une donnée.
//objet.methode() → exécuter une action.
class chaine {
private:
    int longueur;
    char *texte;

public:
    // 1. Constructeur par défaut (Création d'une chaîne vide)
    chaine() {
        longueur = 0;
        texte = new char[1];
        texte[0] = '\0';
    }

    // 2. Constructeur par paramètre (Création à partir d'un texte)
    chaine(const char *s) { //Chaine c("bonjour");
        longueur = strlen(s);//7
        texte = new char[longueur + 1];//b o n j o u r \0
        strcpy(texte, s);//texte = "bonjour"
    }

    // 3. Constructeur de copie (Copie profonde pour éviter les conflits de mémoire)
    chaine(const chaine &c) {//chaine c1("bonjour");chaine c2(c1);
        longueur = c.longueur;//7
        texte = new char[longueur + 1];//b o n j o u r \0
        strcpy(texte, c.texte); // after ([ ][ ][ ][ ][ ][ ][ ][ ],[b][o][n][j][o][u][r][\0]) =>([b][o][n][j][o][u][r][\0],[b][o][n][j][o][u][r][\0])
    }

    // 4. DESTRUCTEUR (Indispensable pour libérer 'texte' avec delete[])
    ~chaine() {
        delete[] texte;
    }

    // 5. Méthode d'affectation (Copier proprement le contenu d'une autre chaîne)
    void affectation(const chaine &c) {
        if (this != &c) // Anti-auto-affectation
        {
            delete[] texte; // On vide l'ancienne mémoire
            longueur = c.longueur;
            texte = new char[longueur + 1]; // On réalloue la bonne taille
            strcpy(texte, c.texte); // On copie le texte
        }
    }

    // 6. Méthode de comparaison
    void comparaison(const chaine &c) {
        if (strcmp(texte, c.texte) == 0) {
            cout << "Les chaines sont egales." << endl;
        } else {
            cout << "Les chaines sont differentes." << endl;
        }
    }

    // 7. Méthode de concaténation (Fusionner deux chaînes)
    void concatenation(const chaine &c) {
        int nouvelleLongueur = longueur + c.longueur;
        char *nouveauTexte = new char[nouvelleLongueur + 1]; // Nouveau grand tableau

        strcpy(nouveauTexte, texte);   // Copie de la 1ère partie
        strcat(nouveauTexte, c.texte); // Ajout de la 2ème partie à la fin

        delete[] texte; // Suppression du petit tableau d'avant
        texte = nouveauTexte; // Le pointeur prend la nouvelle adresse
        longueur = nouvelleLongueur;
    }

    // 8. Méthode d'accès à un caractère spécifique
    char acces(int i) {
        if (i >= 0 && i < longueur) {
            return texte[i];
        } else {
            cerr << "Index out of bounds." << endl;
            exit(1); // Arrêt propre du programme en cas d'erreur d'index
        }
    }

    // Fonction bonus pour afficher le résultat f le main
    void afficher() const {
        cout << "Texte: " << texte << " | Longueur: " << longueur << endl;
    }

    int getLongueur() const { return longueur; }
    const char* getTexte() const { return texte; }
};


#endif

