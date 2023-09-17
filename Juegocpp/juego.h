#ifndef JUEGO_H
#define JUEGO_H
#include "tablero.h"
#include "jugador.h"
class Juego{
private:
    Tablero tableroJuego;
    Player primerJugador;
    Player segundoJugador;
    int turnoActual;
public:
    Juego(); //constructor de la clase.
    int getTutnoActual();
    void incrementarTurno();
    void primerIngreso();
    //void turno();
};

#endif