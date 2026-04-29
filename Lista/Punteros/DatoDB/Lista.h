#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Estructura.h"

using namespace std;

// ?? Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Lista : public Estructura {
private:
    Nodo* cabeza;
    int contador;

public:
    Lista() {
        cabeza = NULL;
        contador = 0;
    }

    void agregar() {
        int valor;
        cout << "Ingresa un numero: ";
        cin >> valor;

        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        if (estaVacia()) {
            cabeza = nuevo;
        } else {
            Nodo* aux = cabeza;
            while (aux->siguiente != NULL) {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
        }

        contador++;
        cout << "Elemento agregado.\n";
    }

    void quitar() {
        if (!estaVacia()) {
            int pos;
            cout << "Posicion a eliminar (0 a " << contador-1 << "): ";
            cin >> pos;

            if (pos >= 0 && pos < contador) {
                Nodo* temp = cabeza;

                if (pos == 0) {
                    cabeza = cabeza->siguiente;
                } else {
                    Nodo* anterior = NULL;
                    for (int i = 0; i < pos; i++) {
                        anterior = temp;
                        temp = temp->siguiente;
                    }
                    anterior->siguiente = temp->siguiente;
                }

                cout << "Eliminado: " << temp->dato << endl;
                delete temp;
                contador--;
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

        Nodo* aux = cabeza;
        cout << "Contenido: ";
        while (aux != NULL) {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        }
        cout << endl;
    }

    bool estaVacia() {
        return cabeza == NULL;
    }

    bool estaLlena() {
        return false;
    }

    int tamanio() {
        return contador;
    }
};

#endif
