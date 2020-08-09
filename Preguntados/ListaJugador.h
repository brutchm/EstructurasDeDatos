//
// Created by Brandon Rutch on 12/14/19.
//

#ifndef PREGUNTADOS_LISTAJUGADOR_H
#define PREGUNTADOS_LISTAJUGADOR_H


#include "Jugador.h"
#include <iostream>

using namespace std;

class ListaJugador {
private:
    Jugador* cab;
    int longitud;
public:
    ListaJugador();

    Jugador *getCab() const;

    void setCab(Jugador *cab);

    int getLongitud() const;

    void setLongitud(int longitud);

    void agregar(Jugador* info);

    string toString();


    virtual ~ListaJugador();
};


#endif //PREGUNTADOS_LISTAJUGADOR_H
