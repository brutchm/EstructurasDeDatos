//
// Created by Brandon Rutch on 11/8/19.
//

#ifndef PYLASYCOLAS_PILAINT_H
#define PYLASYCOLAS_PILAINT_H


#include "NodoInt.h"
#include "ColaInt.h"

class PilaInt {
private:
    NodoInt* cab;
    int longitud;
public:
    PilaInt();

    NodoInt *getCab() const;

    void setCab(NodoInt *cab);

    int getLongitud() const;

    void setLongitud(int longitud);

    void agregarPila(int pInfo);

    void eliminarPila();

    void mostrar();

    void hacerCola(ColaInt* pCola);
};


#endif //PYLASYCOLAS_PILAINT_H
