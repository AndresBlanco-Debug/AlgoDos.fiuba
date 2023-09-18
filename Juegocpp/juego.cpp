#include <iostream>
#include "tablero.h"
#include "jugador.h"
#include "juego.h"
using namespace std;
Juego::Juego(){
    Tablero tableroActual;
    Player jugador1;
    Player jugador2;
    int turnoInicial = 0;
}
int Juego::getTutnoActual() {
    return turnoActual;
}
void Juego::incrementarTurno() {
    turnoActual++;
}
bool Juego::ingresoTesP1(int fila, int columna) {
    if(tableroJuego.guardarIngresoTesoroP1(fila,columna)){
        return true;
    }
    return false;
}
bool Juego::ingresoTesP2(int fila, int columna) {
    if(tableroJuego.guardarIngresoTesoroP2(fila,columna)){
        return true;
    }
    return false;
}
void Juego::ingresoInicialP1() {
    int ingresos = 0;
    while(ingresos < 4){
        int fila, columna;
        primerJugador.pedirCoordenadas(fila,columna);
        if(!ingresoTesP1(fila,columna)){
            cout << "Error! el jugador ya posee un tesoro en la casilla" << endl;
        }
        ingresos++;
    }
}
void Juego::ingresoInicialP2() {
    int ingresos = 0;
    while( ingresos < 4){
        int fila, columna;
        segundoJugador.pedirCoordenadas(fila,columna);
        if(!ingresoTesP2(fila,columna)){
            cout << "Error! el jugador ya posee un tesoro en la casilla" << endl;
        }
        ingresos++;
    }
}
void Juego::turnoPrimerJugador() {
    int fallos = 0;
    //esta funcion esta pensada para abarcar todas las funcionalidades poibles
    int fila, columna;
    char respuesta = primerJugador.pedirIngreso();
    //le pregunta al jugador que se desea ingresar
    if(respuesta == '$'){
        //se trata el caso si se desea ingresar un tesoro
        //se piden las coordenadas al primer jugador:
        primerJugador.pedirCoordenadas(fila,columna);
        //Primero hay que hacer una validacion si el jugador tiene tesoros disponibes para ingresar
        if(!primerJugador.ingresoTesoro()){
            //se valida que el jugador tiene tesoros disponibles para ingresar
            while(!ingresoTesP1(fila,columna)){
                //se entra al while si el jugador intenta ingresar el tesoro en una casilla ocupada
                primerJugador.pedirCoordenadas(fila,columna);
            }
        }
        //Si esto no pasa, significa que el tesoro de guardo exitosamente
        //Luego de validar el ingreso hay 3 casos a examinar
        //1. el jugador pone el tesoro sobre un espia enemigo
        //2. el jugador pone el tesoro sobre un tesoro enemigo
        //3. el jugador pone el tesoro en una casilla limpia
        if(tableroJuego.compararTesoros()){
            //se evalua si hay un tesoro enemigo en la casilla ingresada
            //en caso de ser cierto se imprimen filas y columnas
            cout << "CUIDADO! 2 tesoros se han encontrado en: " << fila << ", " << columna << endl;
        }
        //CASO 2: jugador pone tesoro sobre espia enemigo.
        else if(tableroJuego.tesoroPerdidoP1()){
            cout << "El tesoro se ha ingresado en una casilla con un espia enemigo, el tesoro fue eliminado" << endl;
            primerJugador.reducirTesoros();
            //se reducen los tesoros en juego y totales del primer jugador
        }
        //CASO 3: se ingresa en una casilla limpia.
    }
    else if(respuesta == 'E' || respuesta == 'e'){
        //Caso cuando se ingresa un espia
        primerJugador.pedirCoordenadas(fila,columna);
        //el jugador ingresa las coordenadas
        //los casos posibles que se pueden experimentar son:
        //CASO 1: el espia se ingresa sobre un tesoro del jugador y lo recupera
        //CASO 2: el espia se ingresa sobre un tesoro enemigo
        //CASO 3: el espia se encuentra con otro espia
        //CASO 4: el espia se ingresa en una casilla cualquiera
            //CASO 4.1: el jugador mueve un tesoro
            //CASO 4.2: el jugador no mueve un tesoro
        while(!tableroJuego.espiaInfiltradoP1(fila,columna)){
            cout << "Error! el jugador ya tiene un espia en esa casilla" << endl;
            primerJugador.pedirCoordenadas(fila,columna);
        }
        //CASO 1: el espia ingresa sobre un tesoro del jugador y lo recupera
        if(tableroJuego.espiaSobreTesosoP1()){
            //regresa true si hay un espia y un tesoro en la misma casilla
            tableroJuego.tesoroRecuperadoP1();
            //se elimina el tesoro del vector que almacena las coordenadas
            tableroJuego.restringirCasilla(fila,columna);
            //Se restringe y se almacena la casilla
            primerJugador.tesoroRecuperado();
            //se incrementa el numero de tesoros que posee el jugador
        }
        //CASO 2: el espia se ingresa sobre el tesoro enemigo
        else if(tableroJuego.tesoroPerdidoP2()){
            //El espia se ingreso sobre un tesoro enemigo, la funcion lo detecta y lo elimina "captura"
            segundoJugador.reducirTesoros();
            //se reducen los tesoros del segundo jugador
        }
            //CASO 3: el espia se encuentra con un espia enemigo
        else if(tableroJuego.compararEspias()){
            cout << "Dos espias se encontraron en una mision. Ambos han caido" << endl;
        }
        int resp = primerJugador.moverTesoro();
        if(resp == 1){
            int auxFil, auxCol;
            primerJugador.pedirCoordenadas(auxFil, auxCol);
            while(!tableroJuego.moverTesoroP1(auxFil,auxCol)){
                cout << "Error! ya hay un tesoro en esa posicion!" << '\n';
                cout << "Hay un tesoro en: " << auxFil << ", " << endl;
                primerJugador.pedirCoordenadas(auxFil,auxCol);
            }
            cout << "El tesoro se ha movido exitosamente" << endl;
        }
    }
    else{
        cout <<"Error! respuesta no aceptada, intente en su proximo turno." << endl;
    }
}
void Juego::turnoSegundoJugador() {
    //esta funcion esta pensada para abarcar todas las funcionalidades poibles
    int fila, columna;
    char respuesta = segundoJugador.pedirIngreso();
    //le pregunta al jugador que se desea ingresar
    if(respuesta == '$'){
        //se trata el caso si se desea ingresar un tesoro
        //se piden las coordenadas al primer jugador:
        segundoJugador.pedirCoordenadas(fila,columna);
        //Primero hay que hacer una validacion si el jugador tiene tesoros disponibes para ingresar
        if(!segundoJugador.ingresoTesoro()){
            //se valida que el jugador tiene tesoros disponibles para ingresar
            while(!ingresoTesP2(fila,columna)){
                //se entra al while si el jugador intenta ingresar el tesoro en una casilla ocupada
                segundoJugador.pedirCoordenadas(fila,columna);
            }
        }
        //Si esto no pasa, significa que el tesoro de guardo exitosamente
        //Luego de validar el ingreso hay 3 casos a examinar
        //1. el jugador pone el tesoro sobre un espia enemigo
        //2. el jugador pone el tesoro sobre un tesoro enemigo
        //3. el jugador pone el tesoro en una casilla limpia
        if(tableroJuego.compararTesoros()){
            //se evalua si hay un tesoro enemigo en la casilla ingresada
            //en caso de ser cierto se imprimen filas y columnas
            cout << "CUIDADO! 2 tesoros se han encontrado en: " << fila << ", " << columna << endl;
        }
            //CASO 2: jugador pone tesoro sobre espia enemigo.
        else if(tableroJuego.tesoroPerdidoP2()){
            cout << "El tesoro se ha ingresado en una casilla con un espia enemigo, el tesoro fue eliminado" << endl;
            segundoJugador.reducirTesoros();
            //se reducen los tesoros en juego y totales del primer jugador
        }
        //CASO 3: se ingresa en una casilla limpia.
    }
    else if(respuesta == 'E' || respuesta == 'e'){
        //Caso cuando se ingresa un espia
        segundoJugador.pedirCoordenadas(fila,columna);
        //el jugador ingresa las coordenadas
        //los casos posibles que se pueden experimentar son:
        //CASO 1: el espia se ingresa sobre un tesoro del jugador y lo recupera
        //CASO 2: el espia se ingresa sobre un tesoro enemigo
        //CASO 3: el espia se ingresa en una casilla cualquiera
        //CASO 3.1: el jugador mueve un tesoro
        //CASO 3.2: el jugador no mueve un tesoro
        while(!tableroJuego.espiaInfiltradoP1(fila,columna)){
            cout << "Error! el jugador ya tiene un espia en esa casilla" << endl;
            segundoJugador.pedirCoordenadas(fila,columna);
        }
        //CASO 1: el espia ingresa sobre un tesoro del jugador y lo recupera
        if(tableroJuego.espiaSobreTesosoP2()){
            //regresa true si hay un espia y un tesoro en la misma casilla
            tableroJuego.tesoroRecuperadoP2();
            //se elimina el tesoro del vector que almacena las coordenadas
            tableroJuego.restringirCasilla(fila,columna);
            //Se restringe y se almacena la casilla
            segundoJugador.tesoroRecuperado();
            //se incrementa el numero de tesoros que posee el jugador
        }
            //CASO 2: el espia se ingresa sobre el tesoro enemigo
        else if(tableroJuego.tesoroPerdidoP1()){
            //El espia se ingreso sobre un tesoro enemigo, la funcion lo detecta y lo elimina "captura"
            primerJugador.reducirTesoros();
            //se reducen los tesoros del segundo jugador
        }
        else if(tableroJuego.compararEspias()){
            cout << "2 espias se han encontrado, pagaron el precio maximo por su silencio" << endl;
        }
        int resp = segundoJugador.moverTesoro();
        if(resp == 1){
            int auxFil, auxCol;
            segundoJugador.pedirCoordenadas(auxFil, auxCol);
            while(!tableroJuego.moverTesoroP2(auxFil,auxCol)){
                cout << "Error! ya hay un tesoro en esa posicion!" << '\n';
                cout << "Hay un tesoro en: " << auxFil << ", " << endl;
                segundoJugador.pedirCoordenadas(auxFil,auxCol);
            }
            cout << "El tesoro se ha movido exitosamente" << endl;
        }
    }
}
void Juego::turno() {
    turnoPrimerJugador();
    turnoSegundoJugador();
    incrementarTurno();
}
void Juego::juego() {
    ingresoInicialP1();
    ingresoInicialP2();
    tableroJuego.imprimirTablero();
    while(primerJugador.getTesorosTotales() != 0 || segundoJugador.getTesorosTotales() != 0){
        turno();
        tableroJuego.imprimirTableroP1();
        tableroJuego.imprimirTableroP2();

    }
}