#include <iostream>
#include "Auto.h"

using namespace std;

int main(){

    Auto lista[3];
    Auto *p;

    p = lista;

    float precio;
    int anio;
    string marca;

    string nombre, ap, am, genero;
    int edad;

    for(int i = 0; i < 3; i++){

        cout << "\nPersona " << i+1 << endl;

        cout << "Nombre: ";
        cin >> nombre;

        cout << "Apellido paterno: ";
        cin >> ap;

        cout << "Apellido materno: ";
        cin >> am;

        cout << "Genero: ";
        cin >> genero;

        cout << "Edad: ";
        cin >> edad;

        cout << "Marca del auto: ";
        cin >> marca;

        cout << "Precio: ";
        cin >> precio;

        cout << "Anio: ";
        cin >> anio;

        (p + i)->setDatos(precio, anio, marca, nombre, ap, am, genero, edad);
    }

    cout << "\n----- LISTA DE PERSONAS Y AUTOS -----\n";

    for(int i = 0; i < 3; i++){
        (p + i)->mostrarDatos();
    }

    return 0;
}
