#include <iostream>
#include <cstdlib>
#include "vald_intr.h"
#include "tablero.h"

using namespace std;

class Player {
private:
    string userName;
    int tesorosTotales;
    int tesorosRecuperados;
    int tesorosEnJuego;
    int cantidadEspias;
    bool penalidadFlag;

public:
    int ordenJuego;
    Player(string usuario = "jugador", int tesorosIniciales = 4, int espiasIniciales = 0, bool castigo = false, int ordenJuego = 0, int tesorosAlmacenados = 0, int tesorosTablelro = 4)
        : userName(usuario), tesorosTotales(tesorosIniciales),tesorosRecuperados(tesorosAlmacenados), cantidadEspias(espiasIniciales), penalidadFlag(castigo), ordenJuego(0), tesorosEnJuego(tesorosTablelro) {}

    void pedirCoordenadas(int &fila, int &columna) {
        cout << "Ingrese la fila deseada: " << endl;
        cin >> fila;
        cout << "Ingrese la columna deseada: " << endl;
        cin >> columna;
    }
    char pedirIngreso() {
        char ingreso;
        if(tesorosRecuperados >=0 ){
            cout << "Actualmente tiene todos los tesoros en el tablero." << '\n';
            cout << "Seleccione donde quiere ingresar su espia." << endl;
            ingreso = 'E';
        }
        else{
            cout << "Ingrese $ para tesoro o E para espía: " << std::endl;
            cin >> ingreso;
        }
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
    void reducirTesoros(){
        if(tesorosTotales > 0){
            tesorosTotales--;
            tesorosRecuperados++;
            cout << "Has recuperado un tesoro. Tesoros totales restantes: " << tesorosTotales << endl;
        } 
        else {
            cout << "Ya no quedan tesoros por recuperar." << endl;
        }
}
};
