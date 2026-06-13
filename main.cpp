#include <iostream>
#include <cstring>
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

    // Test de la concaténation
    cout << "\n--- Test Concatenation ---" << endl;
    ch1.concatenation(ch2); // ch1 ghadi twlli "HelloWorld"
    ch1.afficher();

    // Test de l'accès
    cout << "\n--- Test Acces au caractere d'index 4 ---" << endl;
    cout << "Le caractere est: " << ch1.acces(4) << endl; // Ghadi y'affichi 'o'

    // Test de la comparaison
    cout << "\n--- Test Comparaison ---" << endl;
    ch1.comparaison(ch2); // Différentes

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

    Produit p;
    p.initialiser(123, 10.5, 20);

    cout << "=== Produit initial ===" << endl;
    p.afficher();

    cout << "Prix TTC : " << p.calculerPrixTTC() << endl;
    cout << "Prix total du stock : " << p.prix_total() << endl;

    // Retirer des produits
    p.retirer(5);

    cout << endl;
    cout << "=== Apres retrait ===" << endl;
    p.afficher();

    // Ajouter des produits
    p.ajouter(10);

    cout << endl;
    cout << "=== Apres ajout ===" << endl;
    p.afficher();

    Cercle c;
    c.initialiser(5, 0, 0);
    c.afficher();
    cout << "Surface: " << c.calculerSurface() << endl;
    cout << "Perimetre: " << c.calculerPerimetre() << endl;

    c.deplacer(2, 3);
    cout << "Apres deplacement: ";
    c.afficher();

    c.agrandir(2);
    cout << "Apres agrandissement: ";
    c.afficher();

      CompteBancaire c1(1, 1000), c2(2, 500);
    c1.afficher();
    c2.afficher();
    c1.deposer(200);
    cout << "Apres depot: " << endl;
    c1.afficher();
    c1.retirer(150);
    cout << "Apres retrait: " << endl;
    c1.afficher();
    c1.virement(c2, 300);
    cout << "Apres virement: " << endl;
    c1.afficher();
    c2.afficher();



    return 0;

}
