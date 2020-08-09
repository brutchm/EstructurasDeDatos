//
// Created by Brandon Rutch on 10/9/19.
//

#include "NodoContacto.h"
#include <string>

NodoContacto::NodoContacto() {
    nombre=" ";
    apellidos=" ";
    pais=" ";
    correo=" ";
    ptr= nullptr;
}

NodoContacto::NodoContacto(string pNombre, string pApellidos, string pPais, string pCorreo) {
    nombre=pNombre;
    apellidos=pApellidos;
    pais=pPais;
    correo=pCorreo;
    ptr= nullptr;
}

string NodoContacto::toString(){
    return "Nombre: "+nombre+" "+apellidos+", Pais: "+pais+ ", Correo: "+correo+".";

}

const string &NodoContacto::getNombre() const {
    return nombre;
}

void NodoContacto::setNombre(const string &nombre) {
    NodoContacto::nombre = nombre;
}

const string &NodoContacto::getApellidos() const {
    return apellidos;
}

void NodoContacto::setApellidos(const string &apellidos) {
    NodoContacto::apellidos = apellidos;
}

const string &NodoContacto::getPais() const {
    return pais;
}

void NodoContacto::setPais(const string &pais) {
    NodoContacto::pais = pais;
}

const string &NodoContacto::getCorreo() const {
    return correo;
}

void NodoContacto::setCorreo(const string &correo) {
    NodoContacto::correo = correo;
}

NodoContacto *NodoContacto::getPtr() const {
    return ptr;
}

void NodoContacto::setPtr(NodoContacto *ptr) {
    NodoContacto::ptr = ptr;
}
