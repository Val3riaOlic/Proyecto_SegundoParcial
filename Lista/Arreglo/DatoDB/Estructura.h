#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

class Estructura {
public:
    virtual void agregar() = 0;
    virtual void quitar() = 0;
    virtual void mostrar() = 0;
    virtual bool estaVacia() = 0;
    virtual bool estaLlena() = 0;
    virtual int tamanio() = 0;

    virtual ~Estructura() {}
};

#endif
