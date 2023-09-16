#ifndef REGLAS_H
#define REGLAS_H

#include <iostream>
#include "tablero.h"
#include "jugador.h"
class Tablero;
class Jugador;

class Reglas {
private:
    Tablero tableroJuego;
    Player jugadorNumeroUno;
    Player jugadorNumeroDos;

public:
    Reglas(Tablero tablero, Player jugador1, Player jugador2);
    void imprimirCoordenadas(int fila, int columna);
    bool tesoroRecuperadoPrimerJugador();
    bool tesoroRecuperadoSegundoJugador();
};

#endif