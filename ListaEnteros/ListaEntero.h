//
// Created by Brandon Rutch on 10/22/19.
//

#ifndef LISTAENTEROS_LISTAENTERO_H
#define LISTAENTEROS_LISTAENTERO_H


#include "NodoEntero.h"

class ListaEntero {
private:
    NodoEntero* cab;
    int longitud;
public:
    ListaEntero();

    ListaEntero(NodoEntero* pCab);

    void setCab(NodoEntero* pCab);

    void aumentarLongitud();

    void disminuirLongitud();

    void agregarInicio(int info);

    void agregarOdenado(int info);

    string vacia();

    string buscar(int info);

    string eliminarNum(int info);

    string eliminarPos(int pos);

    string mostrarLista();

    string mostrarLongitud();
};


#endif //LISTAENTEROS_LISTAENTERO_H
