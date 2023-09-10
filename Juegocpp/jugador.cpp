#include <iostream>
#include <cstdlib>
#include "vald_intr.h"
#include "tablero.h"

using namespace std;

class Player{
private:
    string userName;
    int tesorosDisponibles;
    int cantidadEspias;
    bool penalidad;
public:
    Player(string usuario = "jugador", int tesorosIniciales = 4, int espiasIniciales = 0, bool castigo = false):
    userName(usuario),tesorosDisponibles(tesorosIniciales),cantidadEspias(espiasIniciales),penalidad(castigo){
    };
    void pedirCoordenadas(int *pFila, int *pColumna){
        cout << "Ingrese la fila deseada: " << '\n';
        cin >> *pFila;
        cout << "Ingrese la columna deseada: " << endl;
        cin >> *pColumna;
    }
    void ingresarTesoros(Tablero& tablero){
        char tesoro = '$';
        for (int i = 0; i < tesorosDisponibles; i++) {
            int fila, columna;
            pedirCoordenadas(&fila, &columna);
            while (tablero.ingresoRepetido(fila, columna, tesoro)) {
                pedirCoordenadas(&fila, &columna);
            }
            tablero.actualizarCasilla(fila, columna, tesoro);
        }
    }   
    char pedirIngreso(){
        char ingreso;
        cout << "Ingrese $ para tesoro `o E para espia: " << endl;
        cin >> ingreso;
        return ingreso;
    }
    bool penalidad(Tablero& Tablero){
        
    }
};