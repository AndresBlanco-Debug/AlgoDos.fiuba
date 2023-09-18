#ifndef TABLERO_H
#define TABLERO_H
#include <vector>
class Tablero
{
private:
    char tablero[20][20]; //array estatico de 20x20
    int fila;
    int columna;
    char casillaSola;
    //Player jugadorGenerico;
    int cantidadTesoros;
    int cantidadEspias;
    int casillaInactiva;
    std::vector<std::pair<int,int> > tesorosPrimerJugador;
    std::vector<std::pair<int,int> > tesorosSegundoJugador;
    std::vector<std::pair<int,int> > espiasPrimerJugador;
    std::vector<std::pair<int,int> >  espiasSegundoJugador;
    std::vector<std::pair<int,int> > casillaInvalida;
public:
    //construir el tablero
    Tablero();
    int getLongJugador1();
    int getLongJugador2();
    int getLongEspiasP1();
    int getLongEspiasP2();
    void reducirPenalidad();
    int getLenInvalidCoord();
    void imprimirTablero();
    char getCasillaActual(int fila, int columna);
    bool compararTesoros();
    bool compararEspias();
    bool guardarIngresoTesoroP1(int fila, int columna);
    bool guardarIngresoTesoroP2(int fila, int columna);
    bool espiaInfiltradoP1(int fila, int columna);
    bool espiaInfiltradoP2(int fila, int columna);
    bool tesoroPerdidoP1();
    bool tesoroPerdidoP2();
    bool espiaSobreTesosoP1();
    bool espiaSobreTesosoP2();
    bool moverTesoroP1(int fila, int columna);
    bool moverTesoroP2(int fila, int columna);
    void restringirCasilla(int fila, int columna);
    bool tesoroRecuperadoP1();
    bool tesoroRecuperadoP2();
    bool invalidarCasilla(int fila, int columna);
    void imprimirTableroP1();
    void imprimirTableroP2();
};

#endif