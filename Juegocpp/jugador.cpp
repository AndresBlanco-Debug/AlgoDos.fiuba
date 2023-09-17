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
char Player::pedirIngreso() {
    char respuesta;
    cout << "Elija el ingreso: $ para tesoro, E para espia: " << endl;
    cin >> respuesta;
    return respuesta;
}