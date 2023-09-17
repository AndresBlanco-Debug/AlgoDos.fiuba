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
void Juego::primerIngreso() { //esta funcion se asegura de
    int fila, columna, auxFil, auxCol;
    int ingresoP1 = 0;
    //esta funcion esta pensada para ingresar los 4 tesoros iniciales de cada jugador
    //el primer jugador ingresa las coordenadas deseadas.
    for(int i = 0; i < 4; i++){
        primerJugador.pedirCoordenadas(fila,columna);
        //revisa si el jugador ya coloco un juegador en la casilla
        if(!tableroJuego.guardarIngresoTesoroP1(fila,columna)){
            cout << "Error! ej jugador ya tiene un tesoro en esa casilla" << endl;
            i--; //reduce el contador para generar otro intento de ingreso
        }
        ingresoP1++;
        cout << "Cantidad de tesoros ingresados: " << ingresoP1 << endl;
        tableroJuego.actualizarTablero(fila,columna);
    }
}
