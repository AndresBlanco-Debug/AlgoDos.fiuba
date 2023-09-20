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
    void mostrarReglas();
    int getTutnoActual();
    void incrementarTurno();
    bool ingresoTesP1(int fila, int columna);
    bool ingresoTesP2(int fila, int columna);
    void ingresoInicialP1();
    void ingresoInicialP2();
    void turnoPrimerJugador();
    void turnoSegundoJugador();
    void turno();
    bool juegoTerminado();
    void juego();
};

#endif