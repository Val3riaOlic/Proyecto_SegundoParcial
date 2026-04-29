#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <string>
#include "Estructura.h"

using namespace std;

class Persona {
public:
    string nombre;
    int edad;

    Persona() {
        nombre = "";
        edad = 0;
    }

    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }
};

class Pila : public Estructura {
private:
    Persona* arreglo;
    int tope;
    int capacidad;

public:
    Pila(int cap) {
        capacidad = cap;
        arreglo = new Persona[cap];
        tope = -1;
    }

    void agregar() {
        if (!estaLlena()) {
            string nombre;
            int edad;

            cout << "Nombre: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;

            tope++;
            arreglo[tope] = Persona(nombre, edad);

            cout << "Persona agregada.\n";
        } else {
            cout << "La pila esta llena.\n";
        }
    }

    void quitar() {
        if (!estaVacia()) {
            cout << "Eliminando: "
                 << arreglo[tope].nombre
                 << " (" << arreglo[tope].edad << ")\n";

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

        cout << "Contenido (tope a base):\n";
        for (int i = tope; i >= 0; i--) {
            cout << arreglo[i].nombre
                 << " - " << arreglo[i].edad << endl;
        }
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
