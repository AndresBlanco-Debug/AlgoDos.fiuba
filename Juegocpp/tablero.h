#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <fstream>

class Tablero {
private:
    char **tablero;
    int filas;
    int columnas;

public:
    Tablero(int filas, int columnas);
    ~Tablero();
    void generarTablero();
    void imprimirTablero(const char* nombreArchivo);
    void liberarMemoria();
   void guardarIgresoTesoro(int fila, int columna, int jugador);
    void guardarIngresoEspia(int fila, int columna, int jugador);
    bool tesoroRepetido(int fila, int columna);
    void actualizarCasilla(int fila, int columna, char caracter);
    void moverTesoroPrimerJugador(int fila, int columna, int nuevaFila, int nuevaColumna);
    void moverTesoroSegundoJugador(int fila, int columna, int nuevaFila, int nuevaColumna);
    bool recuperarTesoroPrimerJugador();
    bool recuperarTesoroSegundoJugador();
    bool compararTesoros();
    bool compararEspias(int fila, int columna, int caso);
    void resetearCasilla(int fila, int columna);
    bool espiaEnPrimerJugador();
    bool espiaEnSegundoJugador();
    bool eliminarEspias();
    bool casillaInvalida(int fila, int columna);
    bool espiaRepetido(int fila, int columna);
    char obtenerValorCelda(int fila, int columna);
};

#endif