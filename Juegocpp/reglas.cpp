/*#include <iostream>
#include "reglas.h"
#include "tablero.h"
using namespace std;
Reglas::Reglas() {
    tablero;
}
bool Reglas::ingresoValidoTesoroP1(int fila, int columna) {
    bool casilla = true;
    if(tablero.getCasillaActual(fila,columna) == '$' && !(tablero.compararTesoros())){
        cout << "Error! un tesoro del jugador ya esta en esa casilla" << endl;
        casilla = false;
    }
}
void Reglas::imprimirCoordenadas(int fila, int columna) {
    cout << "Se ha/n encontrado tesoro/s en la casilla" << '\n';
    cout << "Fila: " << fila << "Columna: " << columna << endl;
}*/