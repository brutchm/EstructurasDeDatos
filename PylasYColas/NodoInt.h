//
// Created by Brandon Rutch on 11/8/19.
//

#ifndef PYLASYCOLAS_NODOINT_H
#define PYLASYCOLAS_NODOINT_H

#include <ostream>

using namespace std;

class NodoInt {
private:
    int info;
    NodoInt* siguiente;
public:
    NodoInt();

    NodoInt(int info);

    int getInfo() const;

    void setInfo(int info);

    NodoInt *getSiguiente() const;

    void setSiguiente(NodoInt *siguiente);

    string toString ();

};


#endif //PYLASYCOLAS_NODOINT_H
