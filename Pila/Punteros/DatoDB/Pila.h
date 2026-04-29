#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "Estructura.h"

using namespace std;

// ?? Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Pila : public Estructura {
private:
    Nodo* tope;
    int contador;

public:
    Pila() {
        tope = NULL;
        contador = 0;
    }

    void agregar() { // push
        int valor;
        cout << "Ingresa un numero: ";
        cin >> valor;

        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = tope;

        tope = nuevo;
        contador++;

        cout << "Elemento agregado.\n";
    }

    void quitar() { // pop
        if (!estaVacia()) {
            Nodo* temp = tope;

            cout << "Elemento eliminado: " << temp->dato << endl;

            tope = tope->siguiente;
            delete temp;
            contador--;
        } else {
            cout << "La pila esta vacia.\n";
        }
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La pila esta vacia.\n";
            return;
        }

        Nodo* aux = tope;
        cout << "Contenido (tope a base): ";
        while (aux != NULL) {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    }

    bool estaVacia() {
        return tope == NULL;
    }

    bool estaLlena() {
        return false; // dinámica
    }

    int tamanio() {
        return contador;
    }
};

#endif
