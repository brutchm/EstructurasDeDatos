#include <iostream>
#include "ListaPregunta.h"
#include "PilaPregunta.h"
#include "ColaPregunta.h"
#include "Jugador.h"
#include "ListaJugador.h"
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

ListaPregunta* lista = new ListaPregunta();
PilaPregunta* pilaUno = new PilaPregunta();
PilaPregunta* pilaDos = new PilaPregunta();
ColaPregunta* colaUno = new ColaPregunta();
ColaPregunta* colaDos = new ColaPregunta();


vector<string> explode(string);

void ejecutarOpcion(int opcion);

void reglas();

void llenarLista();

void inciarPartida();

void hacerPreguntas(string, string, string, string);

int preguntar(Pregunta *pPregunta);

void mostrarRespuestas();

void anadirPartida(string info);

void leerPartida();

void anadirJugador(string jugador);

void verEstadisticasJugador();



int main() {

    llenarLista();
    int opcion = -1;
    while (opcion != 0) {
        cout << "Digite una opcion" << endl;
        cout << "1. Nueva partida" << endl;
        cout << "2. Consultar estadisticas jugador" << endl;
        cout << "3. Reglas del juego" << endl;
        cout<<"4. Ver partidas"<<endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        ejecutarOpcion(opcion);
    }

    return 0;
}

void ejecutarOpcion(int opcion) {
    switch (opcion){
        case 1:
            inciarPartida();
            break;
        case 2:
            verEstadisticasJugador();
            break;
        case 3:
            reglas();
            break;
        case 4:
            leerPartida();
            break;
        case 5:
            leerPartida();
            break;
        case 0:
            cout<<"Gracias por usar el juego"<<endl;
            break;
        default:
            cout<<"Digite una opcion valdia";
            break;
    }

}

void inciarPartida() {
    string idUno, idDos, nombreUno, nombreDos;
    cout<<"Digite la identificacion del jugador uno"<<endl;
    cin>>idUno;
    cout<<"Digite el nombre del jugador uno"<<endl;
    cin>>nombreUno;
    cout<<"Digite la identificacion del jugador dos"<<endl;
    cin>>idDos;
    cout<<"Digite el nombre del jugador dos"<<endl;
    cin>>nombreDos;
    pilaUno->buscarEnLista(lista);
    pilaDos->buscarEnLista(lista);
    hacerPreguntas(idUno, nombreUno, idDos, nombreDos);
}

void hacerPreguntas(string idUno, string nombreUno, string idDos, string nombreDos) {
    int uno, dos = 0;
    Pregunta* tmp;
    string info, jugadorUno, jugadorDos;


    while (!pilaUno->esVacia() && ! pilaDos->esVacia()){
        cout<<"Jugador uno"<<endl;
        tmp=pilaUno->pop();
        uno= uno+ preguntar(tmp);
        colaUno->insertar(tmp);
        cout<<"Jugador dos"<<endl;
        tmp=pilaDos->pop();
        dos= dos+preguntar(tmp);
        colaDos->insertar(tmp);
    }


    mostrarRespuestas();


    if (uno>dos){
        info="El ganador es el jugador "+nombreUno;
        jugadorUno= idUno+","+nombreUno+","+to_string(1)+","+to_string(1)+","+to_string(0)+","+to_string(0)+",";
        jugadorDos= idDos+","+nombreDos+","+to_string(1)+","+to_string(0)+","+to_string(0)+","+to_string(1)+",";
        anadirJugador(jugadorUno);
        anadirJugador(jugadorDos);
    }else if(uno< dos){
        info= "El ganador es el jugador dos "+nombreDos;
        jugadorUno= idUno+","+nombreUno+","+to_string(1)+","+ to_string(0)+","+to_string(0)+","+ to_string(1)+",";
        jugadorDos= idDos+","+nombreDos+","+to_string(1)+","+to_string(1)+","+to_string(0)+","+to_string(0)+",";
        anadirJugador(jugadorUno);
        anadirJugador(jugadorDos);
    }else if(uno == dos){
        info="Ha ocurrido un empate";
        jugadorUno= idUno+","+nombreUno+","+ to_string(1)+","+to_string(0)+","+to_string(1)+","+to_string(0)+",";
        jugadorDos= idDos+","+nombreDos+","+ to_string(1)+","+to_string(0)+","+to_string(1)+","+to_string(0)+",";
        anadirJugador(jugadorUno);
        anadirJugador(jugadorDos);
    }


    info = "Jugador: "+nombreUno+" vs Jugador: "+nombreDos+". "+info+".";
    cout<<info<<endl;
    anadirPartida(info);
}

