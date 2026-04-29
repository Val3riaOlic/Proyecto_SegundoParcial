#ifndef AUTO_H
#define AUTO_H

#include <iostream>
#include <string>
using namespace std;

class Auto {

private:
    float precio;
    int anio;
    string marca;

    string nombre;
    string ap;
    string am;
    string genero;
    int edad;

public:
    void setDatos(float p,int a,string m,string n,string apP,string apM,string g,int e);
    void mostrarDatos();

};

#endif
