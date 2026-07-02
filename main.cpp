#include <iostream>
#include <cstring>
#include <stdexcept>
#include "chaine.h"
#include "Complexe.h"
#include "Fraction.h"
#include "Produit.h"
#include "Cercle.h"
#include "CompteBancaire.h"

using namespace std;

int main() {
    // Test des constructeurs
    chaine ch1("Hello");
    chaine ch2("World");

    cout << "--- Affichage initial ---" << endl;
    ch1.afficher();
    ch2.afficher();

    // Test de la concatenation
    cout << "\n--- Test Concatenation ---" << endl;
    ch1.concatenation(ch2);
    ch1.afficher();

    // Test de l'acces
    cout << "\n--- Test Acces au caractere d'index 4 ---" << endl;
    try {
        cout << "Le caractere est: " << ch1.acces(4) << endl;
    } catch (const out_of_range &e) {
        cerr << "Erreur d'acces: " << e.what() << endl;
    }

    // Test de la comparaison
    cout << "\n--- Test Comparaison ---" << endl;
    ch1.comparaison(ch2);

    Complexe c1(3, 4);
    Complexe c2(1, -2);

    cout << "Complexe 1 : ";
    c1.affiche();

    cout << "Complexe 2 : ";
    c2.affiche();

    cout << "Conjugue de Complexe 1 : ";
    c1.conjugue().affiche();

    cout << "Somme : ";
    c1.somme(c2).affiche();

    cout << "Difference : ";
    c1.difference(c2).affiche();

    cout << "Produit : ";
    c1.produit(c2).affiche();

    cout << "Norme de Complexe 1 : "
         << c1.norme() << endl;
    // Saisie des fractions

     int num1, den1, num2, den2;

    cout << "Entrez la premiere fraction (num den) : ";
    cin >> num1 >> den1;

    try {
        Fraction f1(num1, den1);

        cout << "Entrez la deuxieme fraction (num den) : ";
        cin >> num2 >> den2;

        Fraction f2(num2, den2);

        Fraction troisQuarts(3, 4);
        Fraction cinqHuitiemes(5, 8);
        Fraction quatre(4);

        Fraction numerateur =
            f1.somme(troisQuarts).difference(f2);

        Fraction denominateur =
            f1.produit(f2).difference(cinqHuitiemes);

        Fraction E =
            numerateur.division(denominateur).somme(quatre);

        cout << "Resultat de E = ";
        E.affiche();
        cout << endl;
    } catch (const invalid_argument &e) {
        cerr << "Erreur de fraction: " << e.what() << endl;
    }

    Produit p;
    p.initialiser(123, 10.5, 20);

    cout << "=== Produit initial ===" << endl;
    p.afficher();

    cout << "Prix TTC : " << p.calculerPrixTTC() << endl;
    cout << "Prix total du stock : " << p.prix_total() << endl;

    // Retirer des produits
    if (!p.retirer(5)) {
        cerr << "Echec du retrait de produits" << endl;
    }

    cout << endl;
    cout << "=== Apres retrait ===" << endl;
    p.afficher();

    // Ajouter des produits
    p.ajouter(10);

    cout << endl;
    cout << "=== Apres ajout ===" << endl;
    p.afficher();

    Cercle cercle;
    cercle.initialiser(5, 0, 0);
    cercle.afficher();
    cout << "Surface: " << cercle.calculerSurface() << endl;
    cout << "Perimetre: " << cercle.calculerPerimetre() << endl;

    cercle.deplacer(2, 3);
    cout << "Apres deplacement: ";
    cercle.afficher();

    cercle.agrandir(2);
    cout << "Apres agrandissement: ";
    cercle.afficher();

    CompteBancaire cb1(1, 1000), cb2(2, 500);
    cb1.afficher();
    cb2.afficher();
    cb1.deposer(200);
    cout << "Apres depot: " << endl;
    cb1.afficher();

    if (!cb1.retirer(150)) {
        cerr << "Echec du retrait" << endl;
    }
    cout << "Apres retrait: " << endl;
    cb1.afficher();

    if (!cb1.virement(cb2, 300)) {
        cerr << "Echec du virement" << endl;
    }
    cout << "Apres virement: " << endl;
    cb1.afficher();
    cb2.afficher();



    return 0;

}
