#include <iostream>
#include "tablero.h"
#include "jugador.h"
#include "reglas.h"
using namespace std;
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
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
            while(tableroJuego.tesoroRepetido(fila,columna,tesoro)){
                reglamento.imprimirCoordenadas(fila,columna);
                jugadorNumeroUno.pedirCoordenadas(fila,columna);
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
            jugadorNumeroDos.pedirCoordenadas(fila,columna);
            while(tableroJuego.tesoroRepetido(fila,columna,tesoro)){
                //se ejecuta el codigo de castido
            }
            tableroJuego.guardarIgresoTesoro(fila,columna,2);
            ingresoExitoso++;
        }
    }//----------------------------------------------------------------------------------------------------
    void ingresoPrimerJugador(char ingreso){
        int fila, columna;
        if(ingreso == '$'){
            if(jugadorNumeroUno.validarIngresoTesoro()){
                jugadorNumeroUno.pedirCoordenadas(fila,columna);
                while(tableroJuego.tesoroRepetido(fila,columna,ingreso)){
                    reglamento.imprimirCoordenadas(fila,columna);
                    jugadorNumeroUno.pedirCoordenadas(fila, columna);
                }
                tableroJuego.guardarIgresoTesoro(fila,columna,1);
            }else{
                cout << "Error! Todos los tesoros se encuentran en juego" << endl;
            }
        }
        //HAY QUE PENSAR EN LA FUCNION PARA RECUPERAR EL TESORO.
        else if(ingreso == 'E'){
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
            if(tableroJuego.compararCoordenadas(fila,columna,1)){
                //se valida si hay un tesoro en la posicion que se ingreso en espia
                cout << "Se ha encontrado un tesoro enemigo en la casilla!" << endl;
                reglamento.imprimirCoordenadas(fila,columna);
                tableroJuego.guardarIngresoEspia(fila,columna,1);
                //se borra el tesoro y se reducen todos los tesoros en general
            }
            else{
                tableroJuego.guardarIngresoEspia(fila, columna, 1);
                //se pregunta si se quiere mover el tesoro
                int respuesta = jugadorNumeroUno.moverTesoro();
                if(respuesta == 1){
                    int nuevafila, nuevacolumna;
                    jugadorNumeroUno.pedirCoordenadas(nuevafila,nuevacolumna);
                    while(tableroJuego.tesoroRepetido(nuevafila,nuevacolumna,'$')){
                        reglamento.imprimirCoordenadas(nuevafila,nuevacolumna);
                    }
                    tableroJuego.moverTesoroPrimerJugador(fila,columna,nuevafila,nuevacolumna);
                    //la funcion ya actualiza el tablero
                }
                else{
                }

            }
        }
    }
    
    int turno(int cantidadTurnos){
        int primeraFila, primeraColumna, segunundaFila, segundaColumna;
        char ingresoJugadorUno = jugadorNumeroUno.pedirIngreso(); //E
        char ingresoJugadorDos = jugadorNumeroDos.pedirIngreso();
        if(ingresoJugadorUno == '$'){
            if(jugadorNumeroUno.validarIngresoTesoro()){
                jugadorNumeroUno.pedirCoordenadas(primeraFila,primeraColumna);
                while(tableroJuego.tesoroRepetido(primeraFila,primeraColumna,ingresoJugadorUno)){
                    reglamento.imprimirCoordenadas(primeraFila,primeraColumna);
                    jugadorNumeroUno.pedirCoordenadas(primeraFila,primeraColumna);
                }
                tableroJuego.guardarIgresoTesoro(primeraFila,primeraColumna,1);
            }else{
                cout << "Error! Todos los tesoros se encuentran en juego" << endl;
            }    
        }
        //el caso continua pero la funcion se desarolla arriba.
    }
};
