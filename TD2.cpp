#include "common.h"
#include "ArrayUtils.h"

// Domain-specific array filters (not general-purpose enough for ArrayUtils)

void affiche_8(int T[], int n) {
    for (int i = 0; i < n; i++) {
        if (T[i] % 10 == 8) {
            cout << T[i] << " ";
        }
    }
    cout << endl;
}

int nombre_3(int T[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] % 3 == 0) {
            cout << T[i] << " ";
            count++;
        }
    }
    cout << endl;
    return count;
}

void ajout_dernier_chiffre(int T[], int n) {
    for (int i = 0; i < n; i++) {
        if (T[i] % 10 == 2) {
            T[i] += 5;
        }
    }
}

int occurrence_max(int T[], int n) {
    int maxOcc = 0;
    int valeur = T[0];

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (T[i] == T[j]) {
                count++;
            }
        }
        if (count > maxOcc) {
            maxOcc = count;
            valeur = T[i];
        }
    }
    return valeur;
}

int nain1() {
    int n;
    cout << "Donner la taille : ";
    cin >> n;

    int *T = new int[n];

    ArrayUtils::saisie(T, n);

    cout << "Tableau : ";
    ArrayUtils::affiche(T, n);

    cout << "Maximum : " << ArrayUtils::maximum(T, n) << endl;

    cout << "Se terminent par 8 : ";
    affiche_8(T, n);

    cout << "Multiples de 3 : ";
    int nb3 = nombre_3(T, n);
    cout << "Total = " << nb3 << endl;

    ajout_dernier_chiffre(T, n);
    cout << "Apres ajout (+5 si finit par 2) : ";
    ArrayUtils::affiche(T, n);

    cout << "Valeur la plus repetee : " << occurrence_max(T, n) << endl;

    ArrayUtils::triDecroissant(T, n);
    cout << "Tableau trie (decroissant) : ";
    ArrayUtils::affiche(T, n);

    int val;
    cout << "Valeur a supprimer : ";
    cin >> val;
    ArrayUtils::supprimerOccurrence(T, n, val);
    cout << "Apres suppression : ";
    ArrayUtils::affiche(T, n);

    ArrayUtils::decalerGauche(T, n);
    cout << "Apres decalage gauche : ";
    ArrayUtils::affiche(T, n);

    delete[] T;
    return 0;
}
