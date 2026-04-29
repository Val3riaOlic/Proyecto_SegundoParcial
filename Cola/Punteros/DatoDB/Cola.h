#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "Estructura.h"

using namespace std;

//  Nodo con int
struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Cola : public Estructura {
private:
    Nodo* frente;
    Nodo* fin;
    int contador;

public:
    Cola() {
       	frente = NULL;
		fin = NULL;
        contador = 0;
    }

    void agregar() override {
        int valor;
        cout << "Ingresa un numero: ";
        cin >> valor;

       	Nodo* nuevo = new Nodo;
		nuevo->dato = valor;
		nuevo->siguiente = NULL;

        if (estaVacia()) {
            frente = fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }

        contador++;
        cout << "Elemento agregado.\n";
    }

    void quitar() override {
        if (!estaVacia()) {
            Nodo* temp = frente;
            cout << "Elemento eliminado: " << temp->dato << endl;

            frente = frente->siguiente;
            delete temp;
            contador--;

            if (frente == NULL)
                fin = NULL;    
        } else {
            cout << "La cola esta vacia.\n";
        }
    }

    void mostrar() override {
        if (estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }

        Nodo* aux = frente;
        cout << "Contenido: ";
        while (aux != NULL) {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    }

    bool estaVacia() override {
        return frente == NULL;
    }

    bool estaLlena() override {
        return false; // dinámica
    }

    int tamanio() override {
        return contador;
    }
};

#endif
