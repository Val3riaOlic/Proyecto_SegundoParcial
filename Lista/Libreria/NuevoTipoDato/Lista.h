#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <vector>
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

class Lista : public Estructura {
private:
    vector<Persona> lista;
    int capacidad;

public:
    Lista(int cap) {
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

            lista.push_back(Persona(nombre, edad));
            cout << "Persona agregada.\n";
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
                cout << "Eliminando: "
                     << lista[pos].nombre
                     << " (" << lista[pos].edad << ")\n";

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

        cout << "Contenido:\n";
        for (int i = 0; i < lista.size(); i++) {
            cout << lista[i].nombre
                 << " - " << lista[i].edad << endl;
        }
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
