#include <iostream>
#include "Cola.h"

using namespace std;

int main() {
    int cap;
    cout << "Capacidad de la cola: ";
    cin >> cap;

    Cola c(cap);

    int opcion, valor;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar elemento\n";
        cout << "2. Quitar elemento\n";
        cout << "3. Mostrar contenido\n";
        cout << "4. Verificar si esta vacia\n";
        cout << "5. Verificar si esta llena\n";
        cout << "6. Mostrar tamaño\n";
        cout << "7. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingresa un numero: ";
            cin >> valor;
            c.agregar(valor);
            break;

        case 2:
            c.quitar();
            break;

        case 3:
            c.mostrar();
            break;

        case 4:
            cout << (c.estaVacia() ? "Esta vacia\n" : "No esta vacia\n");
            break;

        case 5:
            cout << (c.estaLlena() ? "Esta llena\n" : "No esta llena\n");
            break;

        case 6:
            cout << "Tamaño actual: " << c.tamanio() << endl;
            break;

        case 7:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 7);

    return 0;
}
