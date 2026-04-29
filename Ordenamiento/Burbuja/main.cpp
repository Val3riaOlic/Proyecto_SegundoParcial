#include <iostream>
#include <vector>
#include "Clase_concreta_Burbuja.h"
#include <limits>
using namespace std;

void mostrar(vector<Persona>& personas) {
    for (int i = 0; i < personas.size(); i++) {
    personas[i].mostrar();
}
}

int main() {
    vector<Persona> personas;
    Clase_concreta_Burbuja ordenador;
    int op;

    do {
        cout << "\n1. Agregar\n2. Mostrar\n3. Ordenar Burbuja\n4. Salir\nOpcion: ";
        cin >> op;

        if (op == 1) {
            string nombre;
            int edad;
            cout << "Nombre: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, nombre); 
            cout << "Edad: ";
            cin >> edad;
             
            if (cin.fail()) {
   				cin.clear();
   				cin.ignore(1000, '\n');
    			cout << "Entrada invalida\n";
    			continue;
				}
            personas.push_back(Persona(nombre, edad));
        } 
        else if (op == 2) {
            mostrar(personas);
        } 
        else if (op == 3) {
            ordenador.ordenar(personas);
            cout << "Ordenado.\n";
        }

    } while (op != 4);

    return 0;
}
