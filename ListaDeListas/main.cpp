#include <iostream>
#include "Lista.h"

void preguntarInfo(Lista* tmpLista){
    int info;
    int opcion;
    int padre;
    cout<<"Digite un numero entero"<< endl;
    cin>>info;
    cout<<"Es una padre, digite 1 para si o 0 para no"<<endl;
    cin>>opcion;
    if (opcion == 1)

}

void Listar()

void menu(Lista * tmpLista){
    int opcion = -1;
    while (opcion != 3){
        cout<< "Digite una opcion" << endl;
        cout<< "1. Nuevo nodo" << endl;
        cout << "2. Listar"<<endl;
        cout << "3. Salir"<< endl;
        cin >> opcion;
        switch (opcion){
            case 1:
                preguntarInfo(tmpLista);
                break;
            case 2:
                listar(tmpLista);
                break;
            case 3:
                break;
            default:
                cout<< "Digite una opcion valida"<< endl;
        }
    }

}

int main() {
    Lista * tmpLista =  new Lista();
    menu(tmpLista);
}