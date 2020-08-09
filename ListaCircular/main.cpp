#include<string.h>

#include<iostream>

#include<stdlib.h>


using namespace std;



struct empleado{

    int ident;

    char ap[20], nom[20],cargo[20];

    int sueldo;

    struct empleado *avanc;

};



empleado* insertar_nodo_inicial(void);

void insertar_nodos_circular(empleado *&,int c);

int progenc(empleado *);

void empleadosmayora(empleado *);

void sumanomina(empleado *);

char opciones(empleado *);

void ordenar(empleado*);

void imprime_lista_circ(empleado*);

void eliminar_nodo_circ(empleado *&cab,int i);

char opciones(empleado * cab)



{

    char a;

    cout<<"n";

    cout<<"1.crear nodo inicial"<<"n"<<endl;

    cout<<"2.Insertar nuevo dato"<<"n"<<endl;

    cout<<"3.Programadores en c++"<<"n"<<endl;

    cout<<"4.Sueldo mayor a $2'500.000"<<"n"<<endl;

    cout<<"5.Motrar suma de sueldos empleados"<<"n"<<endl;

    cout<<"6.imprimir lista"<<"n"<<endl;

    cout<<"7.borrar nodo"<<"n"<<endl;

    cout<<"8.salir"<<"n"<<endl;

    cout<<"INGRESE OPCION: "<<endl;

    cin>>a;

    return a;

}



int main()

{

    int i,c;

    char opcion;

    empleado *cab=NULL;

    while(opcion!='8')

    {

        opcion=opciones(cab);

        switch(opcion)

        {

            case '1':cab=insertar_nodo_inicial();

                break;

            case '2':cout<<"inserte identificacion: "<<endl;

                cin>>c;

                insertar_nodos_circular(*&cab,c);

                break;

            case '3':cout<<"en la empresa hay "<<progenc(cab)<<" programador(es) de  c++"<<endl;

                break;

            case '4':empleadosmayora(cab);

                break;

            case '5':sumanomina(cab);

                break;

            case '6':imprime_lista_circ(cab);

                break;

            case '7':cout<<"inserte identificacion: "<<endl;

                cin>>i;

                eliminar_nodo_circ(*&cab, i);

                break;

            case '8':exit(0);

                break;

            default:cout<<"fuera de parametro"<<endl;

        }

    }

}



//crearnodo

empleado* insertar_nodo_inicial()

{

    empleado *crear;

    crear=new empleado;

    cout<<"IDENTIFICACION: "<<endl;

    cin>>crear->ident;

    cout<<"APELLIDO: "<<endl;

    cin>>crear->ap;

    cout<<"NOMBRE: "<<endl;

    cin>>crear->nom;

    cout<<"CARGO: "<<endl;

    cin>>crear->cargo;

    cout<<"SUELDO: "<<endl;

    cin>>crear->sueldo;

    crear->avanc=crear;

    return crear;

}



//insertar nodo

void insertar_nodos_circular(empleado *&cab,int c)

{

    empleado *aux;

    empleado *r;

    if(cab!=NULL)

    {

        r=cab;

        aux=new empleado;

        while(r->ident!=c && r->avanc!=cab)

            r=r->avanc;

        if(r==cab)

        {

            cout<<"IDENTIFICACION: "<<endl;

            cin>>aux->ident;

            cout<<"APELLIDO: "<<endl;

            cin>>aux->ap;

            cout<<"NOMBRE: "<<endl;

            cin>>aux->nom;

            cout<<"CARGO: "<<endl;

            cin>>aux->cargo;

            cout<<"SUELDO: "<<endl;

            cin>>aux->sueldo;

            aux->avanc=r->avanc;

            r->avanc=aux;

            r=aux;

        }

        else

        {

            aux->avanc=r->avanc;

            r->avanc=aux;

            cout<<"IDENTIFICACION: "<<endl;

            cin>>aux->ident;

            cout<<"APELLIDO: "<<endl;

            cin>>aux->ap;

            cout<<"NOMBRE: "<<endl;

            cin>>aux->nom;

            cout<<"CARGO: "<<endl;

            cin>>aux->cargo;

            cout<<"SUELDO: "<<endl;

            cin>>aux->sueldo;

        }

    }

    else

        cout<<"no hay nodo inicial de lista por favor digite 1"<<endl;

}



//prog en c++

int progenc(empleado*cab)

{

    empleado *q;

    int cant=0;

    q=cab;

    if(cab)

    {

        if(strcmp(q->cargo,"programadores_en_c++")==0)

            cout<<"n"<<endl;

        cant=cant+1;

        while(q->avanc!=cab)

        {

            if(strcmp(q->cargo,"programadores_en_c++")==0)

                cout<<"n"<<endl;

            cant=cant+1;

            q=q->avanc;

        }

    }

    else

        cout<<"no existe lista"<<endl;

    return cant;

}



