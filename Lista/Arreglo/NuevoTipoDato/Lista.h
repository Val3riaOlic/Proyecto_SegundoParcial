#ifndef LISTA_H
#define LISTA_H

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

class Lista : public Estructura {
private:
    Persona* arreglo;
    int capacidad;
    int elementos;

public:
    Lista(int cap) {
        capacidad = cap;
        elementos = 0;
        arreglo = new Persona[cap];
    }

    void agregar() {
        if (!estaLlena()) {
            string nombre;
            int edad;

            cout << "Nombre: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;

            arreglo[elementos] = Persona(nombre, edad);
            elementos++;

            cout << "Persona agregada.\n";
        } else {
            cout << "La lista esta llena.\n";
        }
    }

    void quitar() {
        if (!estaVacia()) {
            int pos;
            cout << "Posicion a eliminar (0 a " << elementos-1 << "): ";
            cin >> pos;

            if (pos >= 0 && pos < elementos) {
                cout << "Eliminando: "
                     << arreglo[pos].nombre
                     << " (" << arreglo[pos].edad << ")\n";

                for (int i = pos; i < elementos - 1; i++) {
                    arreglo[i] = arreglo[i + 1];
                }

                elementos--;
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

        cout << "Contenido:\n";
        for (int i = 0; i < elementos; i++) {
            cout << arreglo[i].nombre
                 << " - " << arreglo[i].edad << endl;
        }
    }

    bool estaVacia() {
        return elementos == 0;
    }

    bool estaLlena() {
        return elementos == capacidad;
    }

    int tamanio() {
        return elementos;
    }
};

#endif
