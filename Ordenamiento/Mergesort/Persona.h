#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona() {}
    Persona(string n, int e) : nombre(n), edad(e) {}

    int getEdad() { return edad; }
    string getNombre() { return nombre; }

    void mostrar() {
        cout << "Nombre: " << nombre << " | Edad: " << edad << endl;
    }
};

#endif
