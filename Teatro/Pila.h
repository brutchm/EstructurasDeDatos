//
// Created by Brandon Rutch on 12/1/19.
//

#ifndef TEATRO_PILA_H
#define TEATRO_PILA_H


#include "Asiento.h"
class Pila
{
private:
    Asiento * tope;
    int longitud;
public:
    Pila();
    ~Pila();
    bool push(int);
    int pop();
    int top();
    int getLongitud();
    bool isEmpty();
    void liberarAsientos();
    void imprimir();
    bool reservar(int);
    bool comprar(int);
};



#endif //TEATRO_PILA_H
