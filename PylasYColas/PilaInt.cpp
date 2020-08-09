//
// Created by Brandon Rutch on 11/8/19.
//

#include "PilaInt.h"
#include <iostream>

using namespace std;

PilaInt::PilaInt() {
    this->cab= nullptr;
    this->longitud=0;
}

NodoInt *PilaInt::getCab() const {
    return cab;
}

void PilaInt::setCab(NodoInt *cab) {
    PilaInt::cab = cab;
}

int PilaInt::getLongitud() const {
    return longitud;
}

void PilaInt::setLongitud(int longitud) {
    PilaInt::longitud = longitud;
}

void PilaInt::agregarPila(int pInfo) {
    NodoInt* tmpNodo = new NodoInt(pInfo);
    if (getCab()== nullptr){
        setCab(tmpNodo);
        longitud++;
    }else{
        tmpNodo->setSiguiente(getCab());
        setCab(tmpNodo);
        longitud++;
    };
}

void PilaInt::eliminarPila() {
    if (getCab()== nullptr){
        return;
    }else{
        NodoInt* ant = getCab();
        setCab(ant->getSiguiente());
        delete(ant);
        longitud--;
    }
}

void PilaInt::mostrar() {
    NodoInt * aux = getCab();
    while (aux!= nullptr){
       cout << aux->toString()<<endl;
    }
}

void PilaInt::hacerCola(ColaInt * pCola) {
    NodoInt * aux = getCab();
    while (aux!= nullptr){
        pCola->agregarCola(aux->getInfo());
        aux= aux->getSiguiente();
    }
}

