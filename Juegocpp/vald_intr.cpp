#include <iostream>
#include "jugador.h"

bool validacionCasilla(char **Tablero, int fila, int columna, char caracter, Player jugador){
    bool casillaValida = false;
    if(Tablero[fila][columna] == caracter){
        //caso de un $ sobre $
        //caso de espia sobre espia
    }
    //cuando Tablero[fila][columna] != caracter
    else{
        //caso de un tesoro y un espia
        //caso normal de validacion
    }
}

bool incautarTesoro(char **Tablero, int fila, int columna, Player jugador, char caracter){
    //FUNCION QUE DEFINE LAS INTERACCIONES DEL ESPIA;
    if(Tablero[fila][columna] != caracter){ //SUPONIENDO QUE EL CARACTER ES DIFERENTE DE "E"
        if(Tablero[fila][columna] == '$'){
            return true;
            //REGRESA TRUE AL HABER ENCONTRADO UN TESORO
        }
    }else{
        return false;
    }
}