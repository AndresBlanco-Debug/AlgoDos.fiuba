#include <iostream>
#include "tablero.h"
#include "jugador.h"
using namespace std;

class Juego
{
private:
    Tablero tablero;
    Player jugador1;
    Player jugador2;
public:
    void juego(){
        //SE INGRESAN LOS TESOROS
        cout << "Ahora se ingresaran los tesoros." << '\n';
        jugador1.ingresarTesoros(tablero);
        cout << "Ingrese los tesoros jugador 2." << endl;
        jugador2.ingresarTesoros(tablero);
        //SE TERMINA EL INGRESO DE TESOROS.
        tablero.imprimirTablero("tablero.txt");
        while(true){
            //TURNO DEL PRIMER JUGADOR
            
        }
    }
};