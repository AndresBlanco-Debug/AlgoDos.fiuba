#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Tablero;

class Player {
private:
    Tablero* tableroJuego;
    std::string userName;
    int tesorosTotales;
    int tesorosRecuperados;
    int tesorosEnJuego;
    int tesorosCapturados;
    int cantidadEspias;
    bool penalidadFlag;

public:
    Player(std::string usuario = "jugador", int tesorosIniciales = 4, int espiasIniciales = 0, bool castigo = false, int ordenJuego = 0, int tesorosAlmacenados = 0, int tesorosTablelro = 4, int tesorosNoJugables = 0);
    void pedirCoordenadas(int &fila, int &columna);
    char pedirIngreso();
    bool validarIngresoTesoro();
    char val();
    bool moverTesoro();
    void reducirTesoros();
    void espiaInfiltrado();
    void espiaCaido();
    int getEspias();
    void tesoroCapturado();
    void aumentarEspias();
    int getTesorosTotales();
    void mostrarTableroJugador() const;
};

#endif