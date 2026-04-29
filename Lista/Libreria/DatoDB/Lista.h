#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <vector>
#include "Estructura.h"

using namespace std;

class Lista : public Estructura {
private:
    vector<int> lista;
    int capacidad;

public:
    Lista(int cap) {
        capacidad = cap;
    }

    void agregar() {
        if (!estaLlena()) {
            int valor;
            cout << "Ingresa un numero: ";
            cin >> valor;

            lista.push_back(valor);
            cout << "Elemento agregado.\n";
        } else {
            cout << "La lista esta llena.\n";
        }
    }

    void quitar() {
        if (!estaVacia()) {
            int pos;
            cout << "Posicion a eliminar (0 a " << lista.size()-1 << "): ";
            cin >> pos;

            if (pos >= 0 && pos < lista.size()) {
                cout << "Eliminado: " << lista[pos] << endl;
                lista.erase(lista.begin() + pos);
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
        for (int i = 0; i < lista.size(); i++) {
            cout << lista[i] << " ";
        }
        cout << endl;
    }

    bool estaVacia() {
        return lista.empty();
    }

    bool estaLlena() {
        return lista.size() == capacidad;
    }

    int tamanio() {
        return lista.size();
    }
};

#endif
