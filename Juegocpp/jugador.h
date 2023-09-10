#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "tablero.h"

class Player {
private:
    std::string userName;
    int tesorosDisponibles;
    int cantidadEspias;
    bool penalidad;

public:
    Player(std::string usuario = "jugador", int tesorosIniciales = 4, int espiasIniciales = 0, bool castigo = false);

    void pedirCoordenadas(int *pFila, int *pColumna);
    void ingresarTesoros(Tablero& tablero);
    char pedirIngreso();
    bool aplicarPenalidad(Tablero& tablero);
};

#endif