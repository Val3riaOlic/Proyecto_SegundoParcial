#include <iostream>
#include "Lista.h"

using namespace std;

int main() {
    int cap;
    cout << "Capacidad: ";
    cin >> cap;

    Lista l(cap);
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar\n2. Quitar\n3. Mostrar\n4. Vacia\n5. Llena\n6. Tamaño\n7. Salir\n";
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
