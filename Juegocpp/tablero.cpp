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
    }
    void generarTablero() {
        char casillaCarac = '#';
        for (int fila = 0; fila < filas; fila++) {
            for (int columna = 0; columna < columnas; columna++) {
                tablero[fila][columna] = casillaCarac;
            }
        }
    }
    //funcion para mostrar el tablero general
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
    }
    void guardarIgresoTesoro(int fila, int columna, int jugador){
        if(jugador == 1){
            tesorosJugador1.push_back(make_pair(fila, columna));
        }
        else if(jugador == 2){
            tesorosJugador2.push_back(make_pair(fila,columna));
        }
        tablero[fila][columna] = '$';
    }
    void guardarIngresoEspia(int fila, int columna, int jugador){
        if(jugador == 1){
            espiasJugador1.push_back(make_pair(fila, columna));
        }
        else if(jugador == 2){
            espiasJugador2.push_back(make_pair(fila,columna));
        }
        tablero[fila][columna] = 'E';
    }
    bool ingresoRepetido(int fila, int columna, char caracter){
        bool valido = false;
        if(caracter == '$'){
            if(tablero[fila][columna] == caracter){
                cout << "Error! No se permiten 2 tesoros por casilla" << endl;
                valido = true;
            }
        }
        return valido;
    }
    bool casillaValida(int fila, int columna, char caracter, bool penalidad){
        if(!penalidad){
            if(tablero[fila][columna] != '#'){
                return true;
        }else{
            return false;
            }
        }
    }
    void mostrarTableroJugador(int jugador, const char* nombreArchivo){
        ofstream file(nombreArchivo);
        if(!file){
            cerr << "Error al generar el archivo! contacte con el programador inmediatamente";
            return;
        }
        else{
            
        }
    }
    void liberarMemoria() {
        for (int i = 0; i < filas; i++) {
            delete[] tablero[i];
        }
        delete[] tablero;
    }
};
