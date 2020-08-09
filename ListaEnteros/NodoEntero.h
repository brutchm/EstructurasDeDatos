//
// Created by Brandon Rutch on 10/22/19.
//

#ifndef LISTAENTEROS_NODOENTERO_H
#define LISTAENTEROS_NODOENTERO_H

#include <ostream>

using namespace std;


class NodoEntero {
private:
    int info;
    NodoEntero* ptr;

public:
    NodoEntero();

    NodoEntero(int pInfo);

    void setInfo(int pInfo);

    int getInfo();

    void setPtr(NodoEntero* pPtr);

    NodoEntero* getPtr();

    string toString();
};


#endif //LISTAENTEROS_NODOENTERO_H
