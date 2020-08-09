#include <iostream>
#include "ColaInt.h"

void agregarCola(ColaInt *pInt);

void agregarPila(PilaInt *tmpCola);

void mostrarCola(ColaInt *tmpCola);

void mostrarPila(PilaInt *tmpPila);

void elimarSigPila(PilaInt *tmpPila);

void eliminarSigCola(ColaInt *tmpCola);

void hacerPilaCola(ColaInt *tmpCola, PilaInt *tmpPila);

void hacerColaPila(ColaInt *tmpCola, PilaInt *tmpPila);

using namespace std;

int main() {

    ColaInt * tmpCola = new ColaInt();
    PilaInt * tmpPila = new PilaInt();

    int opcion = -1;
    while(opcion != 0) {
        cout << "Digite una opcion" << endl;
        cout << "1. Agregar a cola" << endl;
        cout << "2. Agregar a pila" << endl;
        cout << "3. Mostrar Cola" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "5. Eliminar sigiuiente de pila" << endl;
        cout << "6. Eliminar siguiente de cola" << endl;
        cout << "7. Hacer pila cola" << endl;
        cout << "8. Hacer cola pila" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                agregarPila(tmpPila);
                break;
            case 2:
                agregarCola(tmpCola);
                break;
            case 3:
                mostrarCola(tmpCola);
                break;
            case 4:
                mostrarPila(tmpPila);
                break;
            case 5:
                elimarSigPila(tmpPila);
                break;
            case 6:
                eliminarSigCola(tmpCola);
                break;
            case 7:
                hacerPilaCola(tmpCola, tmpPila);
                break;
            case 8:
                hacerColaPila(tmpCola, tmpPila);
                break;
            case 0:
                cout<<"Gracias por usar el programa"<<endl;
                break;
            default:
                cout<<"Digite una opcion valida";
                break;
        }
    }
}

void hacerColaPila(ColaInt *tmpCola, PilaInt *tmpPila) {
    tmpCola->hacerPila(tmpPila);

}

void hacerPilaCola(ColaInt *tmpCola, PilaInt *tmpPila) {
    tmpCola->hacerPila(tmpPila);
}

void eliminarSigCola(ColaInt *tmpCola) {
    tmpCola->eliminarCola();
}

void elimarSigPila(PilaInt *tmpPila) {
    tmpPila->eliminarPila();
}

void mostrarPila(PilaInt *tmpPila) {
    tmpPila->mostrar();
}

void mostrarCola(ColaInt *tmpCola) {
    tmpCola->mostrar();
}

void agregarPila(PilaInt* tmpPila){
    int num;
    cout<< "Digite un numero entero"<<endl;
    cin>>num;

    tmpPila->agregarPila(num);
}

void agregarCola(ColaInt * tmpCola) {
    int num;
    cout<< "Digite un numero entero"<<endl;
    cin>>num;

    tmpCola->agregarCola(num);
}
