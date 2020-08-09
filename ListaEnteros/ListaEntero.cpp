//
// Created by Brandon Rutch on 10/22/19.
//

#include "ListaEntero.h"

using namespace std;

ListaEntero::ListaEntero() {
    this->cab = nullptr;
    this->longitud = 0;
}

ListaEntero::ListaEntero(NodoEntero* pCab) {
    this->cab = pCab;
    this->longitud = 1;
}

void ListaEntero::setCab(NodoEntero *pCab) {
    this->cab = pCab;
}

NodoEntero* ListaEntero::getCab(){
    return this->cab;
}

void ListaEntero::disminuirLongitud() {
    this->longitud = longitud--;
}

void ListaEntero::aumentarLongitud() {
    this->longitud = longitud++;
}

void ListaEntero::agregarInicio(int info) {
    NodoEntero* tmpNodo = new NodoEntero(info);
    if (getCab() == nullptr){
        setCab(tmpNodo);
    }else{
        tmpNodo ->setPtr(cab);
        cab = tmpNodo;
    }
}

void ListaEntero::agregarOdenado(int info) {
    NodoEntero* tmpNodo = new NodoEntero(info);
    if (getCab() == nullptr){
        setCab(tmpNodo);
    }else{
        if (info < cab->getInfo()){
            agregarInicio(info);
        }else{
            NodoEntero* anterior = getCab();
            NodoEntero* actual = anterior->getPtr();
            while (actual != nullptr) {
                if (info > anterior->getInfo() && info < actual->getInfo()){
                    tmpNodo->setPtr(actual);
                    anterior->setPtr(tmpNodo);
                    return;
                }else{
                    anterior = anterior->getPtr();
                    actual = actual->getPtr();
                }
            }
            tmpNodo->setPtr(actual);
            anterior->setPtr(tmpNodo);
        }
    }
}

string vacia(){
    NodoEntero* tmpNodo = getCab
    if ()
}

string buscar(int info);

string eliminarNum(int info);

string eliminarPos(int pos);

string mostrarLista();

string mostrarLongitud();