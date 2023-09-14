#include <iostream>
#include "tablero.h"
#include "jugador.h"
using namespace std;

class Reglas{
private:
    Tablero tableroJuego;
    Player jugadorNumeroUno;
    Player jugadorNumeroDos;
public:
    Reglas(Tablero tablero, Player jugador1, Player jugador2):
    tableroJuego(tablero),jugadorNumeroUno(jugador1),jugadorNumeroDos(jugador2){}//Se construye el objeto en si
    //-----------------------------------------------------------------------------------
    bool ingresoRepetido(char ingreso, int fila, int columna){
        bool repetido = false;
        if(tableroJuego.tesoroRepetido(fila, columna, ingreso)){
            repetido = true;
        }
        return repetido;
    }//------------------------------------------------------------------------------------
    void imprimirCoordenadas(int fila, int columna){
        cout << "Se ha ingresaso un tesoro en las coordenadas: " << fila << ", " << columna << endl;
    }
    bool casillaInactiva(int fila, int columna, bool rescate){
        bool penalidad = false;
        if(rescate){
            penalidad = true;
        }
        return penalidad;
    }
    void eliminarEspia(int fila, int columna){
        
    }
};