void anadirJugador(string jugador) {
    ofstream archivo;
    archivo.open("jugadores.txt", ios::app);
    if(archivo.fail()){
        cout<<"No se puede abrir el archivo"<<endl;
        exit(1);
    }
    archivo<<jugador<<endl;
    archivo.close();
}

void verEstadisticasJugador(){
    ifstream archivo;
    ListaJugador * listJugadores = new ListaJugador;
    archivo.open("jugadores.txt",ios::in);

    if(archivo.fail()){
        cout<<"No se puede abrir el archivo"<<endl;
        exit(1);
    }

    while(!archivo.eof()){
        string infoJugador;
        vector <string> vJugador;
        getline(archivo, infoJugador);
        if(infoJugador == ""){

        }else{
            size_t pos1 = 0;
            size_t pos2 = 0;
            while ( pos2 != infoJugador.npos )
            {
                pos2 = infoJugador.find(",", pos1);
                if ( pos2 != infoJugador.npos )
                {
                    if ( pos2 > pos1 )
                        vJugador.push_back(infoJugador.substr(pos1, pos2-pos1) );
                    pos1 = pos2+1;
                }
            }

            vJugador.push_back( infoJugador.substr(pos1, infoJugador.size()-pos1) );

            Jugador* tmpJugador = new Jugador(vJugador[0],vJugador[1],stoi(vJugador[2]),stoi(vJugador[3]),stoi(vJugador[4]),stoi(vJugador[5]));
            listJugadores->agregar(tmpJugador);
        }

    }
    archivo.close();
    cout<<listJugadores->toString();


}

void anadirPartida(string info) {
    ofstream archivo;
    archivo.open("partidas.txt", ios::app);
    if(archivo.fail()){
        cout<<"No se puedo abrir el archivo"<<endl;
        exit(1);
    }
    archivo<<info<<endl;
    archivo.close();

}

void leerPartida(){
    ifstream lector;
    string info;
    lector.open("partidas.txt",ios::in);

    if (lector.fail()){
        cout<<"No se puede abrir el archivo"<<endl;
        exit(1);
    }

    while (!lector.eof()){
        getline(lector, info);
        cout<<info<<endl;
    }
    lector.close();
}

int preguntar(Pregunta *pPregunta) {
    int res = 0;
    string respuesta;
    cout << pPregunta->toString();
    cin >> respuesta;
    cout << pPregunta->validarRespuesta(respuesta)<<endl;
    if (pPregunta->validarRespuesta(respuesta) == "Correcto") {
        res = 1;
        return res;
    } else {
        return 0;
    }
}

void reglas() {
    cout<<"REGLAS:"<<endl;
    cout<<"1. Cada jugador debe responder 10 preguntas sin tiempo limite"<<endl;
    cout<<"2. Gana la persona que conteste correctamente mas respuestas"<<endl;
    cout<<"3. Las preguntas se alternan entre los jugadores"<<endl;
    cout<<"4. Una vez iniciada la partida, los jugadores deben ir contestando sus preguntas alternadamente"<<endl;
    cout<<"5. Las respuestas deben ser escritas exactamente igual que como se muestra para que la respuesta sea correcta"<<endl;
}

