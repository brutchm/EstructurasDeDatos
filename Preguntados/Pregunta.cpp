//
// Created by Brandon Rutch on 12/4/19.
//

#include "Pregunta.h"

Pregunta::Pregunta() {
    this->pregunta = " ";
    this->pregunta = " ";
    this->opcionUno = " ";
    this->opcionDos = " ";
    this->opcionTres = " ";
    this->opcionCuatro = " ";
    this->next = nullptr;
    this->estado = " ";
}

Pregunta::Pregunta(string pPregunta, string pRespuesta, string pOpcion1, string pOpcion2, string pOpcion3, string pOpcion4) {
    this->pregunta = pPregunta;
    this->respuesta = pRespuesta;
    this->opcionUno = pOpcion1;
    this->opcionDos = pOpcion2;
    this->opcionTres = pOpcion3;
    this->opcionCuatro = pOpcion4;
    this->next = nullptr;
    this->estado = " ";
}

const string &Pregunta::getPregunta() const {
    return pregunta;
}

void Pregunta::setPregunta(const string &pregunta) {
    Pregunta::pregunta = pregunta;
}

const string &Pregunta::getRespuesta() const {
    return respuesta;
}

void Pregunta::setRespuesta(const string &respuesta) {
    Pregunta::respuesta = respuesta;
}

const string &Pregunta::getOpcionUno() const {
    return opcionUno;
}

void Pregunta::setOpcionUno(const string &opcionUno) {
    Pregunta::opcionUno = opcionUno;
}

const string &Pregunta::getOpcionDos() const {
    return opcionDos;
}

void Pregunta::setOpcionDos(const string &opcionDos) {
    Pregunta::opcionDos = opcionDos;
}

const string &Pregunta::getOpcionTres() const {
    return opcionTres;
}

void Pregunta::setOpcionTres(const string &opcionTres) {
    Pregunta::opcionTres = opcionTres;
}

const string &Pregunta::getOpcionCuatro() const {
    return opcionCuatro;
}

void Pregunta::setOpcionCuatro(const string &opcionCuatro) {
    Pregunta::opcionCuatro = opcionCuatro;
}

Pregunta *Pregunta::getNext() const {
    return next;
}

void Pregunta::setNext(Pregunta *next) {
    Pregunta::next = next;
}

const string &Pregunta::getEstado() const {
    return estado;
}

void Pregunta::setEstado(const string &estado) {
    Pregunta::estado = estado;
}

string Pregunta::validarRespuesta(string respuesta) {
    if(getRespuesta()== respuesta){
        setEstado("Correcto");
        return getEstado();
    }else{
        setEstado("Incorrecto");
        return getEstado();
    }
}

string Pregunta::toString() {
    return "Pregunta: "+getPregunta()+"\n"+
    "Opciones:" + "\t" + getOpcionUno() + "\t" + getOpcionDos() + "\t" + getOpcionTres() + "\t" + getOpcionCuatro()+"\n"+
    " Escriba la opción correcta:";
}

string Pregunta::toStringEstado() {
    return "Pregunta: "+getPregunta()+", Repuesta correcta: "+getRespuesta()+", Su respuesta fue: "+getEstado();
}