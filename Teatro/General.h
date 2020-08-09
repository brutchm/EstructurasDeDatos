//
// Created by Brandon Rutch on 12/1/19.
//

#ifndef TEATRO_GENERAL_H
#define TEATRO_GENERAL_H


#include "Lista.h"
#include <iostream>
#include <string>
using namespace std;
class General
{
private:
    Lista * asientos;
    int capacidad;
    int disponibles;
    int comprados;
    double costo;
public:
    General(int, double);
    ~General();
    void liberarAsientos();
    void reservarAsiento(int);
    void comprarAsiento(int, int);
    void mostrar();
    void info();
    int getCapacidad();
    int getDisponibles();
    int getComprados();
    double getCosto();
};


#endif //TEATRO_GENERAL_H
