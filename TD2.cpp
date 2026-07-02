#include <iostream>
using namespace std;

// saisie
void saisie(int T[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Element " << i+1 << " : ";
        cin >> T[i];
    }
}

// affichage
void affiche(int T[], int n) {
    for(int i = 0; i < n; i++) {
        cout << T[i] << " ";
    }
    cout << endl;
}

// maximum
int maximum(int T[], int n) {
    int max = T[0];
    for(int i = 1; i < n; i++) {
        if(T[i] > max) {
            max = T[i];
        }
    }
    return max;
}

// affiche nombres finissant par 8
void affiche_8(int T[], int n) {
    for(int i = 0; i < n; i++) {
        if(T[i] % 10 == 8) {
            cout << T[i] << " ";
        }
    }
    cout << endl;
}

// multiples de 3
int nombre_3(int T[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(T[i] % 3 == 0) {
            cout << T[i] << " ";
            count++;
        }
    }
    cout << endl;
    return count;
}

// ajouter 5 aux nombres finissant par 2
void ajout_dernier_chiffre(int T[], int n) {
    for(int i = 0; i < n; i++) {
        if(T[i] % 10 == 2) {
            T[i] += 5;
        }
    }
}

// valeur la plus répétée
int occurrence_max(int T[], int n) {
    int maxOcc = 0;
    int valeur = T[0];

    for(int i = 0; i < n; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(T[i] == T[j]) {
                count++;
            }
        }

        if(count > maxOcc) {
            maxOcc = count;
            valeur = T[i];
        }
    }
    return valeur;
}

int tri_decroissant (int T[], int n) {
    int temp;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(T[j] < T[j+1]) {
                temp = T[j];
                T[j] = T[j+1];
                T[j+1] = temp;
            }
        }
    }

   return 1;
}
// supprimer occurrence
void Supp_occurrence(int T[], int &n, int val) {
    for(int i = 0; i < n; i++) {
        if(T[i] == val) {
            for(int j = i; j < n-1; j++) {
                T[j] = T[j+1];
            }
            n--;
            i--; // important pour re-vérifier
        }
    }
}

// décalage gauche
void Decale_gauche(int T[], int n) {
    for(int i = 0; i < n-1; i++) {
        T[i] = T[i+1];
    }
}

int nain1() {
    int n;
    cout << "Donner la taille : ";
    cin >> n;

    int *T = new int[n];

    saisie(T, n);

    cout << "Tableau : ";
    affiche(T, n);

    cout << "Maximum : " << maximum(T, n) << endl;

    cout << "Se terminent par 8 : ";
    affiche_8(T, n);

    cout << "Multiples de 3 : ";
    int nb3 = nombre_3(T, n);
    cout << "Total = " << nb3 << endl;

    ajout_dernier_chiffre(T, n);
    cout << "Apres ajout (+5 si finit par 2) : ";
    affiche(T, n);

    cout << "Valeur la plus repetee : " << occurrence_max(T, n) << endl;

    tri_decroissant(T, n);
    cout << "Tableau trie (decroissant) : ";
    affiche(T, n);

    int val;
    cout << "Valeur a supprimer : ";
    cin >> val;
    Supp_occurrence(T, n, val);
    cout << "Apres suppression : ";
    affiche(T, n);

    Decale_gauche(T, n);
    cout << "Apres decalage gauche : ";
    affiche(T, n);

    delete[] T;
    return 0;
}
