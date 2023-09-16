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
    vector<pair<int,int> >casillasInactivas;
public:
    Tablero(int filas, int columnas) : filas(20), columnas(20) {
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
    void guardarIgresoTesoro(int fila, int columna, int jugador){
        if(jugador == 1 && tesorosJugador1.size() < 5){
            tesorosJugador1.push_back(make_pair(fila,columna));
        }
        else if(jugador == 2 && tesorosJugador2.size() < 5){
            tesorosJugador2.push_back(make_pair(fila,columna));
        }
        tablero[fila][columna] = '$';
    }//--------------------------------------------------------------------------------------------------------------------
    void guardarIngresoEspia(int fila, int columna, int jugador){
        if(jugador == 1){
            espiasJugador1.push_back(make_pair(fila,columna));
        }
        else if(jugador == 2){
            espiasJugador2.push_back(make_pair(fila,columna));
        }
        tablero[fila][columna] = 'E';
    }//-------------------------------------------------------------------------------------------------------------------------
    bool tesoroRepetido(int fila, int columna){
        bool valido = false;
        if(tablero[fila][columna] == '$'){
            valido =  true;
        }
        return valido;
    }//-----------------------------------------------------------------------------------------------------------------------------
    //INTERACCION EN EL TABLERO POR EL JUGADOR
    bool recuperarTesoroPrimerJugador(){
        //regresa true si hay un tesoro en la casilla donde se pone el espia
        bool valido = false;
        for(int i = 0; i < espiasJugador1.size(); i++){
            for(int j = 0; j < tesorosJugador1.size(); j++){
                if(espiasJugador1[i] == tesorosJugador1[j]){
                    casillasInactivas.push_back(espiasJugador1[i]);
                    valido = true;
                }
            }
        }
        return valido;
    }//-----------------------------------------------------------------------------------------------------------------------------
    bool recuperarTesoroSegunoJugador(){
        //regresa true si hay un tesoro en la casilla donde se pone el espia
        bool valido = false;
        for(int i = 0; i < espiasJugador2.size(); i++){
            for(int j = 0; j < tesorosJugador2.size(); j++){
                if(espiasJugador2[i] == tesorosJugador2[j]){
                    casillasInactivas.push_back(espiasJugador2[i]);
                    valido = true;
                }
            }
        }
        return valido;
    }//-------------------------------------------------------------------------------------------------------------------------------
    bool compararTesoros(){
        for(int par = 0; par < tesorosJugador1.size(); par++){
            for(int parAux = 0; parAux < tesorosJugador2.size(); parAux++){
                if(tesorosJugador1[par] == tesorosJugador2[parAux]){
                    return true;
                }
            }
        }
        return false;
    }//-------------------------------------------------------------------------------------------------------------------------------
    bool espiaEnSegundoJugador(){
        //funcion elimina el tesoro del segundo jugador cuando el primero ingresa un espia
        for(int i = 0; i < espiasJugador1.size(); i++){
            for(int j = 0; j < tesorosJugador2.size(); j++){
                if(espiasJugador1[i] == tesorosJugador2[j]){
                    tesorosJugador2.erase(espiasJugador2.begin() + j);
                    return true;
                }
            }
            return false;
        }
    }
    bool espiaEnPrimerJugador(){
        //se eliminan los tesoros del primer jugador cuando el espia ingresa a la casilla
        for(int i = 0; i < espiasJugador2.size(); i++){
            for(int j = 0; j < tesorosJugador1.size(); j++){
                if(espiasJugador2[i] == tesorosJugador1[j]){
                    tesorosJugador1.erase(tesorosJugador1.begin() + j);
                    return true;
                }
            }
        }
        return false;
    }
    //compara y elimina espias
    bool eliminarEspias(){ //hay que eliminar los espias del tablero y tambien del vector que los almacena
        for(int i = 0; i < espiasJugador1.size(); i++){
            for(int j = 0; j < espiasJugador2.size(); j++){
                if(espiasJugador1[i] == espiasJugador2[j]){
                    espiasJugador1.erase(espiasJugador1.begin() + i);
                    espiasJugador2.erase(espiasJugador2.begin() + j); 
                    return true; 
                }
            }
        }
        return false;
    }
    void resetearCasilla(int fila, int columna){
        tablero[fila][columna] = '#';
    }
    bool casillaInvalida(int fila, int columna){
        bool valido = false;
        for(int i = 0; i < casillasInactivas.size(); i++){
            int auxFila = casillasInactivas[i].first;
            int auxCol = casillasInactivas[i].second;
            if(fila == auxFila && columna == auxCol){
                valido = true;
            }
        }
        return valido;
    }
    bool espiaRepetido(int fila, int columna){
        bool valido = false;
        for(int i = 0; i < espiasJugador1.size(); i++){
            int auxFila = espiasJugador1[i].first;
            int auxCol = espiasJugador1[i].second;
            if(fila == auxFila && columna == auxCol){
                valido = true;
            }
        }
        return valido;
    }
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
    }//-------------------------------------------------------------------------------------------------------------------------------
    char obtenerValorCelda(int fila, int columna) const{
        if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas){
        return tablero[fila][columna];
        }
    }
    void liberarMemoria() {
        for (int i = 0; i < filas; i++) {
            delete[] tablero[i];
        }
        delete[] tablero;
    }
};
