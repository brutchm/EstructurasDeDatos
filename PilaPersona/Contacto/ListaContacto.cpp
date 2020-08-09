//
// Created by Brandon Rutch on 10/9/19.
//

#include "ListaContacto.h"
#include <iostream>

using namespace std;

ListaContacto::ListaContacto() {
    cab= nullptr;
    longitud=0;
}

ListaContacto::~ListaContacto() {

}

NodoContacto *ListaContacto::getCab() const {
    return cab;
}

void ListaContacto::setCab(NodoContacto *cab) {
    ListaContacto::cab = cab;
}

int ListaContacto::getLongitud() const {
    return longitud;
}

void ListaContacto::setLongitud(int longitud) {
    ListaContacto::longitud = longitud;
}

void ListaContacto::mostrar() {
    NodoContacto *aux = getCab();
    while (aux != nullptr) {
        cout << aux->toString() << endl;
        aux = aux->getPtr();
    }
};

bool ListaContacto::listaVacia() {
    if (cab == nullptr) {
        return true;
    }
    return false;
}

string ListaContacto::buscar(string pNombre) {
    NodoContacto *aux = getCab();
    while (aux != nullptr) {
        if (aux->getNombre()== pNombre) {
            return aux->toString();
        }else{
            return"No existe";
        }
    }
};

bool ListaContacto::eliminar(string nombre) {
    if (!listaVacia()) {
        if (cab->getNombre() == nombre) {
            NodoContacto* aux = cab;
            cab = cab->getPtr();
            delete aux;
            longitud--;
            return true;
        }
        else
        {
            NodoContacto* ant = getCab();
            NodoContacto* act = getCab()->getPtr();
            while (act != nullptr) {
                if (act->getNombre() == nombre) {
                    ant->setPtr(act->getPtr());
                    delete act;
                    longitud--;
                    return true;
                }
                ant = ant->getPtr();
                act = act->getPtr();
            }

        }
    }
    return false;
};\

void ListaContacto::agregarOrdenado(string nombre, string apellido, string pais, string correo) {
    NodoContacto* nuevo = new NodoContacto(nombre, apellido, pais, correo);
    if (getCab() == nullptr) {
        setCab(nuevo);
        longitud++;
    }
    else {
        char nombreNuevo [nuevo->getNombre().size()+1];
        char nombreCab[getCab()->getNombre().size()+1];
        nuevo->getNombre().copy(nombreNuevo, nuevo->getNombre().size()+1);
        getCab()->getNombre().copy(nombreCab, getCab()->getNombre().size()+1);
        nombreNuevo[nuevo->getNombre().size()]='\0';
        nombreCab[getCab()->getNombre().size()]='\0';
        if (strcoll(nombreNuevo, nombreCab)==0) {
            agregarInicio(nuevo);
        }
        else
        {
            NodoContacto *ant = getCab();
            NodoContacto *act = getCab()->getPtr();

            while (act != nullptr && strcoll(nombreNuevo, nombreCab)<0) {
                ant = ant->getPtr();
                act = act->getPtr();
            }
            nuevo->setPtr(ant->getPtr());
            ant->setPtr(nuevo);
            longitud++;
        }
    }
}

void ListaContacto::agregarInicio(NodoContacto* nuevo) {

    if (getCab() == nullptr) {
        setCab(nuevo);

    }
    else {
        nuevo->setPtr(cab);
        cab = nuevo;
    }
    longitud++;
};

bool ListaContacto::eliminarPos(int n) {
    if (!listaVacia() && !(n > longitud)) {
        NodoContacto* ant = cab;
        NodoContacto* act = cab->getPtr();
        for (int i = 1; i < n; i++) {
            ant = ant->getPtr();
            act = act->getPtr();
        }
        ant->setPtr(act->getPtr());
        delete act;
        --longitud;
        return true;
    }
    else {
        return false;
    }
}
