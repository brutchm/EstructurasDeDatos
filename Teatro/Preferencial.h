//
// Created by Brandon Rutch on 12/1/19.
//

#ifndef TEATRO_PREFERENCIAL_H
#define TEATRO_PREFERENCIAL_H


#include "Pila.h"
#include "Lista.h"
#include <iostream>
#include <string>
using namespace std;

class Preferencial
{
private:
    Pila * asientos;
    int * reservas;
    int capacidad;
    int disponibles;
    int comprados;
    double costo;
public:
    Preferencial(int, double);
    ~Preferencial();
    void liberarAsientos();
    void reservarAsiento(int);
    void comprarAsientoReservado(int);
    void comprarAsiento();
    void mostrar();
    void info();
    int getCapacidad();
    int getDisponibles();
    int getComprados();
    double getCosto();
};


#endif //TEATRO_PREFERENCIAL_H
