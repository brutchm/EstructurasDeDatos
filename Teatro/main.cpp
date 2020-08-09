#include <iostream>
#include "Vip.h"
#include "General.h"
#include "Preferencial.h"
#include "Cola.h"

using namespace std;


Vip * vip= new Vip(10, 7000);
General * general = new General(50, 5500);
Preferencial * preferencial= new Preferencial(50, 4000);
Cola * colaEspera;
bool func_iniciada;


void iniciarFuncion()
{
    if (!func_iniciada)
    {
        func_iniciada = true;
        int vipPlata = vip->getComprados() * vip->getCosto();
        int preferencialPlata = preferencial->getComprados() * preferencial->getCosto();
        int generalPlata = general->getComprados() * general->getCosto();
        int totalPlata = vipPlata + preferencialPlata + generalPlata;
        cout << "Acaba de inciciar la funcion de Shrek 2020" << endl;
        cout << "Vip: " <<  vipPlata << " colones"<<", los asistentes fueron: "<<vipPlata/7000 << endl;
        cout << "Preferencial: " <<  preferencialPlata << " colones" ", los asistentes fueron: "<<preferencialPlata/5500 << endl;
        cout << "General: " << generalPlata << " colones" ", los asistentes fueron: "<<generalPlata/4000 << endl;
        cout << "Total: " << totalPlata << " colones" <<", los asistentes fueron: "<< (vipPlata/7000) + (preferencialPlata/5500) + (generalPlata/4000) << endl;
    }
    else
    {
        cout << "Ya la funcion de Shrek 2020 empezo" << endl;
    }

}

// Liberar Asientos
void liberarAsientos()
{
    if (!func_iniciada)
    {
        vip->liberarAsientos();
        preferencial->liberarAsientos();
        general->liberarAsientos();
        cout << "Se han liberado todos los asientos!" << endl;
    }
    else
    {
        cout << "Ya la funcion de 'Toy Story 4' ya empezo!" << endl;
    }

}

// Comprar Asiento
void comprarAsiento()
{
    if (!func_iniciada)
    {
        string tipo;
        cout << "Tipo de asiento (vip, preferencial, general): ";
        cin >> tipo;
        cout << "Tipo: " << tipo << endl;

        // Vip
        if (tipo.compare("vip") == 0)
        {
            cout << "Digite su cedula: " << endl;
            int ced;
            cin >> ced;
            cout << "Digite un asiento: " << endl;
            int asiento;
            cin >> asiento;
            vip->comprarAsiento(asiento, ced);
        }
        else if (tipo.compare("preferencial") == 0)
        {
            cout << "Desea comprar un asiento reservado? (s/n)" << endl;
            string opt;
            cin >> opt;
            bool comprarAsientoReservado = (opt.compare("s") == 0) ? true : false;
            if (comprarAsientoReservado)
            {
                cout << "Digite su cedula: " << endl;
                int ced;
                cin >> ced;
                preferencial->comprarAsientoReservado(ced);
            }
            else
            {
                cout << "Ya no quedan espacios disponibles. Desea ser anadido a la lista de espera? (s/n)" << endl;
                string opt;
                cin >> opt;
                bool addCola = (opt.compare("s") == 0) ? true : false;
                if (addCola) {
                    cout << "Digite su cedula: " << endl;
                    int ced;
                    cin >> ced;
                    if (!colaEspera->buscar(ced)) {
                        colaEspera->insertar(ced);
                        cout << "Se anadio a la cola! (" << ced << ")" << endl;
                    }
                    else
                    {
                        cout << "Usted ya se encuentra en la cola!" << endl;
                    }
                }
            }
        }
        else if (tipo.compare("general") == 0)
        {
            cout << "Digite su cedula: " << endl;
            int ced;
            cin >> ced;
            cout << "Digite un asiento: " << endl;
            int asiento;
            cin >> asiento;
            general->comprarAsiento(asiento, ced);
        }
    }
    else
    {
        cout << "Ya la funcion de 'Toy Story 4' ya empezo!" << endl;
    }
}

