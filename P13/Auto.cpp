#include "Auto.h"

void Auto::setDatos(float p,int a,string m,string n,string apP,string apM,string g,int e){

    precio = p;
    anio = a;
    marca = m;

    nombre = n;
    ap = apP;
    am = apM;
    genero = g;
    edad = e;
}

void Auto::mostrarDatos(){

    cout << "\nDATOS DEL PROPIETARIO\n";
    cout << "Nombre: " << nombre << " " << ap << " " << am << endl;
    cout << "Genero: " << genero << endl;
    cout << "Edad: " << edad << endl;

    cout << "\nDATOS DEL AUTO\n";
    cout << "Marca: " << marca << endl;
    cout << "Precio: " << precio << endl;
    cout << "Anio: " << anio << endl;
}
