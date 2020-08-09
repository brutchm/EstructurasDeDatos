//
// Created by Brandon Rutch on 12/14/19.
//

#ifndef PREGUNTADOS_JUGADOR_H
#define PREGUNTADOS_JUGADOR_H

#include <iostream>


using namespace std;

class Jugador {
private:
    Jugador* next;
    string id;
    string nombre;
    int partidas;
    int ganadas;
    int empate;
    int perdidas;
public:
    Jugador();

    Jugador(const string &id, const string &nombre, int partidas, int ganadas, int empate, int perdidas);

    const string &getId() const;

    void setId(const string &id);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    int getPartidas() const;

    void setPartidas(int partidas);

    int getGanadas() const;

    void setGanadas(int ganadas);

    int getEmpate() const;

    void setEmpate(int empate);

    int getPerdidas() const;

    void setPerdidas(int perdidas);

    string toString();

    Jugador *getNext() const;

    void setNext(Jugador *next);

};


#endif //PREGUNTADOS_JUGADOR_H
