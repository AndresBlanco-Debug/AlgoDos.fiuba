#ifndef TABLERO_H
#define TABLERO_H
#include <vector>
#include "juego.h"
class Tablero
{
private:
    char tablero[20][20]; //array estatico de 20x20
    int fila;
    int columna;
    char casillaSola;
    Player jugadorGenerico;
    int cantidadTesoros;
    int cantidadEspias;
    bool casillaInactiva;
    std::vector<std::pair<int,int> > tesorosPrimerJugador;
    std::vector<std::pair<int,int> > tesorosSegundoJugador;
    std::vector<std::pair<int,int> > espiasPrimerJugador;
    std::vector<std::pair<int,int> >  espiasSegundoJugador;
    std::vector<std::pair<int,int> > casillaInvalida;
public:
    //construir el tablero
    int getLongJugador1();
    int getLongJugador2();
    bool compararTesoros();
    void imprimirTablero();
    
};


#endif