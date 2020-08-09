//
// Created by Brandon Rutch on 10/9/19.
//

#ifndef PILAPERSONA_LISTACONTACTO_H
#define PILAPERSONA_LISTACONTACTO_H


#include <ostream>
#include "NodoContacto.h"

class ListaContacto {

private:

    NodoContacto* cab;
    int longitud;

public:
    ListaContacto();
    virtual ~ListaContacto();
    NodoContacto *getCab() const;
    void setCab(NodoContacto *cab);
    void agregarInicio(NodoContacto*);
    int getLongitud() const;
    void setLongitud(int longitud);
    void aumentar();
    void disminuir();
    void mostrar();
    bool listaVacia();
    string buscar(string);
    void agregarOrdenado(string, string, string, string);
    bool eliminar(string);
    bool eliminarPos(int);

};


#endif //PILAPERSONA_LISTACONTACTO_H
