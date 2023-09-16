#ifndef TABLERO_H
#define TABLERO_H

#include <vector>

class Tablero {
private:
    char **tablero;
    int filas;
    int columnas;
    // vectores para almacenar coordenadas;
    std::vector<std::pair<int, int> > tesorosJugador1;
    std::vector<std::pair<int, int> > espiasJugador1;
    std::vector<std::pair<int, int> > tesorosJugador2;
    std::vector<std::pair<int, int> > espiasJugador2;
    std::vector<std::pair<int, int> > casillasInactivas;

public:
    Tablero();
    ~Tablero();
    void generarTablero();
    void imprimirTablero(const char* nombreArchivo);
    void guardarIngresoTesoro(int fila, int columna, int jugador);
    void guardarIngresoEspia(int fila, int columna, int jugador);
    bool tesoroRepetido(int fila, int columna);
    bool recuperarTesoroPrimerJugador();
    bool recuperarTesoroSegundoJugador();
    bool compararTesoros();
    bool espiaEnSegundoJugador();
    bool espiaEnPrimerJugador();
    bool eliminarEspias();
    void resetearCasilla(int fila, int columna);
    bool casillaInvalida(int fila, int columna);
    bool espiaRepetido(int fila, int columna);
    char obtenerValorCelda(int fila, int columna) const;
    void liberarMemoria();
};

#endif