//
// Created by Brandon Rutch on 12/14/19.
//

#include "ListaJugador.h"

ListaJugador::ListaJugador() {
    this->cab = nullptr;
    this->longitud = 0;
}

Jugador *ListaJugador::getCab() const {
    return cab;
}

void ListaJugador::setCab(Jugador *cab) {
    ListaJugador::cab = cab;
}

int ListaJugador::getLongitud() const {
    return longitud;
}

void ListaJugador::setLongitud(int longitud) {
    ListaJugador::longitud = longitud;
}

ListaJugador::~ListaJugador() {

}

void ListaJugador::agregar(Jugador *info) {
    int cont = 0;
    if (getCab()== nullptr){
        setCab(info);
        longitud++;
    }else{
        Jugador* aux = getCab();
        while(aux!= nullptr){
            if(aux->getId() == info->getId()){
                aux->setPartidas(aux->getPartidas() + info->getPartidas());
                aux->setGanadas(aux->getGanadas()+ info->getGanadas());
                aux->setEmpate(aux->getEmpate() + info->getEmpate());
                aux->setPerdidas(aux->getPerdidas() + info->getPerdidas());
               cont ++;
            }
            aux= aux->getNext();
        }
        if(cont == 0){
            info->setNext(getCab());
            setCab(info);
        }

    }
}
string ListaJugador::toString() {
    string info;
    info = "Estadisticas de jugadores: \n";
    Jugador* aux = getCab();
    while(aux!= nullptr){
        info = info + aux->toString()+ "\n";
        aux = aux->getNext();
    }
    return info;
}

