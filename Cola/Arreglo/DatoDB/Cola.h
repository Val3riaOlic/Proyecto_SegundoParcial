#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "Estructura.h"

using namespace std;

class Cola : public Estructura {
private:
    int* arreglo;
    int frente;
    int fin;
    int capacidad;

public:
    Cola(int cap) {
        capacidad = cap;
        arreglo = new int[cap];
        frente = 0;
        fin = -1;
    }

    void agregar() override {
        if (!estaLlena()) {
            int valor;
            cout << "Ingresa un numero: ";
            cin >> valor;

            fin++;
            arreglo[fin] = valor;

            cout << "Elemento agregado.\n";
        } else {
            cout << "La cola esta llena.\n";
        }
    }

    void quitar() override {
        if (!estaVacia()) {
            cout << "Elemento eliminado: " << arreglo[frente] << endl;
            frente++;
        } else {
            cout << "La cola esta vacia.\n";
        }
    }

    void mostrar() override {
        if (estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }

        cout << "Contenido: ";
        for (int i = frente; i <= fin; i++) {
            cout << arreglo[i] << " ";
        }
        cout << endl;
    }

    bool estaVacia() override {
        return frente > fin;
    }

    bool estaLlena() override {
        return fin == capacidad - 1;
    }

    int tamanio() override {
        return (fin - frente + 1);
    }
};

#endif
