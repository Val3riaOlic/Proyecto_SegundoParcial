#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>
#include "Estructura.h"

using namespace std;

// ?? Tipo de dato propio
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

// ?? Nodo
struct Nodo {
    Persona dato;
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

    void agregar() {
        string nombre;
        int edad;

        cout << "Nombre: ";
        cin >> nombre;
        cout << "Edad: ";
        cin >> edad;

        Nodo* nuevo = new Nodo;
        nuevo->dato = Persona(nombre, edad);
        nuevo->siguiente = NULL;

        if (estaVacia()) {
            frente = nuevo;
            fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }

        contador++;
        cout << "Persona agregada.\n";
    }

    void quitar() {
        if (!estaVacia()) {
            Nodo* temp = frente;

            cout << "Eliminando: "
                 << temp->dato.nombre
                 << " (" << temp->dato.edad << ")\n";

            frente = frente->siguiente;
            delete temp;
            contador--;

            if (frente == NULL) {
                fin = NULL;
            }
        } else {
            cout << "La cola esta vacia.\n";
        }
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }

        Nodo* aux = frente;
        cout << "Contenido:\n";

        while (aux != NULL) {
            cout << aux->dato.nombre
                 << " - " << aux->dato.edad << endl;
            aux = aux->siguiente;
        }
    }

    bool estaVacia() {
        return frente == NULL;
    }

    bool estaLlena() {
        return false; // dinámica
    }

    int tamanio() {
        return contador;
    }
};

#endif
