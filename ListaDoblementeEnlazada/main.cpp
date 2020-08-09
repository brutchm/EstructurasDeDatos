#include <iostream>
#include "ListaDoble.h"

using namespace std;

int main()
{
    ListaDoble ld;

    ld.agregarNodo(new NodoDoble(1));
    ld.agregarNodo(new NodoDoble(2));
    ld.agregarNodo(new NodoDoble(3));

    ld.agregarNodo(new NodoDoble(100000),3);

    ld.imprimir();

    return 0;
}