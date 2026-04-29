#include <iostream>
#include "Pila.h"

using namespace std;

int main() {
    Pila p;
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Mostrar\n";
        cout << "4. Vacia\n";
        cout << "5. Llena\n";
        cout << "6. Tamaño\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: p.agregar(); break;
        case 2: p.quitar(); break;
        case 3: p.mostrar(); break;
        case 4: cout << (p.estaVacia() ? "Vacia\n" : "No vacia\n"); break;
        case 5: cout << (p.estaLlena() ? "Llena\n" : "No llena\n"); break;
        case 6: cout << "Tamaño: " << p.tamanio() << endl; break;
        }

    } while (opcion != 7);

    return 0;
}
