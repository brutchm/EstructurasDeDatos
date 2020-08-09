//
// Created by Brandon Rutch on 11/8/19.
//

#include "NodoInt.h"
#include <ostream>

using namespace std;

NodoInt::NodoInt() {
    this->info=0;
    this->siguiente= nullptr;
}

NodoInt::NodoInt(int info){
    this->info= info;
    this->siguiente= nullptr;
}

int NodoInt::getInfo() const {
    return info;
}

void NodoInt::setInfo(int info) {
    NodoInt::info = info;
}

NodoInt *NodoInt::getSiguiente() const {
    return siguiente;
}

void NodoInt::setSiguiente(NodoInt *siguiente) {
    NodoInt::siguiente = siguiente;
}


string NodoInt::toString() {
    return "El numero es: "+ this->info;
}