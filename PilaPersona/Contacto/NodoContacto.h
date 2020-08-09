//
// Created by Brandon Rutch on 10/9/19.
//

#ifndef PILAPERSONA_NODOCONTACTO_H
#define PILAPERSONA_NODOCONTACTO_H


#include <ostream>
using namespace std;

class NodoContacto {
private:
    string nombre;
    string apellidos;
    string pais;
    string correo;
    NodoContacto* ptr;

public:
    NodoContacto();

    NodoContacto(string nombre, string apellidos, string pais, string correo);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getApellidos() const;

    void setApellidos(const string &apellidos);

    const string &getPais() const;

    void setPais(const string &pais);

    const string &getCorreo() const;

    void setCorreo(const string &correo);

    NodoContacto *getPtr() const;

    void setPtr(NodoContacto *ptr);

    string toString();

};


#endif //PILAPERSONA_NODOCONTACTO_H
