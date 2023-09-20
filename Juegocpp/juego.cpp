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
void Juego::mostrarReglas() {
    cout << "----- Reglas del Juego Tesoro Binario -----\n";
    cout << "Tesoro binario es un juego de mesa para dos jugadores.\n";
    cout << "El objetivo es esconder tus tesoros y descubrir los del oponente.\n";
    cout << "El tablero tiene dimensiones de 20x20 casillas.\n";
    cout << "Cada jugador tiene 4 tesoros para esconder.\n";
    cout << "Durante tu turno, puedes hacer una de las siguientes acciones:\n";
    cout << "1. Ingresar un tesoro ($): Elige una casilla vacía para poner uno de tus tesoros.\n";
    cout << "2. Ingresar un espía (E): Elige una casilla vacía para enviar un espía a espiar el tablero.\n";
    cout << "3. Mover un tesoro: Si tienes un tesoro en juego, puedes moverlo una casilla en cualquier dirección (horizontal, vertical o diagonal).\n";
    cout << "Recuerda que las siguientes reglas se aplican:\n";
    cout << "- Si ingresas un tesoro sobre un tesoro enemigo, se revela la ubicación.\n";
    cout << "- Si ingresas un tesoro sobre un espía enemigo, el tesoro se pierde.\n";
    cout << "- Si un espía se encuentra con otro espía enemigo, ambos son eliminados.\n";
    cout << "- El juego termina cuando un jugador se queda sin tesoros. El otro jugador gana.\n";
    cout << "¡Buena suerte y disfruta del juego!\n" << endl;
}
int Juego::getTutnoActual() {
    return turnoActual;
}
void Juego::incrementarTurno() {
    turnoActual++;
}
bool Juego::juegoTerminado() {
    if((primerJugador.getTesorosTotales() == 0 && primerJugador.getTesorosJuego() == 0) || (segundoJugador.getTesorosTotales() == 0 && segundoJugador.getTesorosJuego() == 0)){
        return true;
    }
    return false;
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
        while(!ingresoTesP1(fila,columna)){
            cout << "Error! el jugador ya posee un tesoro en la casilla" << endl;
            primerJugador.pedirCoordenadas(fila,columna);
        }
        if(tableroJuego.compararTesoros()){
            cout << "SE HAN INGRESADO 2 TESOROS EN LA MISMA CASILLA" << '\n';
            cout << fila << ", " << columna << endl;
        }
        primerJugador.depositarTesoro();
        ingresos++;
    }
    //tableroJuego.mostrarTesoros();
}
void Juego::ingresoInicialP2() {
    int ingresos = 0;
    while( ingresos < 4){
        int fila, columna;
        segundoJugador.pedirCoordenadas(fila,columna);
        while(!ingresoTesP2(fila,columna)){
            cout << "Error! el jugador ya posee un tesoro en la casilla" << endl;
            segundoJugador.pedirCoordenadas(fila,columna);
        }
        if(tableroJuego.compararTesoros()){
            cout << "SE HAN INGRESADO 2 TESOROS EN LA MISMA CASILLA" << '\n';
            cout << fila << ", " << columna << endl;
        }
        segundoJugador.depositarTesoro();
        ingresos++;
    }
    tableroJuego.imprimirTableroP2();
}
void Juego::turnoPrimerJugador() {
    cout << "TURNO DEL PRIMER JUGADOR" << endl;
    //esta funcion esta pensada para abarcar todas las funcionalidades poibles
    int fila, columna;
    char respuesta = primerJugador.pedirIngreso();
    //le pregunta al jugador que se desea ingresar
    if(respuesta == '$' && primerJugador.ingresoTesoro()){
        //se valida el ingreso del usuario y si el jugador tiene tesoros disponibles para depositar
        primerJugador.pedirCoordenadas(fila,columna);
        //HAY QUE VALIDAR QUE LA CASILLA NO ESTE OCUPADA CON UN TESORO DEL JUGADOR
        while(!(tableroJuego.guardarIngresoTesoroP1(fila,columna))){
            cout << "Error! se ha intentado ingresar un tesoro en una casilla ocupada" << '\n';
            cout << "Hay un tesoro en la casilla: " << fila <<", " << columna << endl;
            primerJugador.pedirCoordenadas(fila,columna);
        }
        //Si esto no pasa, significa que el tesoro de guardo exitosamente
        //Luego de validar el ingreso hay 3 casos a examinar
        //1. el jugador pone el tesoro sobre un espia enemigo
        //2. el jugador pone el tesoro sobre un tesoro enemigo
        //3. el jugador pone el tesoro en una casilla limpia
        //CASO 1: el jugador pone un tesoro sobre un espia enemigo
        if(tableroJuego.tesoroPerdidoP1()){
            //evalua si hay un espia en la casilla, y de ser asi lo elimina y regresa true
           cout << "Se ah ingresado un tesoro en una casilla con un espia infiltrado, el tesoro ha desaparecido" << endl;
           primerJugador.reducirTesoros();
        }
        //CASO 2: jugador pone tesoro sobre tesoro enemigo.
        else if(tableroJuego.compararTesoros()){
            //regresa true si hay un tesoro en las mismas coordenadas
            cout << "ATENCION! Hay un 2 tesoros escondidos en :" << '\n';
            cout << fila << ", " << columna << endl;
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
            //regresa true si hay un tesoro en la misma casilla que un espia del mismo jugador
            //la funcion elimina el tesoro del tablero "recuperandolo" y dandole total libertad al jugador de usarlo en otro turno
            tableroJuego.restringirCasilla(fila,columna);
            //Se restringe y se almacena la casilla
            primerJugador.tesoroRecuperado();
            //se incrementa el numero de tesoros que posee el jugador
        }
        //CASO 2: el espia se ingresa sobre el tesoro enemigo
        else if(tableroJuego.tesoroPerdidoP2()){
            //El espia se ingreso sobre un tesoro enemigo, la funcion lo detecta y lo "captura"
            cout << "Un tesoro rival ha sido eliminado en :" << fila << ", " << columna << endl;
            segundoJugador.reducirTesoros();
            //se reducen los tesoros del segundo jugador
        }
            //CASO 3: el espia se encuentra con un espia enemigo
        else if(tableroJuego.compararEspias()){
            //regresa true si hay 2 espias en la misma casilla y ambos se eliminan
            cout << "Dos espias se encontraron en una mision. Ambos han caido en un duelo a muerte con cuchillos" << '\n';
            cout << "JUEGO: Acaso dijo, duelo a muerte con cuchillos?" << endl;
        }
        //CASO 4: el espia se ingresa en una casilla cualquiera
        else{
            if(tableroJuego.getLongJugador1() > 0){
                int movimiento = primerJugador.moverTesoro();
                if(movimiento == 1){
                    int auxFil, auxCol, coordX, coordY;
                    cout << "Ingrese la ubicacion del tesoro que desea mover" << '\n';
                    primerJugador.pedirCoordenadas(auxFil, auxCol);
                    while(!tableroJuego.seleccionarTesoroP1(auxFil, auxCol)){
                        cout << "Error! no hay un tesoro en la casilla seleccionada" << endl;
                        primerJugador.pedirCoordenadas(auxFil, auxCol);
                    }
                    cout << "Ingrese la casilla a la que desea mover el tesoro" << endl;
                    primerJugador.pedirCoordenadas(coordX, coordY);
                    tableroJuego.moverTesoroP1(auxFil, auxCol, coordX, coordY);
                }
            }
        }
    }
    else{
        cout <<"Error! respuesta no aceptada, intente en su proximo turno." << endl;
    }

}
void Juego::turnoSegundoJugador() {
    cout << "TURNO DEL SEGUNDO JUGADOR" << endl;
    //esta funcion esta pensada para abarcar todas las funcionalidades poibles
    int fila, columna;
    char respuesta = segundoJugador.pedirIngreso();
    //le pregunta al jugador que se desea ingresar
    if(respuesta == '$' && segundoJugador.ingresoTesoro()){
        while(!tableroJuego.guardarIngresoTesoroP2(fila,columna)){
            cout << "Error! se ha intentado ingresar un tesoro en una casilla ocupada" << '\n';
            cout << "Hay un  tesoro en la casilla: " << fila << ", " << columna << endl;
        }
        if(tableroJuego.tesoroPerdidoP2()){
            cout << "habia un espia enemigo infiltrado en la casilla, el tesoro ha sido cpaturado" << endl;
            segundoJugador.reducirTesoros();
        }
        else if(tableroJuego.compararTesoros()){
            cout << "2 jugadores han ingresado un tesoro en la misma casilla" << '\n';
            cout << "La casilla es: " << fila << ", " << columna << endl;
        }
    }
    else if(respuesta == 'E' || respuesta == 'e'){
        segundoJugador.pedirCoordenadas(fila,columna);
        while(!tableroJuego.espiaInfiltradoP2(fila,columna)){
            cout << "Error! el jugador ya tiene un espia en esa casilla" << endl;
            segundoJugador.pedirCoordenadas(fila,columna);
        }
        //CASO 1: el espia ingresa sobre el tesoro de un jugador y lo reecupera
        if(tableroJuego.espiaSobreTesosoP2()){
            tableroJuego.restringirCasilla(fila,columna);
            segundoJugador.tesoroRecuperado();
        }
        //CASO 2: el espia se ingresa sobre un tesoro enemigo y lo captura
        else if(tableroJuego.tesoroPerdidoP1()){
            primerJugador.reducirTesoros();
        }
        //CASO 3: el espia se encuentra con un espia enemigo
        else if(tableroJuego.compararEspias()){
            cout << "Dos espias se han tenido un duelo y ambos han desaparecido" << endl;
        }
        //CASO 4: Se le pregunta al jugador si desea mover un tesoro
        else{
            if(tableroJuego.getLongJugador2() > 0){
                int movimiento = segundoJugador.moverTesoro();
                if(movimiento == 1){
                    int auxFil, auxCol, coordX, coordY;
                    cout << "Ingrese las casillas del tesoro que desea mover" << '\n';
                    while(!tableroJuego.seleccionarTesoroP2(fila,columna)){
                        cout << "Error! no hay ningun tesoro en la casilla seleccionada" << endl;
                        segundoJugador.pedirCoordenadas(auxFil,auxCol);
                    }
                    cout << "Por favor ingrese las casillas donde quiere mover el tesoro" << endl;
                    segundoJugador.pedirCoordenadas(coordX,coordY);
                    tableroJuego.moverTesoroP2(auxFil, auxCol, coordX, coordY);
                }
                else{
                    cout << "Espia ingresado exitosamente" << endl;
                }
            }
        }
    }
    else{
        cout << "Ingreso invalido, se terminara el turno" << endl;
    }
}
void Juego::turno() {
    turnoPrimerJugador();
    tableroJuego.imprimirTableroP1();
    turnoSegundoJugador();
    tableroJuego.imprimirTableroP2();
    incrementarTurno();
}
void Juego::juego() {
    mostrarReglas();
    ingresoInicialP1();
    ingresoInicialP2();
    cout << '\n' << endl;
    while(!juegoTerminado()){
        turno();
    }
}