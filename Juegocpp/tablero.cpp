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
    bool tesoroRepetido(int fila, int columna, char caracter){
        bool valido = false;
        if(tablero[fila][columna] == '$'){
            valido =  true;
        }
        return valido;
    }//-----------------------------------------------------------------------------------------------------------------------------
    //INTERACCION EN EL TABLERO POR EL JUGADOR
    void moverTesoroPrimerJugador(int fila, int columna, int nuevaFila, int nuevaColumna){ //La fila y columna ya se tienen porque se pidieron.
        char tesoro = '$';
        for(int i = 0; i < tesorosJugador1.size(); i++){
            int filaAlmacenada = tesorosJugador1[i].first;
            int columnaAlmacenada = tesorosJugador1[i].second;
            if(fila == filaAlmacenada && columna == columnaAlmacenada){
                guardarIgresoTesoro(nuevaFila,nuevaColumna,1);
                tablero[fila][columna] = '#';
                break;
            }
        }
    }//-------------------------------------------------------------------------------------------------------------------------------
    void moverTesoroSegundoJugador(int fila, int columna, int nuevaFila, int nuevaColumna){ //La fila y columna ya se tienen porque se pidieron.
        char tesoro = '$';
        for(int i = 0; i < tesorosJugador2.size(); i++){
            int filaAlmacenada = tesorosJugador2[i].first;
            int columnaAlmacenada = tesorosJugador2[i].second;
            if(fila == filaAlmacenada && columna == columnaAlmacenada){
                guardarIgresoTesoro(nuevaFila,nuevaColumna,2);
                tablero[fila][columna] = '#';
                break;
            }
        }
    }//-----------------------------------------------------------------------------------------------------------------------------
    bool recuperarTesoroPrimerJugador(int fila, int columna){ //PASA POR UNA VALIDACION EXTERNA A LA FUNCION
    //importante, para que se cumpla esta validacion se tiene que haber ingresado exitosamente antes al espia, de lo contrario es siempre falsa;
        bool valido = false;
        int longitud = tesorosJugador1.size();
        for(int i = 0; i < longitud; i++){
            int vectorFila = tesorosJugador1[i].first;
            int vectorColumna = tesorosJugador1[i].second;
            if(fila == vectorFila && columna == vectorColumna){
                tesorosJugador1.erase(espiasJugador1.begin() + i);
                tablero[fila][columna] = '#';
                valido = true;
            }
        }return valido;        
    }//-----------------------------------------------------------------------------------------------------------------------------
    bool recuperarTesoroSegundoJugador(int fila, int columna){ //PASA POR UNA VALIDACION EXTERNA A LA FUNCION
        bool valido = false;
        int longitud = tesorosJugador2.size();
        for(int i = 0; i < longitud; i++){
            int vectorFila = tesorosJugador2[i].first;
            int vectorColumna = tesorosJugador2[i].second;
            if(fila == vectorFila && columna == vectorColumna){
                tablero[fila][columna] = '#';
                tesorosJugador2.erase(espiasJugador2.begin() + i);
                valido = true;
            }
        }return valido;        
    }//-------------------------------------------------------------------------------------------------------------------------------
    bool compararTesoros(int fila, int columna, int caso){
        bool tesoro = false;
        if(caso == 1){ //jugador 1 revisando en jugador 2.
            for(int parOrdenado = 0; parOrdenado < tesorosJugador2.size();parOrdenado++){
                int filaGuardada = tesorosJugador2[parOrdenado].first;
                int columnaGuardada = tesorosJugador2[parOrdenado].second;
                if(fila == filaGuardada && columna == columnaGuardada){
                    tesoro = true;
                }                
            }
        }
        else if(caso == 2){//jugador 2 revisa el jugador 1
            for(int parOrdenado = 0; parOrdenado < tesorosJugador1.size(); parOrdenado++){
                int filaGuardada = tesorosJugador1[parOrdenado].first;
                int columnaGuardada = tesorosJugador1[parOrdenado].second;
                if(fila == filaGuardada && columna == columnaGuardada){
                    tesoro = true;
                }
            }
        }
        return tesoro;
    }//-------------------------------------------------------------------------------------------------------------------------------
    bool compararEspias(int fila, int columna, int caso, int  &filaAuxiliar, int &columnaAuxiliar){ //esta fucnion puede eliminar los espias directamente.
        bool tesoro = false;
        if(caso == 1){ //jugador 1 revisando espias en jugador 2.
            for(int parOrdenado = 0; parOrdenado < espiasJugador2.size();parOrdenado++){
                int filaGuardada = espiasJugador2[parOrdenado].first;
                int columnaGuardada = espiasJugador2[parOrdenado].second;
                if(fila == filaGuardada && columna == columnaGuardada){
                    tablero[fila][columna] = '#';
                    tesoro = true;
                }                
            }
        }
        else if(caso == 2){//jugador 2 revisa espias en jugador 1.
            for(int parOrdenado = 0; parOrdenado < espiasJugador1.size(); parOrdenado++){
                int filaGuardada = espiasJugador1[parOrdenado].first;
                int columnaGuardada = espiasJugador1[parOrdenado].second;
                if(fila == filaGuardada && columna == columnaGuardada){
                    tablero[fila][columna] = '#';
                    tesoro = true;
                }
            }
        }
        return tesoro;
    }//--------------------------------------------------------------------------------------------------------------------------------
    void espiaEnSegundoJugador(){
        //funcion elimina el tesoro del segundo jugador cuando el primero ingresa un espia
        for(int i = 0; i < espiasJugador1.size(); i++){
            for(int j = 0; j < tesorosJugador2.size(); j++){
                if(espiasJugador1[i] == tesorosJugador2[j]){
                    tesorosJugador2.erase(espiasJugador2.begin() + j);
                }
            }//hacer que los indices decescan despues de la iteracion
        }
    }//ha funcion de abajo elimina tesoros del primer jugador
    void espiaEnPrimerJugador(){
        for(int i = 0; i < espiasJugador2.size(); i++){
            for(int j = 0; j < tesorosJugador1.size(); j++){
                if(espiasJugador2[i] == tesorosJugador1[j]){
                    tesorosJugador1.erase(tesorosJugador1.begin() + j);
                }
            }
        }
    }
    //compara y elimina espias
    void eliminarEspias(int fila, int columna, int caso){ //hay que eliminar los espias del tablero y tambien del vector que los almacena
        for(int i = 0; i < espiasJugador1.size(); i++){
            for(int j = 0; j < espiasJugador2.size(); j++){
                if(espiasJugador1[i] == espiasJugador2[j]){
                    espiasJugador1.erase(espiasJugador1.begin() + i);
                    espiasJugador2.erase(espiasJugador1.begin() + j);  
                }
            }
        }
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
    void liberarMemoria() {
        for (int i = 0; i < filas; i++) {
            delete[] tablero[i];
        }
        delete[] tablero;
    }
};
