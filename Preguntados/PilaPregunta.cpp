//
// Created by Brandon Rutch on 12/4/19.
//

#include "PilaPregunta.h"

PilaPregunta::PilaPregunta() {
    this->top = nullptr;
    this->longitud = 0;
}

PilaPregunta::~PilaPregunta() {}

Pregunta *PilaPregunta::getTop() const {
    return top;
}

void PilaPregunta::setTop(Pregunta *top) {
    PilaPregunta::top = top;
}

int PilaPregunta::getLongitud() const {
    return longitud;
}

void PilaPregunta::setLongitud(int longitud) {
    PilaPregunta::longitud = longitud;
}

void PilaPregunta::buscarEnLista(ListaPregunta* pLista) {
    Pregunta* tmpPregunta;
    for (int i = 0; i < 10;){
        int randomValue = rand()%100+1;
        if(randomValue <= pLista->getLongitud()){
            tmpPregunta = pLista->buscar(randomValue);
            push(tmpPregunta);
            i++;
        }else{
            randomValue = rand()%100+1;
        }
    }
}

void PilaPregunta::push(Pregunta *pPregunta) {
    pPregunta->setNext(getTop());
    setTop(pPregunta);
    setLongitud(getLongitud()+1);
}

Pregunta* PilaPregunta::pop() {
        Pregunta* tmpPregunta = getTop();
        setTop(tmpPregunta->getNext());
        setLongitud(getLongitud()-1);
        return tmpPregunta;
}

bool PilaPregunta::esVacia() {
    if (longitud == 0){
        return true;
    }else{
        return false;
    }
}