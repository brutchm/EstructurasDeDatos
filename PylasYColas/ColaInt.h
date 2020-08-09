//
// Created by Brandon Rutch on 11/8/19.
//

#ifndef PYLASYCOLAS_COLAINT_H
#define PYLASYCOLAS_COLAINT_H

#include <iostream>
#include "NodoInt.h"
#include "PilaInt.h"

using namespace std;

class ColaInt {
private:
    NodoInt* cab;
    int longitud;

public:
    ColaInt();

    NodoInt *getCab() const;

    void setCab(NodoInt *cab);

    int getLongitud() const;

    void setLongitud(int longitud);

    void agregarCola(int pInfo);

    void eliminarCola();

    void mostrar();

    void hacerPila(PilaInt* pPila);
};


#endif //PYLASYCOLAS_COLAINT_H
