#include "common.h"
#include "chaine.h"
#include "Complexe.h"
#include "Fraction.h"
#include "Produit.h"
#include "Cercle.h"
#include "CompteBancaire.h"

int main() {
    // --- chaine ---
    chaine ch1("Hello");
    chaine ch2("World");

    cout << "--- Affichage initial ---" << endl;
    ch1.afficher();
    ch2.afficher();

    cout << "\n--- Test Concatenation ---" << endl;
    ch1.concatenation(ch2);
    ch1.afficher();

    cout << "\n--- Test Acces au caractere d'index 4 ---" << endl;
    cout << "Le caractere est: " << ch1.acces(4) << endl;

    cout << "\n--- Test Comparaison ---" << endl;
    ch1.comparaison(ch2);

    // --- Complexe ---
    Complexe comp1(3, 4);
    Complexe comp2(1, -2);

    cout << "Complexe 1 : ";
    comp1.affiche();

    cout << "Complexe 2 : ";
    comp2.affiche();

    cout << "Conjugue de Complexe 1 : ";
    comp1.conjugue().affiche();

    cout << "Somme : ";
    comp1.somme(comp2).affiche();

    cout << "Difference : ";
    comp1.difference(comp2).affiche();

    cout << "Produit : ";
    comp1.produit(comp2).affiche();

    cout << "Norme de Complexe 1 : "
         << comp1.norme() << endl;

    // --- Fraction ---
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

    // --- Produit (now uses constructor instead of initialiser()) ---
    Produit p(123, 10.5, 20);

    cout << "=== Produit initial ===" << endl;
    p.afficher();

    cout << "Prix TTC : " << p.calculerPrixTTC() << endl;
    cout << "Prix total du stock : " << p.prix_total() << endl;

    p.retirer(5);

    cout << endl;
    cout << "=== Apres retrait ===" << endl;
    p.afficher();

    p.ajouter(10);

    cout << endl;
    cout << "=== Apres ajout ===" << endl;
    p.afficher();

    // --- Cercle (now uses constructor instead of initialiser()) ---
    Cercle cercle(5, 0, 0);
    cercle.afficher();
    cout << "Surface: " << cercle.calculerSurface() << endl;
    cout << "Perimetre: " << cercle.calculerPerimetre() << endl;

    cercle.deplacer(2, 3);
    cout << "Apres deplacement: ";
    cercle.afficher();

    cercle.agrandir(2);
    cout << "Apres agrandissement: ";
    cercle.afficher();

    // --- CompteBancaire ---
    CompteBancaire cb1(1, 1000), cb2(2, 500);
    cb1.afficher();
    cb2.afficher();
    cb1.deposer(200);
    cout << "Apres depot: " << endl;
    cb1.afficher();
    cb1.retirer(150);
    cout << "Apres retrait: " << endl;
    cb1.afficher();
    cb1.virement(cb2, 300);
    cout << "Apres virement: " << endl;
    cb1.afficher();
    cb2.afficher();

    return 0;
}
