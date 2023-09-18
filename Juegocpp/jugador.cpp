#include <iostream>
#include "jugador.h"
using namespace std;

Player::Player() {
    //tableroJugador; //hay que ver si esto se hace asi
    tesorosTotales = 4;
    tesorosEnJuego = 4;
    cantidadEspias = 0;
}

void Player::pedirCoordenadas(int &fila, int &columna) {
    cout << "Ingrese la fila deseada: " << '\n';
    cin >> fila;
    cout << "Ingrese la columna deseada: " << endl;
    cin >> columna;
}
void Player::aumentarEspias() {
    cantidadEspias++;
}
void Player::reducirTesoros() {
    //funcion para cuando un espia captura un tesoro
    tesorosEnJuego--;
    tesorosTotales--;
}
void Player::tesoroRecuperado() {
    tesorosTotales++;
}
bool Player::ingresoTesoro() {
    if(tesorosTotales > tesorosEnJuego){
        return true;
    }
    return false;
}
char Player::pedirIngreso() {
    char respuesta;
    cout << "Elija el ingreso: $ para tesoro, E para espia: " << endl;
    cin >> respuesta;
    return respuesta;
}
int Player::moverTesoro() {
    int respuesta;
    cout << "Ingrese 1 si desea mover el tesoro, otro numero si no dese hacer nada" << endl;
    cin >> respuesta;
    return respuesta;
}
int Player::getTesorosTotales() {
    return tesorosTotales;
}