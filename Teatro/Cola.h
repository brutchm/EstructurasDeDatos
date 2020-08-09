//
// Created by Brandon Rutch on 12/1/19.
//

#ifndef TEATRO_COLA_H
#define TEATRO_COLA_H


#include "NodoCola.h"
class Cola
{
private:
    NodoCola *frente;
    NodoCola *fin;
    int longitud;
public:
    Cola();
    bool isEmpty();
    bool insertar(int);
    int atender();
    bool eliminarPos(int);
    bool buscar(int);
    int getLongitud();
    ~Cola();
};



#endif //TEATRO_COLA_H
