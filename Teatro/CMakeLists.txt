cmake_minimum_required(VERSION 3.15)
project(Teatro)

set(CMAKE_CXX_STANDARD 14)

add_executable(Teatro main.cpp Asiento.cpp Asiento.h Cola.cpp Cola.h General.cpp General.h Lista.cpp Lista.h NodoCola.cpp NodoCola.h Pila.cpp Pila.h Preferencial.cpp Preferencial.h Reserva.cpp Reserva.h Vip.cpp Vip.h)