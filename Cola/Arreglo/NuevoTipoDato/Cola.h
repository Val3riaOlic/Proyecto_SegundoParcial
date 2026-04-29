#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>
#include "Estructura.h"

using namespace std;

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

class Cola : public Estructura {
private:
    Persona* arreglo;
    int frente;
    int fin;
    int capacidad;

public:
    Cola(int cap) {
        capacidad = cap;
        arreglo = new Persona[cap];
        frente = 0;
        fin = -1;
    }

    void agregar() override {
        if (!estaLlena()) {
            string nombre;
            int edad;

            cout << "Nombre: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;

            fin++;
            arreglo[fin] = Persona(nombre, edad);

            cout << "Persona agregada.\n";
        } else {
            cout << "La cola esta llena.\n";
        }
    }

    void quitar() override {
        if (!estaVacia()) {
            Persona p = arreglo[frente];
            cout << "Eliminando: " << p.nombre << " (" << p.edad << ")\n";
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

        cout << "Contenido:\n";
        for (int i = frente; i <= fin; i++) {
            cout << arreglo[i].nombre << " - " << arreglo[i].edad << endl;
        }
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
