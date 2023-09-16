#include <iostream>
#include "tablero.h"
#include "jugador.h"
using namespace std;

class Reglas{
private:
    Tablero tableroJuego;
    Player jugadorNumeroUno;
    Player jugadorNumeroDos;
public:
    Reglas(Tablero tablero, Player jugador1, Player jugador2):
    tableroJuego(tablero),jugadorNumeroUno(jugador1),jugadorNumeroDos(jugador2){}
    void imprimirCoordenadas(int fila, int columna){
        cout << "Se ha ingresaso un tesoro en las coordenadas: " << fila << ", " << columna << endl;
    }
    bool tesoroRecuperadoPrimerJugador(){
        //funcion para el primer jugador
        //comprueba si hay un tesoro en el lugar ingresado y de ser asi lo recupera
        //y da penalidad a la casilla
        if(tableroJuego.recuperarTesoroPrimerJugador()){
            //la misma funcion guarda las coordenadas de las casillas inactivas
            return true;
        }
        return false;
    }
    bool tesoroRecuperadoSegundoJugador(){
        //funciona igual que la funcion de arriba pero con el jugador 2
        if(tableroJuego.recuperarTesoroSegundoJugador()){
            return true;
        }
        return false;
    }
};