//
// Created by Brandon Rutch on 11/8/19.
//

#include "ColaInt.h"
#include "PilaInt.h"

ColaInt::ColaInt() {
    this->cab = nullptr;
    this->longitud = 0;
}

NodoInt *ColaInt::getCab() const {
    return cab;
}

void ColaInt::setCab(NodoInt *cab) {
    ColaInt::cab = cab;
}

int ColaInt::getLongitud() const {
    return longitud;
}

void ColaInt::setLongitud(int longitud) {
    ColaInt::longitud = longitud;
}

void ColaInt::agregarCola(int pInfo) {
    NodoInt* tmpNodo = new NodoInt(pInfo);
    if (getCab()== nullptr){
        setCab(tmpNodo);
        longitud++;
    }else{
        if (getCab()->getSiguiente()== nullptr){
            getCab()->setSiguiente(tmpNodo);
        }else{
            NodoInt* ant = getCab();
            NodoInt* sig = getCab()->getSiguiente();

            while (sig!= nullptr){
                ant = sig;
                sig = sig->getSiguiente();
            }
            sig->setSiguiente(tmpNodo);
        }
    }
}

void ColaInt::mostrar() {
    NodoInt * aux = getCab();
    while (aux!= nullptr){
        cout << aux->toString()<<endl;
    }
}

void ColaInt::hacerPila(PilaInt* pPila) {
    NodoInt * aux = getCab();
    while (aux!= nullptr){
        pPila->agregarPila(aux->getInfo());
        aux= aux->getSiguiente();
    }
}
