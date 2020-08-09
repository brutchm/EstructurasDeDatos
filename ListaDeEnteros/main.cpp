#include <iostream>
#include "Lista.h"

void preguntarInfo(Lista * tmpLista);
void eliminar(Lista * tmpLista);
void listar(Lista * tmpLista);
void buscar(Lista * tmpLista);
void obtenerLongitud(Lista* tmpLista);
void eliminarPos(Lista * tmpLista);

using namespace std;


void menu(Lista * tmpLista){
    int opcion = -1;
    while (opcion != 0){
        cout<< "Digite una opcion" << endl;
        cout<< "1. Nuevo nodo" << endl;
        cout << "2. Listar"<<endl;
        cout << "3. Buscar"<< endl;
        cout << "4. Eliminar"<< endl;
        cout<<"5. Obtener longitud"<< endl;
        cout<<"6.Eliminar posicion"<< endl;
        cin >> opcion;
        switch (opcion){
            case 1:
                preguntarInfo(tmpLista);
                break;
            case 2:
                listar(tmpLista);
                break;
            case 3:
                buscar(tmpLista);
                break;
            case 4:
                eliminar(tmpLista);
                break;
            case 5:
                obtenerLongitud(tmpLista);
                break;
            case 6:
                eliminarPos(tmpLista);
                break;
            default:
                cout<< "Digite una opcion valida"<< endl;
        }
    }

}

void eliminarPos(Lista* tmpLista){
    int pos;
    cout<<"Digite la posicion que desea eliminar"<<endl;
    cin>>pos;
    cout<<tmpLista->eliminarPos(pos)<<endl;
}

void eliminar(Lista * tmpLista){
    int num;
    cout << "Digite el numero que desea eliminar"<< endl;
    cin >> num;

    cout<<tmpLista->eliminar(num)<< endl;
}

void listar(Lista * tmpLista) {
    Nodo* aux;
    aux = tmpLista->getCabeza();
    cout<<tmpLista->mostrarRecursivo(aux)<<endl;
}

void preguntarInfo(Lista * tmpLista) {
    int valor;
    cout<< "Digite un numero entero" <<endl;
    cin >> valor;

    tmpLista->agregarOrdenado(valor);
}

void buscar(Lista * tmpLista){
    int valor;
    cout << "Digite el valor a buscar"<< endl;
    cin >> valor;

    if (tmpLista->buscar(valor) != nullptr){
        cout << tmpLista->buscar(valor)<< endl;
    }else{
        cout << "No se encontro el elemento"<< endl;
    }
}

void obtenerLongitud(Lista * tmpLista){
    cout<< tmpLista->listaVacia()<< endl;
}

int main() {
    Lista * tmpLista =  new Lista();
    menu(tmpLista);
}