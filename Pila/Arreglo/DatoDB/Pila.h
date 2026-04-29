#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "Estructura.h"

using namespace std;

class Pila : public Estructura {
private:
    int* arreglo;
    int tope;
    int capacidad;

public:
    Pila(int cap) {
        capacidad = cap;
        arreglo = new int[cap];
        tope = -1;
    }

    void agregar() { // push
        if (!estaLlena()) {
            int valor;
            cout << "Ingresa un numero: ";
            cin >> valor;

            tope++;
            arreglo[tope] = valor;

            cout << "Elemento agregado.\n";
        } else {
            cout << "La pila esta llena.\n";
        }
    }

    void quitar() { // pop
        if (!estaVacia()) {
            cout << "Elemento eliminado: " << arreglo[tope] << endl;
            tope--;
        } else {
            cout << "La pila esta vacia.\n";
        }
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La pila esta vacia.\n";
            return;
        }

        cout << "Contenido (tope a base): ";
        for (int i = tope; i >= 0; i--) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
    }

    bool estaVacia() {
        return tope == -1;
    }

    bool estaLlena() {
        return tope == capacidad - 1;
    }

    int tamanio() {
        return tope + 1;
    }
};

#endif
