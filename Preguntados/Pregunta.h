//
// Created by Brandon Rutch on 12/4/19.
//

#ifndef PREGUNTADOS_PREGUNTA_H
#define PREGUNTADOS_PREGUNTA_H

#include <iostream>

using namespace std;


class Pregunta {
private:
    string pregunta;
    string respuesta;
    string opcionUno;
    string opcionDos;
    string opcionTres;
    string opcionCuatro;
    Pregunta* next;
    string estado;
public:
    Pregunta();

    Pregunta(string pPregunta, string pRespuesta, string pOpcion1, string pOpcion2, string pOpcion3, string pOpcion4);

    const string &getPregunta() const;

    void setPregunta(const string &pregunta);

    const string &getRespuesta() const;

    void setRespuesta(const string &respuesta);

    const string &getOpcionUno() const;

    void setOpcionUno(const string &opcionUno);

    const string &getOpcionDos() const;

    void setOpcionDos(const string &opcionDos);

    const string &getOpcionTres() const;

    void setOpcionTres(const string &opcionTres);

    const string &getOpcionCuatro() const;

    void setOpcionCuatro(const string &opcionCuatro);

    Pregunta *getNext() const;

    void setNext(Pregunta *next);

    const string &getEstado() const;

    void setEstado(const string &estado);

    string validarRespuesta(string respuesta);

    string toString();

    string toStringEstado();
};


#endif //PREGUNTADOS_PREGUNTA_H
