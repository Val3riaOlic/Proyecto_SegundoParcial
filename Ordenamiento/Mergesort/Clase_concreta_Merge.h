#ifndef CLASE_CONCRETA_MERGE_H
#define CLASE_CONCRETA_MERGE_H

#include "Clase_abstracta.h"

class Clase_concreta_Merge : public Clase_abstracta {
private:
    void merge(vector<Persona>& arr, int ini, int mid, int fin) {
        vector<Persona> temp;
        int i = ini, j = mid + 1;

        while (i <= mid && j <= fin) {
            if (arr[i].getEdad() <= arr[j].getEdad())
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= fin) temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++) {
            arr[ini + k] = temp[k];
        }
    }

    void mergeSort(vector<Persona>& arr, int ini, int fin) {
        if (ini < fin) {
            int mid = (ini + fin) / 2;
            mergeSort(arr, ini, mid);
            mergeSort(arr, mid + 1, fin);
            merge(arr, ini, mid, fin);
        }
    }

public:
    void ordenar(vector<Persona>& personas) {
        if (!personas.empty())
            mergeSort(personas, 0, personas.size() - 1);
    }
};

#endif
