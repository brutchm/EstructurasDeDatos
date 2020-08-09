//
// Created by Brandon Rutch on 11/18/19.
//

#include "NodoPadre.h"

NodoPadre::NodoPadre() {}

NodoPadre::NodoPadre(int infoo) {
    this->info = infoo;
    this->hijo = nullptr;
    this->sig = nullptr;
}

int NodoPadre::getInfo() const {
    return info;
}

void NodoPadre::setInfo(int info) {
    NodoPadre::info = info;
}

NodoPadre *NodoPadre::getSig() const {
    return sig;
}

void NodoPadre::setSig(NodoPadre *sig) {
    NodoPadre::sig = sig;
}

NodoHijo *NodoPadre::getHijo() const {
    return hijo;
}

void NodoPadre::setHijo(NodoHijo *hijo) {
    NodoPadre::hijo = hijo;
}

string NodoPadre::toString() {
    return "Numero: "+this->info;
}