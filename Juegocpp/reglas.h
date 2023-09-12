#ifndef REGLAS_H
#define REGLAS_H

#include "tablero.h"
#include "jugador.h"

class Reglas {
private:
    Tablero tableroJuego;
    Player jugadorNumeroUno;
    Player jugadorNumeroDos;

public:
    Reglas(Tablero tablero, Player jugador1, Player jugador2);

    bool recuperarTesoro();
    bool ingresoRepetido(char ingreso, int fila, int columna);
    void imprimirCoordenadas(int fila, int columna);
};

#endif