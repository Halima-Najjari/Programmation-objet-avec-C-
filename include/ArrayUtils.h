#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

#include "common.h"

namespace ArrayUtils {

void saisie(int T[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << " : ";
        cin >> T[i];
    }
}

void affiche(int T[], int n) {
    for (int i = 0; i < n; i++) {
        cout << T[i] << " ";
    }
    cout << endl;
}

int maximum(int T[], int n) {
    int max = T[0];
    for (int i = 1; i < n; i++) {
        if (T[i] > max) {
            max = T[i];
        }
    }
    return max;
}

void triDecroissant(int T[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (T[j] < T[j + 1]) {
                int temp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = temp;
            }
        }
    }
}

void supprimerOccurrence(int T[], int &n, int val) {
    for (int i = 0; i < n; i++) {
        if (T[i] == val) {
            for (int j = i; j < n - 1; j++) {
                T[j] = T[j + 1];
            }
            n--;
            i--;
        }
    }
}

void decalerGauche(int T[], int n) {
    for (int i = 0; i < n - 1; i++) {
        T[i] = T[i + 1];
    }
}

} // namespace ArrayUtils

#endif // ARRAYUTILS_H
