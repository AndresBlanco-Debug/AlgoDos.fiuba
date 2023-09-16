#include <iostream>
#include "tablero.h"
#include "jugador.h"
#include "reglas.h"
#include "juego.h"

using namespace std;

int main() {
    Tablero tablero;
    Player jugador1;
    Player jugador2;
    Reglas reglas(tablero, jugador1, jugador2);
    Juego juego(tablero, jugador1, jugador2, reglas);

    // Ejecuta el juego
    juego.juego();

    return 0;
}