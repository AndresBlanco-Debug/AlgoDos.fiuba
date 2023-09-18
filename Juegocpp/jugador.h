#ifndef JUGADOR_H
#define JUGADOR_H

class Player{
private:
    //Tablero tableroJugador;
    int tesorosTotales;
    int tesorosEnJuego;
    int cantidadEspias;
public:
    Player();
    void pedirCoordenadas(int &fila, int &columna);
    void aumentarEspias();
    void reducirTesoros();
    void tesoroRecuperado();
    bool ingresoTesoro();
    char pedirIngreso();
    int moverTesoro();
    int getTesorosTotales();
};
#endif