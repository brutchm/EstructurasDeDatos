//
// Created by Brandon Rutch on 12/4/19.
//

#include "ListaPregunta.h"

ListaPregunta::ListaPregunta() {
    this->cab = nullptr;
    this->longitud = 0;
}

Pregunta *ListaPregunta::getCab() const {
    return cab;
}

void ListaPregunta::setCab(Pregunta *cab) {
    ListaPregunta::cab = cab;
}

int ListaPregunta::getLongitud() const {
    return longitud;
}

void ListaPregunta::setLongitud(int longitud) {
    ListaPregunta::longitud = longitud;
}

Pregunta* ListaPregunta::buscar(int pPos) {
    int pos = 1;

    if (pPos == pos) {
        Pregunta *aux = getCab();
        setCab(getCab()->getNext());
        return aux;
    }else {
        pos++;

        Pregunta *anterior = getCab();
        Pregunta *actual = getCab()->getNext();

        while (actual != nullptr) {
            if (pos == pPos) {
                anterior->setNext(actual->getNext());
                return actual;
            }
            pos++;
        }
    }
    return nullptr;
}

void ListaPregunta::agregar(string pPregunta, string pRespuesta, string pOpcion1, string pOpcion2, string pOpcion3, string pOpcion4) {
    Pregunta* tmpPregunta = new Pregunta(pPregunta, pRespuesta, pOpcion1, pOpcion2, pOpcion3, pOpcion4);
    if (this->cab == nullptr){
        setCab(tmpPregunta);
    }else{
        tmpPregunta->setNext(getCab());
        setCab(tmpPregunta);
    }
    setLongitud(getLongitud()+1);
}

ListaPregunta::~ListaPregunta() {}
