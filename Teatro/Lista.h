//
// Created by Brandon Rutch on 12/1/19.
//

#ifndef TEATRO_LISTA_H
#define TEATRO_LISTA_H


#include "Asiento.h"
class Lista
{
private:
    Asiento * cabeza;
    int longitud;
public:
    Lista();
    Lista(int);
    ~Lista();
    //void setCabeza(Nodo *);
    //Asiento * getCabeza();
    void setLongitud(int);
    int getLongitud();
    int liberarAsientos();
    void imprimir();
    bool reservarPos(int, int);
    int reservar(int);
    bool comprar(int, int);
    int mostrarRecursivo(Asiento *);

    void agregar(int);
    void agregarOrdenado(int);
    bool esVacia();
    int buscar(int);
    bool eliminar(int);
    bool eliminarPos(int);
};


#endif //TEATRO_LISTA_H
