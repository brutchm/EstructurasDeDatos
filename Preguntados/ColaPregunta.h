//
// Created by Brandon Rutch on 12/4/19.
//

#ifndef PREGUNTADOS_COLAPREGUNTA_H
#define PREGUNTADOS_COLAPREGUNTA_H


#include "Pregunta.h"

class ColaPregunta {
private:
    Pregunta* inicio;
    Pregunta* fin;
    int longitud;
public:
    ColaPregunta();

    virtual ~ColaPregunta();

    Pregunta *getInicio() const;

    void setInicio(Pregunta *inicio);

    Pregunta *getFin() const;

    void setFin(Pregunta *fin);

    int getLongitud() const;

    void setLongitud(int longitud);

    bool esVacia();

    void insertar(Pregunta* pPregunta);

    string atender();



};


#endif //PREGUNTADOS_COLAPREGUNTA_H
