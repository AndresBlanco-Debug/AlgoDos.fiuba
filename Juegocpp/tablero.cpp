#include "tablero.h"
using namespace std;
Tablero::Tablero(){
    //constructor de la clase con tablero estatico
    fila = 20;
    columna = 20;
    casillaSola = '#';
    cantidadTesoros = 0;
    cantidadEspias = 0;
    casillaInactiva = false;
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){
            tablero[i][j] = casillaSola;
        }
    }
}

int Tablero::getLongJugador1(){
    return tesorosPrimerJugador.size();
}

int Tablero::getLongJugador2(){
    return tesorosSegundoJugador.size();
}


bool Tablero::compararTesoros(){
    bool encontrado = false;
    int longitud = getLongJugador1();
    for(int i = 0; i < longitud; i++){
        //se recorre el vector de tesoros del primer jugador
        for(int j = 0; j < getLongJugador2(); j++){
            //se recorre el segundo jugador
            if(tesorosPrimerJugador[i] == tesorosSegundoJugador[j]){
                encontrado = true;
            }
        }
    }
    return encontrado;
}

void Tablero::imprimirTablero(){
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){
            cout << tablero[i][j] << ' ';
        }
        cout << endl;
    }
}