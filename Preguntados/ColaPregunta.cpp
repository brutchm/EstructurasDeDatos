//
// Created by Brandon Rutch on 12/4/19.
//

#include "ColaPregunta.h"

ColaPregunta::ColaPregunta() {
    this->longitud=0;
    this->fin= nullptr;
    this->inicio= nullptr;
}

ColaPregunta::~ColaPregunta() {

}

Pregunta *ColaPregunta::getInicio() const {
    return inicio;
}

void ColaPregunta::setInicio(Pregunta *inicio) {
    ColaPregunta::inicio = inicio;
}

Pregunta *ColaPregunta::getFin() const {
    return fin;
}

void ColaPregunta::setFin(Pregunta *fin) {
    ColaPregunta::fin = fin;
}

int ColaPregunta::getLongitud() const {
    return longitud;
}

void ColaPregunta::setLongitud(int longitud) {
    ColaPregunta::longitud = longitud;
}

bool ColaPregunta::esVacia() {
    if (getLongitud()== 0){
        return true;
    }else{
        false;
    }
}

void ColaPregunta::insertar(Pregunta* pPregunta) {
    if(esVacia()){
        setInicio(pPregunta);
        setFin(pPregunta);
        setLongitud(getLongitud()+1);
    }else{
        Pregunta* aux =getFin();
        aux->setNext(pPregunta);
        setFin(pPregunta);
        setLongitud(getLongitud()+1);
    }
}

string ColaPregunta::atender() {
    if (!esVacia()) {
        string info;
        Pregunta *aux = getInicio();
        setInicio(aux->getNext());
        info = aux->toStringEstado();
        longitud--;
        return info;
    } else {
        return nullptr;
    }
}