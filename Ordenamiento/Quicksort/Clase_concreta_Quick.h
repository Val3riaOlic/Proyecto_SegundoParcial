#ifndef CLASE_CONCRETA_QUICK_H
#define CLASE_CONCRETA_QUICK_H

#include "Clase_abstracta.h"

class Clase_concreta_Quick : public Clase_abstracta {
private:
    int particion(vector<Persona>& arr, int ini, int fin) {
        int pivote = arr[fin].getEdad();
        int i = ini - 1;

        for (int j = ini; j < fin; j++) {
            if (arr[j].getEdad() < pivote) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[fin]);
        return i + 1;
    }

    void quickSort(vector<Persona>& arr, int ini, int fin) {
        if (ini < fin) {
            int pi = particion(arr, ini, fin);
            quickSort(arr, ini, pi - 1);
            quickSort(arr, pi + 1, fin);
        }
    }

public:
    void ordenar(vector<Persona>& personas) {
        if (!personas.empty())
            quickSort(personas, 0, personas.size() - 1);
    }
};

#endif
