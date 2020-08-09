//
// Created by Brandon Rutch on 12/1/19.
//

#ifndef TEATRO_ASIENTO_H
#define TEATRO_ASIENTO_H


class Asiento
{
private:
    int numero;
    bool estado;
    int idComprador;
    bool ocupado;
    Asiento * sig;
public:
    Asiento();
    Asiento(int);
    ~Asiento();
    bool validarComprador(int);
    void setNumero(int);
    int getNumero();
    void setEstado(bool pEstado);
    bool getEstado();
    bool getOcupado();
    bool reservar(int);
    bool liberar();
    void comprar(int);
    void setSig(Asiento *);
    Asiento * getSig();
};

#endif //TEATRO_ASIENTO_H
