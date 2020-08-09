//
// Created by Brandon Rutch on 11/18/19.
//

#include "NodoHijo.h"

NodoHijo::NodoHijo() {}

NodoHijo::NodoHijo(int info) {
    this->info = info;
    this->sig = nullptr;
}

int NodoHijo::getInfo() const {
    return info;
}

void NodoHijo::setInfo(int info) {
    NodoHijo::info = info;
}

NodoHijo *NodoHijo::getSig() const {
    return sig;
}

void NodoHijo::setSig(NodoHijo *sig) {
    NodoHijo::sig = sig;
}

string NodoHijo::toStrinf() {
    return "Numero:"+this->info;
}
