#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <queue>
#include "Estructura.h"

using namespace std;

class Cola : public Estructura {
private:
    queue<int> cola;  // ?? dato básico (int)
    int capacidad;

public:
    Cola(int cap) {
        capacidad = cap;
    }

    void agregar(int x) override {
        if (!estaLlena()) {
            cola.push(x);
            cout << "Elemento agregado: " << x << endl;
        } else {
            cout << "La cola esta llena.\n";
        }
    }

    void quitar() override {
        if (!estaVacia()) {
            cout << "Elemento eliminado: " << cola.front() << endl;
            cola.pop();
        } else {
            cout << "La cola esta vacia.\n";
        }
    }

    void mostrar() override {
        if (estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }

        queue<int> temp = cola;
        cout << "Contenido: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    bool estaVacia() override {
        return cola.empty();
    }

    bool estaLlena() override {
        return cola.size() == capacidad;
    }

    int tamanio() override {
        return cola.size();
    }
};

#endif
