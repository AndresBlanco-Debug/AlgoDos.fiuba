#include <iostream>
#include <cstdlib>
#include "vald_intr.h"
#include "tablero.h"

using namespace std;

class Player {
private:
    std::string userName;
    int tesorosDisponibles;
    int cantidadEspias;
    bool penalidadFlag;

public:
    int ordenJuego;
    Player(std::string usuario = "jugador", int tesorosIniciales = 4, int espiasIniciales = 0, bool castigo = false, int ordenJuego = 0)
        : userName(usuario), tesorosDisponibles(tesorosIniciales), cantidadEspias(espiasIniciales), penalidadFlag(castigo), ordenJuego(0) {}

    void pedirCoordenadas(int &fila, int &columna) {
        std::cout << "Ingrese la fila deseada: " << std::endl;
        std::cin >> fila;
        std::cout << "Ingrese la columna deseada: " << std::endl;
        std::cin >> columna;
    }
    void ingresarTesoros(Tablero &tablero, int &ingresosTotales) {
        ingresosTotales = 0;
        char tesoro = '$';
        for (int i = 0; i < tesorosDisponibles; i++) {
            int fila, columna;
            pedirCoordenadas(fila, columna);
            while (tablero.ingresoRepetido(fila, columna, tesoro)) {
                std::cout << "Ingreso repetido. Por favor, ingrese coordenadas válidas." << std::endl;
                pedirCoordenadas(fila, columna);
            }
            tablero.actualizarCasilla(fila, columna, tesoro);
            ingresosTotales++;
        }
    }
    char pedirIngreso() {
        char ingreso;
        std::cout << "Ingrese $ para tesoro o E para espía: " << std::endl;
        std::cin >> ingreso;
        return ingreso;
    }

    bool tienePenalidad() const {
        return penalidadFlag;
    }
};
