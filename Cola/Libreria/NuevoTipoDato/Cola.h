#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <queue>
#include <string>
#include "Estructura.h"

using namespace std;

// ?? Nuevo tipo de dato
class Persona {
public:
    string nombre;
    int edad;

    Persona() {}

    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }
};

// ?? Clase Cola
class Cola : public Estructura {
private:
    queue<Persona> cola;
    int capacidad;

public:
    Cola(int cap) {
        capacidad = cap;
    }

    void agregar() override {
        if (!estaLlena()) {
            string nombre;
            int edad;

            cout << "Nombre: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;

            Persona p(nombre, edad);
            cola.push(p);

            cout << "Persona agregada.\n";
        } else {
            cout << "La cola esta llena.\n";
        }
    }

    void quitar() override {
        if (!estaVacia()) {
            Persona p = cola.front();
            cout << "Eliminando: " << p.nombre << " (" << p.edad << ")\n";
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

        queue<Persona> temp = cola;
        cout << "Contenido:\n";

        while (!temp.empty()) {
            Persona p = temp.front();
            cout << p.nombre << " - " << p.edad << endl;
            temp.pop();
        }
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