void llenarLista() {
    lista->agregar("¿Cuál es el lugar más frío de la tierra?", "ANTARTIDA", "ISLANDIA", "POLO_NORTE", "ANTARTIDA", "NORUEGA");
    lista->agregar("¿Quién escribió La Odisea?", "HOMERO", "HOMERO", "JUAN_PEREZ", "PABLO_NERUDA", "MIGUEL_DE_CERVANTES");
    lista->agregar("¿Cómo se llama la capital de Mongolia?", "ULAN_BATOR", "BULGAN", "DORNOD", "ORHON", "ULAN_BATOR");
    lista->agregar("¿Cuál es el río más largo del mundo?", "AMAZONAS", "NILO", "AMAZONAS", "MISSISSIPPI", "AMARILLO");
    lista->agregar("¿En qué continente está Ecuador?", "AMERICA", "OCEANIA", "ASIA", "EUROPA", "AMERICA");

    lista->agregar("¿Dónde originaron los juegos olímpicos (país)?", "GRECIA", "ITALIA", "INGLATERRA", "GRECIA", "RUSIA");
    lista->agregar("¿Qué tipo de animal es la ballena?", "MAMIFERO", "REPTIL", "ANFIBIO", "MAMIFERO", "PECES");
    lista->agregar("¿De qué colores es la bandera de México?",  "VERDE_BLANCO_ROJO", "VERDE_AZUL_BLANCO", "VERDE_BLANCO_ROJO"," ROJO_BLANCO_AMARILLO", "NARANJA_CAFÉ_ROJO");
    lista->agregar ("¿Qué cantidad de huesos hay en el cuerpo humano de un adulto?", "206", "215", "300", "206", "201");
    lista->agregar ("¿En qué año acabó la II Guerra Mundial?", "1945", "1939", "1943", "1945", "1950");
    lista->agregar ("¿Quién es el autor de el Quijote?", "MIGUEL_DE_CERVANTES", "GABRIEL_GARCÍA_MARQUEZ", "MIGUEL_DE_CERVANTES", "FEDERICO_GARCÍA_LORCA", "FRANCISCO_DE_QUEVEDO");
    lista->agregar ("¿Quién pintó “la última cena”?", "LEONARDO_DA_VINCI", "LEONARDO_DA_VINCI", "MIGUEL_ÁNGEL", "DONATELLO", "LOUISE_BOURGEOIS");
    lista->agregar ("¿En qué país se encuentra la torre de Pisa?", "ITALIA", "FRANCIA", "POLONIA", "ITALIA", "ESPAÑA");
    lista->agregar ("¿Lugar dónde se encuentra la basílica católica la Sagrada Familia?", "Barcelona", "VATICANO", "BARCELONA", "LONDRES", "MADRID");
    lista->agregar ("¿Cómo se denomina el resultado de la multiplicación?", "PRODUCTO", "COCIENTE", "RESIDUO", "PRODUCTO", "MULTIPLO");
    lista->agregar ("¿Cuál es el océano más grande?", "PACIFICO", "ATLANTICO", "INDICO", "PACIFICO", "CARIBE");
    lista->agregar ("¿Quién es el padre del psicoanálisis?", "SIGMUND_FREUD", "IVÁN_PAVLOV", "CARL_ROGERS", "JEAN_PIAGET", "SIGMUND_FREUD");
    lista->agregar ("¿Cuál es el disco más vendido de la historia?", "THRILLER", "THE_DARK_SIDE_OF_THE_MOON", "THRILLER", "BACK_IN_BLACK", "EL_GUARDAESPALDAS");
    lista->agregar ("¿Qué producto cultiva más Guatemala?", "CAFE", "AGUACATE", "BANANO", "CAFE", "TRIGO");
    lista->agregar ("¿Quién es el famoso Rey de Rock en los Estados Unidos?", "ELVIS_PRESLEY", "AXEL_ROSE", "BOB_DYLAN", "ELVIS_PRESLEY", "BILLY_JOEL");
    lista->agregar ("¿Qué significa FIFA?", "FEDERATION_INTERNATIONALE_DE_FOOTBALL_ASSOCIATION", "FEDERACION_INTERNACIONAL_DE_FUTBOL_AMERICANO", "FEDERATION_INTERNATIONALE_DE_FOOTBALL_ASSOCIATION", "FRENTE_INTERNACIONAL_DE_FOOTBALL_ASSOCIATION", "FEDERACION_INTRAMURAL_DE_FRESAS_AMERICANAS");
    lista->agregar ("¿En qué se especializa la cartografía?", "ESTUDIO_DE_MAPAS", "ESTUDIO_DE_CARTONES", "ESTUDIO_DE_PLANOS", "ESTUDIO_GEOGRÁFICO", "ESTUDIO_DE_MAPAS");
    lista->agregar ("¿Cuál es el país con el territorio más grande del mundo?", "RUSIA", "CHINA", "BRASIL", "RUSIA", "ESTADOS_UNIDOS");
    lista->agregar ("¿Dónde se encuentra la famosa Torre Eiffel?", "FRANCIA", "ESPAÑA", "FRANCIA", "ITALIA", "MEXICO");
    lista->agregar ("¿Qué deporte practicaba Michael Jordan?", "BALONCESTO", "TENIS", "FUTBOL", "PING_PONG", "BALONCESTO");
    lista->agregar ("¿En qué año comenzó la II Guerra Mundial?", "1939", "1935", "1939", "1940", "1945");
    lista->agregar ( "Si 50 es el 100%, ¿cuánto es el 90%?", "45", "40", "49", "45", "42");
    lista->agregar ("¿Cuál es tercer planeta en el sistema solar?", "TIERRA", "MERCURIO", "MARTE", "TIERRA", "JUPITER");
    lista->agregar ("¿Qué país tiene forma de bota?", "ITALIA", "FRANCIA", "AUSTRIA", "JAPON", "ITALIA");
    lista->agregar ("¿Cuál es la moneda del Reino Unido?", "LIBRA", "DOLAR", "LIBRA", "YEN", "DIRHAM");
    lista->agregar ("¿Cual es país más poblado de la Tierra?", "CHINA", "BRASIL", "RUSIA", "CHINA", "ESTADOS_UNIDOS");
    lista->agregar ("¿En qué lugar del cuerpo se produce la insulina?", "PANCREAS", "HIGADO", "RIÑON", "PANCREAS", "TIROIDES");
    lista->agregar ("¿Quién es Justin Timberlake?", "CANTANTE", "CANTANTE", "ESCRITOR", "DEPORTISTA", "ESCULTOR");
    lista->agregar ("¿Cuál es el color que representa la esperanza?", "VERDE", "AMARILLO", "AZUL", "CELESTE", "VERDE");
    lista->agregar ("¿Cuál es el área del arte protagonista en los premios Grammy?", "MUSICA", "LITERATURA", "CIENCIA", "MUSICA", "ACTUACION");
    lista->agregar ( "¿De qué estilo arquitectónico es la Catedral de Notre Dame en París?", "GOTICO", "COLONIAL", "BARROCO", "GOTICO", "ROMANICO");
    lista->agregar ("¿Cuántas patas tiene la araña?", "8", "9", "7", "8", "16");
    lista->agregar ("¿Cómo se llama el animal más rápido del mundo?", "GUEPARDO", "CARACOL", "LEON", "ANTILOPE", "GUEPARDO");
    lista->agregar ("¿Cuál es la ciudad de los rascacielos?", "NUEVA_YORK", "MONTECRISTO", "BARCELONA", "ABU_DHABI", "NUEVA_YORK");
    lista->agregar ("¿De qué país es el futbolista Zlatan Ibrahimović?", "SUECO", "FRANCES", "ESPAÑOL", "SUECO", "POLACO");
    lista->agregar ("¿En qué país se encuentra el famoso monumento Taj Mahal?", "INDIA", "RUSIA", "TAILANDIA", "INDIA", "EGIPTO");
    lista->agregar ( "¿Quién va a la cárcel: el imputado, el acusado, el condenado o la victima?", "CONDENADO", "IMPUTADO", "ACUSADO", "CONDENADO", "VICTIMA");
    lista->agregar ("¿Cuál fue el primer metal que empleó el hombre?", "COBRE", "ORO", "PLATA", "ALUMINIO", "COBRE");
    lista->agregar ("¿Quién era el general de los nazis en la Segunda Guerra Mundial?", "ADOLF_HITLER", "BENITO_MUSSOLINI", "ADOLF_HITLER", "KARL_MARX", "IOSIF_STALIN");
    lista->agregar ("¿Cómo se llama la estación espacial rusa?", "MIR", "MABUR", "MIR", "KROFF-21", "ATLAS");
    lista->agregar ( "Cuál es el área del arte protagonista en los Premios Óscar?", "CINE", "MUSICA", "CINE", "LITERATURA", "INGENIERIA");
    lista->agregar ("¿Cuál es el primero de la lista de los números primos?", "2", "1", "2", "3", "5");
    lista->agregar ("¿Cómo se le llama a una colección de revistas, diarios y publicaciones periódicas?", "HEMEROTECA", "BIBLIOTECA", "MAQUETA", "HEMEROTECA", "PERITECA");
    lista->agregar ("¿Cuál es el único mamífero capaz de volar?", "MURCIELAGO", "BALLENA", "AVESTRUZ", "MURCIELAGO", "COLIBRI");
    lista->agregar ("¿Cuál es el libro sagrado del Islam?", "CORAN", "TANAJ", "BIBLIA", "CORAN", "RELIGIOSO");
    lista->agregar ("¿Qué era el Concorde?", "AVION_SUPERSONICO", "BARCO", "TREN", "SUBMARINO", "AVION_SUPERSONICO");
    lista->agregar ("¿Quién ganó el mundial de fútbol del 2014?", "ALEMANIA", "ALEMANIA", "FRANCIA", "BRASIL", "ESPAÑA");
    lista->agregar ("¿Quién escribió “Hamlet”?","WILLIAN_SHAKESPEARE" , "OSCAR_WILDE", "CHARLES_DICKENS", "WILLIAN_SHAKESPEARE", "ERNEST_HEMINGWAY");
    lista->agregar ("¿Cuál es la moneda oficial de Estados Unidos?", "DOLAR", "LIBRA", "COLON", "EURO", "DOLAR");
    lista->agregar ("¿A qué país pertenece la ciudad de Varsovia?", "POLONIA", "HUNGRIA", "ESPAÑA", "POLONIA", "ALEMANIA");
    lista->agregar ("¿Cuál es la nacionalidad de Pablo Neruda?", "CHILE", "ARGENTINA", "COLOMBIA", "VENEZUELA", "CHILE");
    lista->agregar ("¿A quién le crecía la nariz cuando mentía?", "PINOCHO", "GUEPETO", "PEPE_GRILLO", "PINOCHO", "GENGIBRE");
    lista->agregar ("¿De qué estado fue emperador Napoleón Bonaparte?", "FRANCIA", "ITALIA", "POLONIA", "AUSTRIA", "FRANCIA");
    lista->agregar ("¿Cómo se llama la energía contenida en el núcleo de los átomos?", "NUCLEAR", "POTENCIAL", "ELECTRICA", "NUCLEAR", "QUIMICA");
    lista->agregar ("¿Dónde está la Casa Blanca?", "WASHINGTON_D.C", "CALIFORNIA", "TEXAS", "NUEVA_YORK", "WASHINGTON_D.C");
    lista->agregar ("¿De qué está recubierto el cuerpo de los peces?", "ESCAMAS", "PELO", "ESCAMAS", "PLUMAS", "PIEL");
    lista->agregar ("El triángulo que tiene sus tres lados iguales ¿Cómo se llama?", "EQUILATERO", "ISOSCELES", "ESCALENO", "EQUILATERO", "RECTANGULO");
    lista->agregar ("¿Quién es el protagonista de la película “Rocky”?", "SYLVESTER_STALLONE", "ARNOLD_SCHWARZENEGGER", "DWAYNE_JOHNSON", "SYLVESTER_STALLONE", "MATT_DAMON");
    lista->agregar ("¿Cuál es el metal más caro del mundo?", "RODIO", "ORO", "PLATINO", "RODIO", "ALUMINIO");
    lista->agregar ("¿Cuántos años tiene un lustro?", "5", "10", "100", "5" ,"7");
    lista->agregar ("¿Cuál es la capital de Francia?", "PARIS", "MARSELLA", "LYON", "NIZA", "PARIS");
    lista->agregar ("¿Qué deporte practica profesionalmente Roger Federer?", "TENIS", "FUTBOL", "ESGRIMA", "TENIS", "NATACION");
    lista->agregar ("¿Qué instrumento tocaba Paco de Lucía?", "GUITARRA", "BAJO", "BATERIA", "VIOLIN", "GUITARRA");
    lista->agregar ("¿Cuáles son los dos países con mayor cantidad de musulmanes?", "INDONESIA_INDIA", "INDONESIA_INDIA", "INDONESIA_ARABIA SAUDITA", "INDIA_PAKISTÁN", "INDIA_ECUADOR");
    lista->agregar ("¿En qué año apareció en el mercado el primer videojuego protagonizado por Super Mario?", "1981", "1980", "1981", "1990", "1985");
    lista->agregar ("¿Cúal animal posee caracteristicas fisicas con las que le es más sencillo replicar a los humanos al hablar?", "CUERVO", "LORO", "LAPA", "PERICO", "CUERVO");
    lista->agregar ("¿Cuál es el idioma más antiguo de los que sobreviven en Europa?", "VASCO", "VASCO", "ESPAÑOL", "FRANCES", "ITALIANO");
    lista->agregar ("¿Cuál es el país con más camellos salvajes?", "AUSTRALIA", "EGIPTO", "SUDAFRICA", "ARGENTINA" , "AUSTRALIA");
    lista->agregar ("¿Cuántos corazones tienen los pulpos?", "3", "2", "5", "4", "3");
    lista->agregar ("¿hace cuanto se extinguieron los mamuts estimadamente (Años)?", "4000", "10000", "4000", "8000", "7000");
}

void mostrarRespuestas() {
    cout<<"Respuestas correctas para el jugador uno"<<endl;
    while (!colaUno->esVacia()){
        cout<<colaUno->atender()<<endl;
    }
    cout<<"Respuestas correctas para el jugador dos"<<endl;
    while (!colaDos->esVacia()){
        cout<<colaDos->atender()<<endl;
    }
}



