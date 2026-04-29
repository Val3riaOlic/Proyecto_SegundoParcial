#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <string>
#include "Estructura.h"

using namespace std;

//Tipo de dato
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

//Nodo
struct Nodo {
    Persona dato;
    Nodo* siguiente;
};

class Pila : public Estructura {
private:
    Nodo* tope;
    int contador;

public:
    Pila() {
        tope = NULL;
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
        nuevo->siguiente = tope;

        tope = nuevo;
        contador++;

        cout << "Persona agregada.\n";
    }

    void quitar() {
        if (!estaVacia()) {
            Nodo* temp = tope;

            cout << "Eliminando: "
                 << temp->dato.nombre
                 << " (" << temp->dato.edad << ")\n";

            tope = tope->siguiente;
            delete temp;
            contador--;
        } else {
            cout << "La pila esta vacia.\n";
        }
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "La pila esta vacia.\n";
            return;
        }

        Nodo* aux = tope;

        cout << "Contenido:\n";
        while (aux != NULL) {
            cout << aux->dato.nombre
                 << " - " << aux->dato.edad << endl;
            aux = aux->siguiente;
        }
    }

    bool estaVacia() {
        return tope == NULL;
    }

    bool estaLlena() {
        return false;
    }

    int tamanio() {
        return contador;
    }
};

#endif
