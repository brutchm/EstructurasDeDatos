//
// Created by Brandon Rutch on 12/4/19.
//

#ifndef PREGUNTADOS_LISTAPREGUNTA_H
#define PREGUNTADOS_LISTAPREGUNTA_H


#include "Pregunta.h"

class ListaPregunta {
private:
    Pregunta * cab;
    int longitud;

public:
    ListaPregunta();

    virtual ~ListaPregunta();

    Pregunta *getCab() const;

    void setCab(Pregunta *cab);

    int getLongitud() const;

    void setLongitud(int longitud);

    Pregunta* buscar(int);

    void agregar(string pPregunta, string pRespuesta, string pOpcion1, string pOpcion2, string pOpcion3, string pOpcion4);


};


#endif //PREGUNTADOS_LISTAPREGUNTA_H
