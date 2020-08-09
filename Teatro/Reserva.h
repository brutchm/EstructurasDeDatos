//
// Created by Brandon Rutch on 12/1/19.
//

#ifndef TEATRO_RESERVA_H
#define TEATRO_RESERVA_H

#include <string>
using namespace std;
class Reserva
{
private:
    int id;
    string nombre;
    int asiento;
public:
    Reserva();
    Reserva(int, string, int);
    ~Reserva();
    void setId(int);
    int getId();
    void setNombre(string);
    string getNombre();
    string toString();
};


#endif //TEATRO_RESERVA_H
