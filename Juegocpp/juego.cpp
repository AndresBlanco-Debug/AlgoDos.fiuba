#include <iostream>
#include "tablero.h"
#include "jugador.h"
#include "reglas.h"

class Juego
{
private:
    Tablero tableroJuego;
    Player jugadorNumeroUno;
    Player jugadorNumeroDos;
    Reglas reglamento;
public:
    Juego(Tablero tableroInicial, Player jugador1, Player jugador2, Reglas interaciones):
    tableroJuego(tableroInicial),jugadorNumeroUno(jugador1),jugadorNumeroDos(jugador2),reglamento(interaciones){}
    //se inicia el juego
    void asigarTurnos(){
        int ordenTurno = (rand() % 2) + 1;
        jugadorNumeroUno.ordenJuego = ordenTurno;
        jugadorNumeroDos.ordenJuego = (ordenTurno == 1) ? 2: 1;
    }//----------------------------------------------------------------------------------------------------
    void ingresarTesorosPrimerJugador(){
        int ingresoExitoso = 0;
        char tesoro = '$';
        for(int i = 0; i < 4; i++){
            int fila, columna;
            jugadorNumeroUno.pedirCoordenadas(&fila,&columna);
            while(tableroJuego.tesoroRepetido(fila,columna,tesoro)){
                reglamento.imprimirCoordenadas(fila,columna);
                jugadorNumeroUno.pedirCoordenadas(&fila,&columna);
            }
            tableroJuego.guardarIgresoTesoro(fila,columna,1,ingresoExitoso);
            ingresoExitoso++;
        }
    }//---------------------------------------------------------------------------------------------------
    void ingresarTesorosPrimerJugador(){
        int ingresoExitoso = 0;
        char tesoro = '$';
        for(int i = 0; i < 4; i++){
            int fila, columna;
            jugadorNumeroDos.pedirCoordenadas(&fila,&columna);
            while(tableroJuego.tesoroRepetido(fila,columna,tesoro)){
                //se ejecuta el codigo de castido
            }
            tableroJuego.guardarIgresoTesoro(fila,columna,2,ingresoExitoso);
            ingresoExitoso++;
        }
    }//----------------------------------------------------------------------------------------------------
    void turno(){
        if(1){
            
        }
    }
};
