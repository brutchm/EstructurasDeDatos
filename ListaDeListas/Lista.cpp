//
// Created by Brandon Rutch on 11/18/19.
//

#include "Lista.h"

Lista::Lista() {}

Lista::Lista(NodoPadre *cab) : cab(cab) {}

NodoPadre *Lista::getCab() const {
    return cab;
}

void Lista::setCab(NodoPadre *cab) {
    Lista::cab = cab;
}

void Lista::agregarInicio(int info) {
    NodoPadre* tmpNodo = new NodoPadre(info);
    if (getCab() == nullptr){
        setCab(tmpNodo);
    }else{
        tmpNodo ->setSig(cab);
        cab = tmpNodo;
    }
}

bool Lista::agregarOrdenadoPadre(int info) {
    NodoPadre* tmpNP = new NodoPadre(info);
    if (getCab() == nullptr){
        setCab(tmpNP);
    }else{
        if (info < cab->getInfo()){
            agregarInicio(info);
        }else{
            NodoPadre* anterior = getCab();
            NodoPadre* actual = anterior->getSig();
            while (actual != nullptr) {
                if (info > anterior->getInfo() && info < actual->getInfo()){
                    tmpNP->setSig(actual);
                    anterior->setSig(tmpNP);
                    return true;
                }else{
                    anterior = anterior->getSig();
                    actual = actual->getSig();
                }
            }
            tmpNP->setSig(actual);
            anterior->setSig(tmpNP);
        }
    }
}

void Lista::agregarInicioHijo(int info, int padre) {
    NodoPadre *aux = getCab();

    while (aux != nullptr) {
        if (aux->getInfo() == padre) {
            NodoHijo* tmpH = new NodoHijo(info);
            if (aux->getHijo() == nullptr){
                aux->setHijo(tmpH);
            }else{
                tmpH ->setSig(aux->getHijo()->getSig());
                aux->setHijo(tmpH) ;
            }
        }
        aux = aux->getSig();
    }
}

bool Lista::agregarHijo(int infoP, int infoH) {
    NodoPadre *aux = getCab();

    while (aux != nullptr) {
        if (aux->getInfo() == infoP) {


            NodoHijo* tmpNH = new NodoHijo(infoH);
            if (aux->getHijo()== nullptr){
                aux->setHijo(tmpNH);
            }else{
                if (infoH < aux->getHijo()->getInfo()){
                    agregarInicioHijo(infoH, infoP);
                }else{
                    NodoHijo* anterior = aux->getHijo();
                    NodoHijo* actual = anterior->getSig();
                    while (actual != nullptr && infoH > actual->getInfo()) {
                        if (infoH > anterior->getInfo() && infoH < actual->getInfo()){
                            tmpNH->setSig(actual);
                            anterior->setSig(tmpNH);
                            return true;
                        }
                    }
                    tmpNH->setSig(actual);
                    anterior->setSig(tmpNH);
                }
            }




        }
        aux = aux->getSig();
    }
}