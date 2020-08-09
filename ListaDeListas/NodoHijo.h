//
// Created by Brandon Rutch on 11/18/19.
//

#ifndef LISTADELISTAS_NODOHIJO_H
#define LISTADELISTAS_NODOHIJO_H

#include <iostream>

using namespace std;


class NodoHijo {
private:
    int info;
    NodoHijo* sig;
public:
    NodoHijo(int info);

    NodoHijo();

    int getInfo() const;

    void setInfo(int info);

    NodoHijo *getSig() const;

    void setSig(NodoHijo *sig);

    string toStrinf();

};


#endif //LISTADELISTAS_NODOHIJO_H
