#ifndef CLASE_ABSTRACTA_H
#define CLASE_ABSTRACTA_H

#include <vector>
#include "Persona.h"

class Clase_abstracta {
public:
    virtual void ordenar(vector<Persona>& personas) = 0;
};

#endif
