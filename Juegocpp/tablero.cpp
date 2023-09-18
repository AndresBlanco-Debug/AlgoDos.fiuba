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
    casillaInactiva = 5;
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
void Tablero::reducirPenalidad() {
    casillaInactiva--;
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
        imprimirTablero();
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
    }
    return ingresoVal;
}
bool Tablero::espiaInfiltradoP1(int fila, int columna) {
    bool infiltracion = true;
    int len = getLongEspiasP1();
    pair<int, int> coordenadas(fila,columna);
    if(getCasillaActual(fila,columna) == 'E'){
        for(int i = 0; i < len; i++){
            if(coordenadas == espiasPrimerJugador[i]){
                infiltracion = false;
            }
        }
    }
    else{
        espiasPrimerJugador.push_back(coordenadas);
        cout << "Espia infiltrado exitosamente" << endl;
    }
    return infiltracion;
}
bool Tablero::espiaInfiltradoP2(int fila, int columna) {
    bool infiltracion = true;
    int len = getLongEspiasP2();
    pair<int, int> coordenadas(fila,columna);
    if(getCasillaActual(fila,columna) == 'E'){
        for(int i = 0; i < len; i++){
            if(coordenadas == espiasSegundoJugador[i]){
                infiltracion = false;
            }
        }
    }
    else{
        espiasSegundoJugador.push_back(coordenadas);
        cout << "Espia infiltrado exitosamente" << endl;
    }
    return infiltracion;
}
bool Tablero::tesoroPerdidoP1() {
    //funcion que elimina tesoros del primer jugador al encontrar un espia
    int lenTesorosP1 = getLongJugador1();
    int lenEspiasP2 = getLongEspiasP2();
    for(int i = 0; i < lenTesorosP1; i++){
        for(int j = 0; j < lenEspiasP2; j++){
            if(tesorosPrimerJugador[i] == espiasSegundoJugador[j]){
                tesorosPrimerJugador.erase(tesorosPrimerJugador.begin() + i);
                return true;
            }
        }
    }
    return false;
}
bool Tablero::tesoroPerdidoP2() {
    //elimina tesoros del segundo jugador al encontrar un espia rival
    int lenTesorosP2 = getLongJugador2();
    int lenEspiasP1 = getLongEspiasP1();
    for(int i = 0; i < lenTesorosP2; i++){
        for(int j = 0; j < lenEspiasP1; j++){
            if(tesorosSegundoJugador[i] == espiasPrimerJugador[j]){
                tesorosSegundoJugador.erase(tesorosSegundoJugador.begin() + i);
                return true;
            }
        }
    }
    return false;
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
void Tablero::restringirCasilla(int fila, int columna) {
    //funcion agrega la casilla restringida, nada mas.
    int len = getLenInvalidCoord();
    int cont = 0; //contador usado mas adelante
    pair<int, int> coordenadas(fila,columna);
    for(int i = 0; i < len; i++){
        if(coordenadas != casillaInvalida[i]){
            cont++;
        }
    }
    if(cont == len){
        casillaInvalida.push_back(coordenadas);
    }
}
bool Tablero::tesoroRecuperadoP1() {
    int lenTesoros = getLongJugador1();
    int lenEspias = getLongEspiasP1();
    for(int i = 0; i < lenTesoros; i++){
        for(int j = 0; j < lenEspias; j++){
            if(tesorosPrimerJugador[i] == espiasPrimerJugador[j]){
                tesorosPrimerJugador.erase(tesorosPrimerJugador.begin() + i);
                return true;
            }
        }
    }
    return false;
}
bool Tablero::tesoroRecuperadoP2() {
    int lenTesoros = getLongJugador2();
    int lenEspias = getLongEspiasP2();
    for(int i = 0; i < lenTesoros; i++){
        for(int j = 0; j < lenEspias; j++){
            if(tesorosSegundoJugador[i] == espiasSegundoJugador[j]){
                tesorosSegundoJugador.erase(tesorosSegundoJugador.begin() + i);
                return true;
            }
        }
    }
    return false;
}
bool Tablero::invalidarCasilla(int fila, int columna) {
    bool invalido = false;
    int len = getLenInvalidCoord();
    pair<int, int> coordenadas(fila,columna);
    for(int i = 0; i < len; i++){
        if(coordenadas == casillaInvalida[i] && (casillaInactiva > 0)){
            invalido = true;

        }
    }
    return invalido;
}
void Tablero::imprimirTableroP1() {
    int lenTesP1 = getLongJugador1();
    int lenEspP1 = getLongEspiasP1();
    for(int i = 0; i < lenTesP1; i++){
        int auxFil = tesorosPrimerJugador[i].first;
        int auxCol = tesorosPrimerJugador[i].second;
        tablero[auxFil][auxCol] = '$';
    }
    for(int j = 0; j < lenEspP1; j++){
        int betaFil = espiasPrimerJugador[j].first;
        int betaCol = espiasPrimerJugador[j].second;
        tablero[betaFil][betaCol] = 'E';
    }
}
void Tablero::imprimirTableroP2() {
    int lenTesP1 = getLongJugador2();
    int lenEspP1 = getLongEspiasP2();
    for(int i = 0; i < lenTesP1; i++){
        int auxFil = tesorosSegundoJugador[i].first;
        int auxCol = tesorosSegundoJugador[i].second;
        tablero[auxFil][auxCol] = '$';
    }
    for(int j = 0; j < lenEspP1; j++){
        int betaFil = espiasSegundoJugador[j].first;
        int betaCol = espiasSegundoJugador[j].second;
        tablero[betaFil][betaCol] = 'E';
    }
}
