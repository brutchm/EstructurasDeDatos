//
// Created by Brandon Rutch on 11/18/19.
//

#ifndef LISTADELISTAS_LISTA_H
#define LISTADELISTAS_LISTA_H

#include <iostream>
#include "NodoPadre.h"

using namespace std;


class Lista {
private:
    NodoPadre * cab;

public:
    Lista();

    Lista(NodoPadre *cab);

    NodoPadre *getCab() const;

    void setCab(NodoPadre *cab);

    void agregarInicio(int info);

    bool agregarOrdenadoPadre(int info);

    void agregarInicioHijo(int info, int padre);

    bool agregarHijo(int infoP, int infoH);

    void imprimirLista();

};


#endif //LISTADELISTAS_LISTA_H
