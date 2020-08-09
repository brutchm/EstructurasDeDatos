cmake_minimum_required(VERSION 3.15)
project(PilaPersona)

set(CMAKE_CXX_STANDARD 14)

add_executable(PilaPersona Contacto/main.cpp Contacto/NodoContacto.cpp Contacto/NodoContacto.h Contacto/ListaContacto.cpp Contacto/ListaContacto.h)