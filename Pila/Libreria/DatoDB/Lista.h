#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stack>
#include "Estructura.h"

using namespace std;

class Pila : public Estructura {
private:
    stack<int> pila;
    int capacidad;

public:
    Pila(int cap) {
        capacidad = cap;
    }

    void agregar() {
        if (!estaLlena()) {
            int valor;
            cout << "Ingresa un numero: ";
            cin >> valor;

            pila.push(valor);
            cout << "Elemento agregado.\n";
        } else {
            cout << "La pila esta llena.\n";
        }
    }

    void quitar() {
        if (!estaVacia()) {
            cout << "Elemento eliminado: " << pila.top() << endl;
            pila.pop();
        } else {
            cout << "La pila esta vacia.\n";
        }
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La pila esta vacia.\n";
            return;
        }

        stack<int> temp = pila;

        cout << "Contenido (tope a base): ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    bool estaVacia() {
        return pila.empty();
    }

    bool estaLlena() {
        return pila.size() == capacidad;
    }

    int tamanio() {
        return pila.size();
    }
};

#endif
