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
    bool casillaValida(int fila, int columna, char caracter, bool penalidad);
    bool ingresoRepetido(int fila, int columna, char caracter);
    void actualizarCasilla(int fila, int columna, char caracter);
};

#endif