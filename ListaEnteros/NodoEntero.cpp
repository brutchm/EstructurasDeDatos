//
// Created by Brandon Rutch on 10/22/19.
//

#include "NodoEntero.h"

NodoEntero::NodoEntero() {
    this->info = 0;
    this->ptr = nullptr;
}

NodoEntero::NodoEntero(int pInfo) {
    this->info = pInfo;
    this->ptr = nullptr;
}

void NodoEntero::setInfo(int pInfo) {
    this->info = pInfo;
}

int NodoEntero::getInfo() {
    return this->info;
}

void NodoEntero::setPtr(NodoEntero * pPtr) {
    this->ptr = pPtr;
}

NodoEntero* NodoEntero::getPtr() {
    return this->ptr;
}

string NodoEntero::toString() {
    return "El numero es: " + info + ", posicion  de memoria: " + ptr;
}