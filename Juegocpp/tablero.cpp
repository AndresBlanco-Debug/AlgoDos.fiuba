#include <iostream>
#include <vector>
#include <fstream>
#include "jugador.h"
using namespace std;

class Tablero {
private:
    char **tablero;
    int filas;
    int columnas;
    //vectores para almacenar coordenadas;
    vector<pair<int, int> >tesorosJugador1;
    vector<pair<int, int> >espiasJugador1;
    vector<pair<int, int> >tesorosJugador2;
    vector<pair<int, int> >espiasJugador2;

public:
    Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
        tablero = new char*[filas];
        for (int i = 0; i < filas; ++i) {
            tablero[i] = new char[columnas];
        }
    }
    ~Tablero() {
        liberarMemoria();
    }//--------------------------------------------------------------------------------------------------------------------
    void generarTablero() {
        char casillaCarac = '#';
        for (int fila = 0; fila < filas; fila++) {
            for (int columna = 0; columna < columnas; columna++) {
                tablero[fila][columna] = casillaCarac;
            }
        }
    }//----------------------------------------------------------------------------------------------------------------------
    //funcion para mostrar el tablero al principio del juego
    void imprimirTablero(const char* nombreArchivo) {
        ofstream file(nombreArchivo);
        if (!file) {
            cerr << "Error al crear el archivo." << endl;
            return;
        }
        for (int fila = 0; fila < filas; fila++) {
            for (int columna = 0; columna < columnas; columna++) {
                file << tablero[fila][columna];
            }
            file << endl;
        }
        file.close();
    }//------------------------------------------------------------------------------------------------------------------
    void guardarIgresoTesoro(int fila, int columna, int jugador, int ingresosTurno){
        if(jugador == 1 && ingresosTurno >= 0 && ingresosTurno < tesorosJugador1.size()){
            tesorosJugador1.push_back(make_pair(fila,columna));
        }
        else if(jugador == 2 && ingresosTurno >= 0 && ingresosTurno < tesorosJugador2.size()){
            tesorosJugador2.push_back(make_pair(fila,columna));
        }
        tablero[fila][columna] = '$';
    }//--------------------------------------------------------------------------------------------------------------------
    void guardarIngresoEspia(int fila, int columna, int jugador, int ingresosTurno){
        if(jugador == 1 && ingresosTurno >= 0 && ingresosTurno < espiasJugador1.size()){
            espiasJugador1.push_back(make_pair(fila,columna));
        }
        else if(jugador == 2 && ingresosTurno >= 0 && ingresosTurno < espiasJugador2.size()){
            espiasJugador2.push_back(make_pair(fila,columna));
        }
        tablero[fila][columna] = 'E';
    }//-------------------------------------------------------------------------------------------------------------------------
    bool ingresoRepetido(int fila, int columna, char caracter){
        bool valido = false;
        //caracter = '$';
        if(tablero[fila][columna] != caracter){
            valido = true;
        }
        else if(tablero[fila][columna] == caracter){

        }
        
    }//-----------------------------------------------------------------------------------------------------------------------------
    bool casillaValida(int fila, int columna, char caracter, bool penalidad){
        if(!penalidad){
            if(tablero[fila][columna] != '#'){
                return true;
        }else{
            return false;
            }
        }
    }//-----------------------------------------------------------------------------------------------------------------------------
    void mostrarTableroJugador(int jugador, const char* nombreArchivo){
        ofstream file(nombreArchivo);
        if(!file){
            cerr << "Error al generar el archivo! contacte con el programador inmediatamente";
            return;
        }
        for(int fila = 0; fila < filas; fila++){
            for(int columna = 0; columna < columnas; columna++){
                char casilla = '#';              
                if(jugador == 1){
                    for(const auto& tesoro : tesorosJugador1){}
                }
            }
        }
    }
    //-------------------------------------------------------------------------------------------------------------------------------
    
    //-------------------------------------------------------------------------------------------------------------------------------
    void liberarMemoria() {
        for (int i = 0; i < filas; i++) {
            delete[] tablero[i];
        }
        delete[] tablero;
    }
};
