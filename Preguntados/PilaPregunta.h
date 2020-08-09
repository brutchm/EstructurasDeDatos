//
// Created by Brandon Rutch on 12/4/19.
//

#ifndef PREGUNTADOS_PILAPREGUNTA_H
#define PREGUNTADOS_PILAPREGUNTA_H


#include "Pregunta.h"
#include "ListaPregunta.h"

class PilaPregunta {
private:
    Pregunta*  top;
    int longitud;

public:
    PilaPregunta();

    virtual ~PilaPregunta();

    Pregunta *getTop() const;

    void setTop(Pregunta *top);

    int getLongitud() const;

    void setLongitud(int longitud);

    void buscarEnLista(ListaPregunta* pLista);

    void push(Pregunta* pPregunta);

    Pregunta*  pop();

    bool esVacia();
};


#endif //PREGUNTADOS_PILAPREGUNTA_H
