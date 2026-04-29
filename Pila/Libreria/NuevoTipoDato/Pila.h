#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <stack>
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
    stack<Persona> pila;
    int capacidad;

public:
    Pila(int cap) {
        capacidad = cap;
    }

    void agregar() {
        if (!estaLlena()) {
            string nombre;
            int edad;

            cout << "Nombre: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;

            pila.push(Persona(nombre, edad));
            cout << "Persona agregada.\n";
        } else {
            cout << "La pila esta llena.\n";
        }
    }

    void quitar() {
        if (!estaVacia()) {
            Persona p = pila.top();
            cout << "Eliminando: " << p.nombre << " (" << p.edad << ")\n";
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

        stack<Persona> temp = pila;

        cout << "Contenido:\n";
        while (!temp.empty()) {
            cout << temp.top().nombre
                 << " - " << temp.top().edad << endl;
            temp.pop();
        }
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
