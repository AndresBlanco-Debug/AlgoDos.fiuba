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
    tableroJuego(tablero),jugadorNumeroUno(jugador1),jugadorNumeroDos(jugador2){}//Se construye el objeto en si
    //-----------------------------------------------------------------------------------
    void asigarTurnos(){
        int ordenTurno = (rand() % 2) + 1;
        jugadorNumeroUno.ordenJuego = ordenTurno;
        jugadorNumeroDos.ordenJuego = (ordenTurno == 1) ? 2: 1;
    }//----------------------------------------------------------------------------------
    bool recuperarTesoro(){
    }
};