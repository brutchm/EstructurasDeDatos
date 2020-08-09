//
// Created by Brandon Rutch on 12/1/19.
//

#ifndef TEATRO_NODOCOLA_H
#define TEATRO_NODOCOLA_H


class NodoCola
{
private:
    int idComprador;
    NodoCola *sig;
public:
    NodoCola();
    NodoCola(int);
    int getIdComprador();
    void setIdComprador(int);
    NodoCola * getSig();
    void setSig(NodoCola *);
    ~NodoCola();
};

#endif //TEATRO_NODOCOLA_H
