#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    Lista l;
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar\n";
        cout << "2. Quitar\n";
        cout << "3. Mostrar\n";
        cout << "4. Vacia\n";
        cout << "5. Llena\n";
        cout << "6. Tamaño\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: l.agregar(); break;
        case 2: l.quitar(); break;
        case 3: l.mostrar(); break;
        case 4: cout << (l.estaVacia() ? "Vacia\n" : "No vacia\n"); break;
        case 5: cout << (l.estaLlena() ? "Llena\n" : "No llena\n"); break;
        case 6: cout << "Tamaño: " << l.tamanio() << endl; break;
        }

    } while (opcion != 7);

    return 0;
}
