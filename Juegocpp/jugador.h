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
    int ordenJuego;
    Player(std::string usuario = "jugador", int tesorosIniciales = 4, int espiasIniciales = 0, bool castigo = false, int ordenJuego = 0, int tesorosAlmacenados = 0, int tesorosTablelro = 4);
    

    void pedirCoordenadas(int &fila, int &columna);
    void ingresarTesoros(Tablero& tablero);
    char pedirIngreso();
    bool aplicarPenalidad(Tablero& tablero);
    void reducirTesoros();
    bool validarIngresoTesoro();
};

#endif