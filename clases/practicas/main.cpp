#include <iostream>
#include "lista.h"
using namespace std;

int ingreso(){
    int respuesta;
    cout << "Opciones:" << '\n';
    cout << "Seleccione '1' para ingresar un numero al final" << '\n';
    cout << "Seleccione '2' para ingresar un numero al principio" << '\n';
    cout << "Seleccione '3' para ingresar un dato en cualquier posicion" << '\n';
    cout << "Seleccione '4' para eliminar el numero ingresado" << '\n';
    cout << "Seleccione '5' para saber si un numero esta en la lista" << '\n';
    cout << "Seleccione '6' para mostrar los elementos de la lista" << '\n';
    cout << "Seleccione '7' para eliminar el primer numero de la lista" << '\n';
    cout << "Seleccione '8' para eliminar el ultimo numero de la lista" << '\n';
    cout << "Seleccione '9' para eliminar un numero en cualquier posicion" << '\n';    
    cout << "Seleccione '10' para eliminar todas las apariciones de un numero" << '\n';
    cout << "Seleccione '11' para mostrar el primer numero de la lista" << '\n';
    cout << "Seleccione '12' para mostrar el ultimo numero de la lista" << '\n';
    cout << "Seleccione '13' para mostrar el numero en la posicion deseada" << '\n';
    cout << "Seleccione '0' para cerrar el programa" << '\n';
    cout << endl;
    if(cin >> respuesta){
        return respuesta;
    }
    else{
        cout << "Error! ingreso no valido" << endl;
        return 0;
    }
}

int getNumero(){
    int numero;
    cout << "Ingrese el numero/posicion: " <<'\n';
    if(cin >> numero){
        return numero;
    }
    cout << "Error! ingreso no valido" << endl;
    return 0;    
}

void menu(){
    Lista lista;
    cout << "Bienvenido al menu! aca las opciones" << '\n';
    int operacion = ingreso();
    do
    {
        switch (operacion)
        {
        case 0:
            break;
        case 1:
            {
            int numero = getNumero();
            lista.altaFinal(numero);
            }
            break;
        case 2:{
            int numero = getNumero();
            lista.altaPrincipio(numero);
            }
            break;
        case 3:{
            int numero = getNumero(), posicion = getNumero();
            lista.altaXPosicion(numero, posicion);
            }
            break;
        case 4:{
            int numero = getNumero();
            lista.bajaLista(numero);
            }
            break;
        case 5:{
            int numero = getNumero();
            lista.datoEnLista(numero);
            }
            break;
        case 6:
            lista.emiteLista();
            break;
        case 7:
            lista.bajaPricipio();
            break;
        case 8:
            lista.bajaFinal();
            break;
        case 9:{
            int posicion = getNumero();
            lista.bajaXPosicion(posicion);
            }
            break;
        case 10:{
            int numero = getNumero();
            lista.eliminarDato(numero);
            }
            break;
        case 11:
            lista.mostrarPrimerElemento();
            break;
        case 12:
            lista.mostrarUltimoElemento();
            break;
        case 13:{
            int posicion = getNumero();
            lista.mostrarXElemento(posicion);
            }
            break;
        default:
            cout << "Error! ingreso no valido" << endl;
            break;
        }
    } 
    while (operacion != 0);
}

int main(){

    menu();
    
    return 0;
}