//SUELDO

void empleadosmayora(empleado *cab)

{

    empleado *p;

    p=cab;

    if(cab)

    {

        if(cab->sueldo>2500000)

        {

            cout<<"IDENTIFICACION: "<<cab->ident<<endl;

            cout<<"n"<<endl;

            cout<<"APELLIDO: "<<cab->ap<<endl;

            cout<<"n"<<endl;

            cout<<"NOMBRE: "<<cab->nom<<endl;

            cout<<"n"<<endl;

            cout<<"CARGO: "<<cab->cargo<<endl;

            cout<<"n"<<endl;

            cout<<"SUELDO: "<<cab->sueldo<<endl;

            cout<<"n"<<endl;

        }

        p=cab->avanc;

        while(p!=cab){

            if(p->sueldo>2500000 && p!=cab)

            {

                cout<<"n"<<endl;

                cout<<"IDENTIFICACION: "<<p->ident<<endl;

                cout<<"n"<<endl;

                cout<<"APELLIDO: "<<p->ap<<endl;

                cout<<"n"<<endl;

                cout<<"NOMBRE: "<<p->nom<<endl;

                cout<<"n"<<endl;

                cout<<"CARGO: "<<p->cargo<<endl;

                cout<<"n"<<endl;

                cout<<"SUELDO: "<<p->sueldo<<endl;

                cout<<"n"<<endl;

            }

            p=p->avanc;}

    }

    else

        cout<<"no existe lista"<<endl;
}



//SUMANOMINA

void sumanomina(empleado *cab)

{

    empleado *q;

    int sumnomina=0;

    q=cab->avanc;

    if(cab)

    {

        sumnomina=cab->sueldo+sumnomina;

    }

    while(q!=cab)

    {

        sumnomina=cab->sueldo+sumnomina;

        q=q->avanc;

    }

    cout<<"El total de la nomina es "<<sumnomina<<endl;
}



void imprime_lista_circ(empleado*cab)

{

    empleado *q;

    if(cab==NULL)

        cout<<"no hay lista"<<endl;

    else

    if(cab->avanc==cab)

    {

        cout<<"n"<<endl;

        cout<<"n"<<endl;

        cout<<"cedula:"<<cab->ident<<endl;

        cout<<"n"<<endl;

        cout<<"apellido:"<<cab->ap<<endl;

        cout<<"n"<<endl;

        cout<<"nombre:"<<cab->nom<<endl;

        cout<<"n"<<endl;

        cout<<"cargo:"<<cab->cargo<<endl;

        cout<<"n"<<endl;

        cout<<"sueldo:"<<cab->sueldo<<endl;

        cout<<"n"<<endl;

        cout<<"n"<<endl;

    }

    else

    {

        q=cab;

        cout<<"n"<<endl;

        cout<<"n"<<endl;

        cout<<"cedula:"<<cab->ident<<endl;

        cout<<"n"<<endl;

        cout<<"apellido:"<<cab->ap<<endl;

        cout<<"n"<<endl;

        cout<<"nombre:"<<cab->nom<<endl;

        cout<<"n"<<endl;

        cout<<"cargo:"<<cab->cargo<<endl;

        cout<<"n"<<endl;

        cout<<"sueldo:"<<cab->sueldo<<endl;

        cout<<"n"<<endl;

        cout<<"n"<<endl;

        q=cab->avanc;

        do{

            cout<<"cedula:"<<q->ident<<endl;

            cout<<"n"<<endl;

            cout<<"apellido:"<<q->ap<<endl;

            cout<<"n"<<endl;

            cout<<"nombre:"<<q->nom<<endl;

            cout<<"n"<<endl;

            cout<<"cargo:"<<q->cargo<<endl;

            cout<<"n"<<endl;

            cout<<"sueldo:"<<q->sueldo<<endl;

            cout<<"n"<<endl;

            cout<<"n"<<endl;

            q=q->avanc;

        }

        while(q!=cab);

    }

}





//ELIMINAR NODO

void eliminar_nodo_circ(empleado *&cab, int i)

{

    empleado *q,*r;

    q=r=cab;

    if(cab==NULL)

        cout<<"no hay cabeza"<<endl;

    else

    if(cab->avanc==cab && cab->ident==i)

    {

        delete(q);

    }

    else

        while((q->ident!=i) && (q->avanc!=cab))

        {

            q=q->avanc;

        }

    if(cab->avanc==q)

    {

        cab->avanc=q->avanc;

        delete(q);

    }

    else

    {

        while(r->avanc!=q)

        {

            r=r->avanc;

        }

        r->avanc=q->avanc;

        delete(q);

    }

}