void reservarAsiento()
{
    if (!func_iniciada)
    {
        string tipo;
        cout << "Tipo de asiento (vip, preferencial, general): ";
        cin >> tipo;
        cout << "Tipo: " << tipo << endl;

        // Vip
        if (tipo.compare("vip") == 0)
        {
            if (vip->getDisponibles() == vip->getCapacidad())
            {
                cout << "Ya no quedan espacios disponibles. Desea ser anadido a la lista de espera? (s/n)" << endl;
                string opt;
                cin >> opt;
                bool addCola = (opt.compare("s") == 0) ? true : false;
                if (addCola)
                {
                    cout << "Digite su cedula: " << endl;
                    int ced;
                    cin >> ced;
                    // Verificar si ya esta en la cola
                    if (!colaEspera->buscar(ced)) {
                        colaEspera->insertar(ced);
                        cout << "Se anadio a la cola! (" << ced << ")" << endl;
                    }
                    else
                    {
                        cout << "Usted ya se encuentra en la cola!" << endl;
                    }
                }
            }
            else
            {
                cout << "Digite su cedula: " << endl;
                int ced;
                cin >> ced;
                cout << "Digite un asiento: " << endl;
                int asiento;
                cin >> asiento;
                vip->reservarAsiento(asiento, ced);
            }

        }
        else if (tipo.compare("preferencial") == 0)
        {
            if (preferencial->getDisponibles() == preferencial->getCapacidad())
            {
                cout << "Ya no quedan espacios disponibles. Desea ser anadido a la lista de espera? (s/n)" << endl;
                string opt;
                cin >> opt;
                bool addCola = (opt.compare("s") == 0) ? true : false;
                if (addCola)
                {
                    cout << "Digite su cedula: " << endl;
                    int ced;
                    cin >> ced;
                    if (!colaEspera->buscar(ced)) {
                        colaEspera->insertar(ced);
                        cout << "Se anadio a la cola! (" << ced << ")" << endl;
                    }
                    else
                    {
                        cout << "Usted ya se encuentra en la cola!" << endl;
                    }
                }
            }
            else
            {
                cout << "Digite su cedula: " << endl;
                int ced;
                cin >> ced;
                preferencial->reservarAsiento(ced);
            }
        }
        else if (tipo.compare("general") == 0)
        {
            if (general->getDisponibles() == general->getCapacidad())
            {
                cout << "Ya no quedan espacios disponibles. Desea ser anadido a la lista de espera? (s/n)" << endl;
                string opt;
                cin >> opt;
                bool addCola = (opt.compare("s") == 0) ? true : false;
                if (addCola)
                {
                    cout << "Digite su cedula: " << endl;
                    int ced;
                    cin >> ced;
                    if (!colaEspera->buscar(ced))
                    {
                        colaEspera->insertar(ced);
                        cout << "Se anadio a la cola! (" << ced << ")" << endl;
                    }
                    else
                    {
                        cout << "Usted ya se encuentra en la cola!" << endl;
                    }
                }
            }
            else
            {
                cout << "Digite su cedula: " << endl;
                int ced;
                cin >> ced;
                general->reservarAsiento(ced);
            }
        }
    }
    else
    {
        cout << "Ya la funcion de 'Toy Story 4' ya empezo!" << endl;
    }
}

void detenerAplicacion()
{
    cout << "[!] Deteniendo la aplicacion..." << endl;
    exit(0);
}

bool seleccionarOpcion(string opt)
{
    bool menu = true;

    if (opt.compare("1") == 0)
    {
        cout << "Nombre: Shrek 2020 está en camino" << endl;
        cout << "Vip: " << vip->getDisponibles() << "/" << vip->getCapacidad() << endl;
        cout << "Preferencial: " << preferencial->getDisponibles() << "/" << preferencial->getCapacidad() << endl;
        cout << "General: " << general->getDisponibles() << "/" << general->getCapacidad() << endl;
    }

    if (opt.compare("2") == 0)
    {
        reservarAsiento();
    }

    if (opt.compare("3") == 0)
    {
        comprarAsiento();
    }

    if (opt.compare("4") == 0)
    {
        liberarAsientos();
    }

    if (opt.compare("5") == 0)
    {
        iniciarFuncion();
    }

    if (opt.compare("6") == 0)
    {
        detenerAplicacion();
    }

    return menu;
}


void mostrarMenu()
{
    cout << "**********************************************" << endl;
    cout << "1. Información de la Funcion" << endl;
    cout << "2. Hacer una reservación" << endl;
    cout << "3. Pagar una reservación" << endl;
    cout << "4. Liberar reservaciones" << endl;
    cout << "5. Iniciar la función" << endl;
    cout << "6. Salir" << endl;
    cout << "**********************************************" << endl;
    cout << "Digite una opcion: " << endl;
}

string leerOpcion()
{
    string opcion;
    cin >> opcion;
    return opcion;

}

void menuPrincipal()
{
    string opcion = "";
    bool menu;
    do
    {
        mostrarMenu();
        opcion = leerOpcion();
        menu = seleccionarOpcion(opcion);
    } while (menu);
}

int main()
{
    menuPrincipal();



    return 0;
}