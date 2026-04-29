#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Estructura.h"

using namespace std;

class Lista : public Estructura {
private:
    int* arreglo;
    int capacidad;
    int elementos;

public:
    Lista(int cap) {
        capacidad = cap;
        elementos = 0;
        arreglo = new int[cap];
    }

    void agregar() {
        if (!estaLlena()) {
            int valor;
            cout << "Ingresa un numero: ";
            cin >> valor;

            arreglo[elementos] = valor;
            elementos++;

            cout << "Elemento agregado.\n";
        } else {
            cout << "La lista esta llena.\n";
        }
    }

    void quitar() {
        if (!estaVacia()) {
            int pos;
            cout << "Posicion a eliminar (0 a " << elementos-1 << "): ";
            cin >> pos;

            if (pos >= 0 && pos < elementos) {
                cout << "Eliminado: " << arreglo[pos] << endl;

                for (int i = pos; i < elementos - 1; i++) {
                    arreglo[i] = arreglo[i + 1];
                }

                elementos--;
            } else {
                cout << "Posicion invalida.\n";
            }
        } else {
            cout << "La lista esta vacia.\n";
        }
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La lista esta vacia.\n";
            return;
        }

        cout << "Contenido: ";
        for (int i = 0; i < elementos; i++) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
    }

    bool estaVacia() {
        return elementos == 0;
    }

    bool estaLlena() {
        return elementos == capacidad;
    }

    int tamanio() {
        return elementos;
    }
};

#endif
