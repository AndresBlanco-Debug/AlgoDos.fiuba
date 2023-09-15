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
        char tesoro = '$';
        for(int i = 0; i < 4; i++){
            int fila, columna;
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
            while(tableroJuego.tesoroRepetido(fila,columna,tesoro)){
                reglamento.imprimirCoordenadas(fila,columna);
                jugadorNumeroUno.pedirCoordenadas(fila,columna);
            }
            tableroJuego.guardarIgresoTesoro(fila,columna,1);  
        }
    }//---------------------------------------------------------------------------------------------------
    void ingresarTesorosSegundoJugador(){
        char tesoro = '$';
        for(int i = 0; i < 4; i++){
            int fila, columna;
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
            while(tableroJuego.tesoroRepetido(fila,columna,tesoro)){
                reglamento.imprimirCoordenadas(fila,columna);
                jugadorNumeroUno.pedirCoordenadas(fila,columna);
            }
            tableroJuego.guardarIgresoTesoro(fila,columna,2);  
        }
    }//----------------------------------------------------------------------------------------------------
    void ingresoPrimerJugador(char ingreso){
        int fila, columna;
        if(ingreso == '$'){
            if(jugadorNumeroUno.validarIngresoTesoro()){
                jugadorNumeroUno.pedirCoordenadas(fila,columna);
                while(tableroJuego.tesoroRepetido(fila,columna,ingreso)){
                    if(tableroJuego.compararTesoros(fila,columna,1)){
                        cout << "SE HA DETECTADO UN TESORO ENEMIGO!" << '\n';
                        reglamento.imprimirCoordenadas(fila,columna);
                        jugadorNumeroUno.pedirCoordenadas(fila,columna);
                    }
                    cout << "Error! tesoro ya almacenado" << '\n';
                    reglamento.imprimirCoordenadas(fila,columna);
                    jugadorNumeroUno.pedirCoordenadas(fila, columna);
                }
                tableroJuego.guardarIgresoTesoro(fila,columna,1);
            }else{
                cout << "Error! Todos los tesoros se encuentran en juego" << endl;
            }
        }
        //SIEMPRE HAY QUE VALIDAR QUE LOS TESOROS SEAN DEL JUGADOR CORRESPONDIENTE PERO SOLO PARA MOVER O RECUPERAR.
        //HAY QUE PENSAR EN LA FUCNION PARA RECUPERAR EL TESORO.
        else if(ingreso == 'E'){
            jugadorNumeroUno.pedirCoordenadas(fila,columna);
            if(tableroJuego.compararTesoros(fila,columna,1)){
                //se valida si hay un tesoro en la posicion que se ingreso en espia
                cout << "Se ha encontrado un tesoro enemigo en la casilla!" << endl;
                reglamento.imprimirCoordenadas(fila,columna);
                tableroJuego.guardarIngresoEspia(fila,columna,1);
                //se borra el tesoro y se reducen todos los tesoros en general
            }
            //caso si se topa con espia del enemigo
            //antes de hacer eso tiene que haber ingresado el dato.
            else if(tableroJuego.compararEspias(fila,columna,1)){
                //se ejecuta si el espia se encuentra con un espia enemigo, segun reglas deben eliminarse.
                //se reducen los espias de ambos jugadores.
                jugadorNumeroUno.espiaCaido();
                jugadorNumeroDos.espiaCaido();
                //se tiene que cambiar el tablero
            }
            //caso donde se mueve el tesoro
            //hay que guardar el espia
            else{
                int respuesta = jugadorNumeroUno.moverTesoro();
                if(respuesta == 1){
                    int ejeX, ejeY;
                    cout << "Ingrese las casillas del tesoro que desea mover" << endl;
                    jugadorNumeroUno.pedirCoordenadas(ejeX,ejeY);
                    //hay que validar que ahi haya un tesoro
                    if(tableroJuego.tesoroRepetido(ejeX,ejeY,'$') && !(tableroJuego.compararTesoros(ejeX,ejeY,1))){
                        //confirma que en la casilla que ingreso hay un tesoro y valida que es del jugador
                        int auxFila, auxColumna;
                        cout << "Indique donde quiere mover el tesoro" << endl;
                        jugadorNumeroUno.pedirCoordenadas(auxFila,auxColumna);
                        while(tableroJuego.tesoroRepetido(auxFila, auxColumna,'$')){
                            reglamento.imprimirCoordenadas(auxFila, auxColumna);
                            jugadorNumeroUno.pedirCoordenadas(auxFila,auxColumna);
                        }
                        tableroJuego.moverTesoroPrimerJugador(ejeX, ejeY, auxFila, auxColumna);
                        tableroJuego.guardarIngresoEspia(fila, columna,1);
                    }else{
                        cout << "Error! esa es una casilla vacia" << '\n';
                        jugadorNumeroUno.pedirCoordenadas(fila, columna);
                        while(tableroJuego.)
                    }
                    //hay que pedir otras coordenadas para que se pueda mover cualquier tesoro
                }else{
                    tableroJuego.guardarIngresoEspia(fila,columna,1);
                    cout << "Se ha ingresado un espia correctamente" << endl;

                }
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
