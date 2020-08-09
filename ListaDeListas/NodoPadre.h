//
// Created by Brandon Rutch on 11/18/19.
//

#ifndef LISTADELISTAS_NODOPADRE_H
#define LISTADELISTAS_NODOPADRE_H

#include <iostream>
#include "NodoHijo.h"

using namespace std;


class NodoPadre {
private:
    int info;
    NodoPadre* sig;
    NodoHijo* hijo;
public:
    NodoPadre();

    NodoPadre(int info);

    int getInfo() const;

    void setInfo(int info);

    NodoPadre *getSig() const;

    void setSig(NodoPadre *sig);

    NodoHijo *getHijo() const;

    void setHijo(NodoHijo *hijo);

    string toString();

};


#endif //LISTADELISTAS_NODOPADRE_H
