#include <iostream>
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
int Tablero::getLongEspiasP1() {
    return espiasPrimerJugador.size();
}
int Tablero::getLongEspiasP2() {
    return espiasSegundoJugador.size();
}
int Tablero::getLenInvalidCoord() {
    return casillaInvalida.size();
}
void Tablero::imprimirTablero(){
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){
            cout << tablero[i][j] << ' '; // Agrega esta línea para verificar el valor asignado
        }
        cout << endl;
    }
}
char Tablero::getCasillaActual(int fila, int columna) {
    return tablero[fila][columna];
}
//VALIDACIONES
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
bool Tablero::compararEspias() {
    //funcion util para ambos jugadores
    //evalua los espias guardados
    bool infiltrado = false;
    int longE1 = getLongJugador1();
    int longE2 = getLongJugador2();
    //recorre las coordenadas guardadas
    for(int i = 0; i < longE1; i++){
        for(int j = 0; j < longE2; j++){
            if(espiasPrimerJugador[i] == espiasSegundoJugador[j]){
                espiasSegundoJugador.erase(espiasPrimerJugador.begin() + i);
                espiasSegundoJugador.erase(espiasSegundoJugador.begin() + j);
                //elimina los espias con coordenadas iguales;
                infiltrado = true;
            }
        }
    }
    return infiltrado;
}
bool Tablero::guardarIngresoTesoroP1(int fila, int columna) {
    bool ingresoVal = true;
    pair<int, int> coordenadas(fila,columna);
    int len = getLongJugador1();
    if(getCasillaActual(fila,columna) == '$'){
        for(int i = 0; i < len; i++){
            if(coordenadas == tesorosPrimerJugador[i]){
                ingresoVal = false;
            }
        }
    }
    else{
        tesorosPrimerJugador.push_back(coordenadas);
        cout << "Tesoro ingresado exitosamente" << endl;
        tablero[fila][columna] = '$';
    }
    return ingresoVal;
}
bool Tablero::guardarIngresoTesoroP2(int fila, int columna) {
    bool ingresoVal = true;
    pair<int, int> coordenadas(fila,columna);
    int len = getLongJugador2();
    if(getCasillaActual(fila,columna) == '$'){
        for(int i = 0; i < len; i++){
            if(coordenadas == tesorosSegundoJugador[i]){
                ingresoVal = false;
            }
        }
    }
    else{
        tesorosSegundoJugador.push_back(coordenadas);
        cout << "Tesoro ingresado exitosamente" << endl;
        tablero[fila][columna] = '$'; //se actualiza el tablero
    }
    return ingresoVal;
}
bool Tablero::espiaInfiltradoP1(int fila, int columna) {
    bool infiltracion = false;
    //las interacciones del espia se trabajan por separado
    if(getCasillaActual(fila,columna) == 'E' && !(compararEspias())){
        //esto significa que se quiere poner un espia donde el jugador ya controla un espia
        cout << "Error! el jugador ya posee un espia infiltado en la casilla" << '\n';
        cout << "intente nuevamente" << endl;
    }
    else{
        pair<int, int> coordenadas(fila,columna);
        espiasPrimerJugador.push_back(coordenadas);
        cout << "Espia infiltrado exitosamente" << endl;
        infiltracion = true;

    }
    return infiltracion;
}
bool Tablero::espiaInfiltradoP2(int fila, int columna) {
    bool infiltracion = false;
    //las interacciones del espia se trabajan por separado
    if(getCasillaActual(fila,columna) == 'E' && !(compararEspias())){
        //esto significa que se quiere poner un espia donde el jugador ya controla un espia
        cout << "Error! el jugador ya posee un espia infiltado en la casilla" << '\n';
        cout << "intente nuevamente" << endl;
    }
    else{
        pair<int, int> coordenadas(fila,columna);
        espiasSegundoJugador.push_back(coordenadas);
        cout << "Espia infiltrado exitosamente" << endl;
        infiltracion = true;
    }
    return infiltracion;
}
bool Tablero::espiaSobreTesosoP1() {
    int lenTes = getLongJugador1();
    int lenEsp = getLongEspiasP1();
    bool extraccion = false;
    for(int i = 0; i < lenTes; i++){
        for(int j = 0; j < lenEsp; j++){
            if(tesorosPrimerJugador[i] == espiasPrimerJugador[j]){
                extraccion = true;
            }
        }
    }
    return extraccion;
}
bool Tablero::espiaSobreTesosoP2() {
    int lenTes = getLongJugador2();
    int lenEsp = getLongEspiasP2();
    bool extraccion = false;
    for(int i = 0; i < lenTes; i++){
        for(int j = 0; j < lenEsp; j++){
            if(tesorosSegundoJugador[i] == espiasSegundoJugador[j]){
                extraccion = true;
            }
        }
    }
    return extraccion;
}
bool Tablero::moverTesoroP1(int fila, int columna) {
    bool valido = false;
    int len = getLongJugador1();
    pair<int, int> coordenadas(fila,columna);
    for(int i = 0; i < len; i++){
        if(coordenadas == tesorosPrimerJugador[i]){
            cout << "Error el jugador ya tiene un teesoro en esa casilla" << endl;
            valido = true;
        }
    }
    return valido;
}
bool Tablero::moverTesoroP2(int fila, int columna) {
    bool valido = false;
    int len = getLongJugador1();
    pair<int, int> coordenadas(fila,columna);
    for(int i = 0; i < len; i++){
        if(coordenadas == tesorosSegundoJugador[i]){
            cout << "Error el jugador ya tiene un teesoro en esa casilla" << endl;
            valido = true;
        }
    }
    return valido;
}
bool Tablero::casillaRestringida(int fila, int columna) {
    bool penalidad = false;
    if(moverTesoroP1(fila,columna) || moverTesoroP2(fila,columna)){
        pair<int, int> coordenadas(fila,columna);
        casillaInvalida.push_back(coordenadas);
        penalidad = true;
    }
    return penalidad;
}
bool Tablero::invalidarCasilla(int fila, int columna) {
    bool invalido = false;
    int len = getLenInvalidCoord();
    pair<int, int> coordenadas(fila,columna);
    for(int i = 0; i < len; i++){
        if(coordenadas == casillaInvalida[i]){
            invalido = true;
        }
    }
    return invalido;
}

void Tablero::actualizarTablero(int fila, int columna) {
    //funcion pensada para el primer jugador
    pair<int, int> tesoros(fila,columna);
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){
            if(tesoros == tesorosSegundoJugador[i]){
                tablero[fila][columna] = '$';
            }
        }
    }
}