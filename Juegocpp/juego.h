#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "jugador.h"
#include "reglas.h"
class Tablero;
class Jugador;
class Reglas;

class Juego
{
private:
    Tablero tableroJuego;
    Player jugadorNumeroUno;
    Player jugadorNumeroDos;
    Reglas reglamento;

public:
    Juego(Tablero tableroInicial, Player jugador1, Player jugador2, Reglas interacciones);

    void ingresarTesorosPrimerJugadorINICIO();
    void ingresarTesorosSegundoJugadorINICIO();

    void IngresoTesoroPrimerJugador();
    void ingresoEspiaPrimerJugador();
    void IngresoTesoroSegundoJugador();
    void ingresoEspiaSegundoJugador();
    void turno();
    void juego();
};

#endif