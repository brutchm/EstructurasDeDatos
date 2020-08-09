//
// Created by Brandon Rutch on 12/14/19.
//

#include "Jugador.h"

Jugador::Jugador() {
    this->id=" ";
    this->nombre=" ";
    this->partidas, this->empate, this->ganadas, this->perdidas = 0;
    this->next = nullptr;
}

Jugador::Jugador(const string &id, const string &nombre, int partidas, int ganadas, int empate, int perdidas) : id(id),
                                                                                                                nombre(nombre),
                                                                                                                partidas(
                                                                                                                        partidas),
                                                                                                                ganadas(ganadas),
                                                                                                                empate(empate),
                                                                                                                perdidas(
                                                                                                                        perdidas) {
    this->next= nullptr;
}

const string &Jugador::getId() const {
    return id;
}

void Jugador::setId(const string &id) {
    Jugador::id = id;
}

const string &Jugador::getNombre() const {
    return nombre;
}

void Jugador::setNombre(const string &nombre) {
    Jugador::nombre = nombre;
}

int Jugador::getPartidas() const {
    return partidas;
}

void Jugador::setPartidas(int partidas) {
    Jugador::partidas = partidas;
}

int Jugador::getGanadas() const {
    return ganadas;
}

void Jugador::setGanadas(int ganadas) {
    Jugador::ganadas = ganadas;
}

int Jugador::getEmpate() const {
    return empate;
}

void Jugador::setEmpate(int empate) {
    Jugador::empate = empate;
}

int Jugador::getPerdidas() const {
    return perdidas;
}

void Jugador::setPerdidas(int perdidas) {
    Jugador::perdidas = perdidas;
}

string Jugador::toString() {
    return "Jugador: " + this->nombre+", Partidas: "+ to_string(this->partidas)+", Ganes: "+ to_string(this->ganadas)+", Empate: "+to_string(this->empate)+", Perdidas: "+to_string(this->perdidas)+".";
}

Jugador *Jugador::getNext() const {
    return next;
}

void Jugador::setNext(Jugador *next) {
    Jugador::next = next;
}
