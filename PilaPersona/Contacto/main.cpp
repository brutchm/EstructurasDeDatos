#include <iostream>
#include "ListaContacto.h"

using namespace std;

void preguntarInfo(ListaContacto * tmpLista);
void eliminar(ListaContacto * tmpLista);
void listar(ListaContacto * tmpLista);
void buscar(ListaContacto * tmpLista);
void obtenerLongitud(ListaContacto* tmpLista);
void eliminarPos(ListaContacto * tmpLista);

void crearContacto(ListaContacto * p){
    string nombre;
    string apellidos;
    string pais;
    string correo;

    cout<< "Nombre:"<< endl;
    cin>> nombre;
    cout<<"Apellidos"<< endl;
    cin>> apellidos;
    cout<<"Pais:"<<endl;
    cin>> pais;
    cout<<"Email"<<endl;
    cin>>correo;

    p->agregarOrdenado(nombre, apellidos, pais, correo);
}

void listar (ListaContacto * p) {
    p->mostrar();
}

void menu(ListaContacto * p){
    int opcion = -1;
    while (opcion != 0){
        cout << "Digite una opcion"<< endl;
        cout << "1. Registrar un nuevo contacto"<< endl;
        cout << "2. Listar contactos"<<endl;
        cout << "3. Buscar"<< endl;
        cout << "4. Eliminar"<< endl;
        cout<<"5. Obtener longitud"<< endl;
        cout<<"6.Eliminar posicion"<< endl;
        cin >> opcion;
        switch (opcion){
            case 1:
                crearContacto(p);
                break;
            case 2:
                listar(p);
                break;
            case 3:
                buscar(p);
                break;
            case 4:
                eliminar(p);
                break;
            case 5:
                obtenerLongitud(p);
                break;
            case 6:
                eliminarPos(p);
                break;
            default:
                cout<< "Digite una opcion valida"<< endl;
        }
    }
}


int main() {
    ListaContacto* p = new ListaContacto();
    menu(p);

}


void eliminarPos(ListaContacto* tmpLista){
    int pos;
    cout<<"Digite la posicion que desea eliminar"<<endl;
    cin>>pos;
    cout<<tmpLista->eliminarPos(pos)<<endl;
}

void eliminar(ListaContacto * tmpLista){
    string nombre;
    cout << "Digite el numero que desea eliminar"<< endl;
    cin >> nombre;

    cout<<tmpLista->eliminar(nombre)<< endl;
}


void buscar(ListaContacto * tmpLista){
    string nombre;
    cout << "Digite el nombre a buscar"<< endl;
    cin >> nombre;
    cout<<tmpLista->buscar(nombre)<<endl;
}

void obtenerLongitud(ListaContacto * tmpLista){
    cout<< tmpLista->getLongitud()<< endl;
}
