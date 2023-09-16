#include <iostream>
#include <cstdlib>
#include "tablero.h"

using namespace std;

class Player {
private:
    Tablero tableroJuego;
    string userName;
    int tesorosTotales;
    int tesorosRecuperados;
    int tesorosEnJuego;
    int tesorosCapturados;
    int cantidadEspias;
    bool penalidadFlag;

public:
    Player(string usuario = "jugador", int tesorosIniciales = 4, int espiasIniciales = 0, bool castigo = false, int ordenJuego = 0, int tesorosAlmacenados = 0, int tesorosTablelro = 4, int tesorosNoJugables = 0)
        : userName(usuario), tesorosTotales(tesorosIniciales), tesorosRecuperados(tesorosAlmacenados), cantidadEspias(espiasIniciales), penalidadFlag(castigo), tesorosEnJuego(tesorosTablelro), tesorosCapturados(tesorosNoJugables), tableroJuego() {}

    void pedirCoordenadas(int &fila, int &columna) {
        cout << "Ingrese la fila deseada: " << endl;
        cin >> fila;
        cout << "Ingrese la columna deseada: " << endl;
        cin >> columna;
    }
    char pedirIngreso() {
        char ingreso;
        cout << "Para ingresar un tesoro elija '$', para ingresar un espia elija 'E'" << endl;
        cin >> ingreso;
        return ingreso;
    }
    bool validarIngresoTesoro(){
        if(tesorosEnJuego < tesorosTotales){
            return true;
        }else{
            cout << "Todos los tesoros disponibles estan en juego" << endl;
            return false;
        }
    }
    char val(){
        int respuesta;
        cout << "Si desea mover un tesoro ingrese 1 de lo contrario ingrese 0" << endl;
        cin >> respuesta;
        return respuesta;
    }
    bool moverTesoro(){
        if(tesorosEnJuego < tesorosCapturados){
            return true;
        }
        return false;
    }
    void reducirTesoros(){
        if(tesorosTotales > 0){
            tesorosTotales--;
            tesorosEnJuego--;
        }
    }
    void espiaInfiltrado(){
        if(tesorosTotales > 0){
            cantidadEspias++;
            tesorosCapturados++;
        }
    }
    void espiaCaido(){
        if(cantidadEspias > 0){
            cantidadEspias--;
        }
    }
    int getEspias(){
        return cantidadEspias;
    }
    void tesoroCapturado(){
        tesorosCapturados++;
    }
    void aumentarEspias(){
        cantidadEspias++;
    }
    int getTesorosTotales(){
        return tesorosTotales;
    }
    void mostrarTableroJugador(const Tablero& tablero){
        cout << "tablero actual" << endl;
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 20; j++){
                char valor = tablero.obtenerValorCelda(i,j);
            }
            cout << endl;
        }
    }
};
