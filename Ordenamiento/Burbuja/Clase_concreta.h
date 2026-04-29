#ifndef CLASE_CONCRETA_BURBUJA_H
#define CLASE_CONCRETA_BURBUJA_H

#include "Clase_abstracta.h"

class Clase_concreta_Burbuja : public Clase_abstracta {
public:
    void ordenar(vector<Persona>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j].getEdad() > arr[j + 1].getEdad()) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

#endif
