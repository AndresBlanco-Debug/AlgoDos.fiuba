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
        case 1:
            int numero = getNumero();
            lista.altaFinal(numero);
            break;
        case 2:
            int numero = getNumero();
            lista.altaPrincipio(numero);

        default:
            break;
        }
    } 
    while ((operacion != 0) && (operacion < 14));
    
    
}

int main(){

    Lista lista;
    cout << "\nalta al final de 1\n";
    lista.altaFinal(1);
    lista.emiteLista();

    cout << "\nalta al final de 2\n";
    lista.altaFinal(2);
    lista.emiteLista();

    cout << "\nalta al final de 3\n";
    lista.altaFinal(3);
    lista.emiteLista();

    cout << "\nalta al final de 4\n";
    lista.altaFinal(4);
    lista.emiteLista();

    cout << "\nalta al principio de 5\n";
    lista.altaPrincipio(5);
    lista.emiteLista();

    cout << "\nbaja 4\n";
    lista.bajaLista(4);
    lista.emiteLista();

    cout << "\nbaja 1\n";
    lista.bajaLista(1);
    lista.emiteLista();

    cout <<"\nElemento en cualquier posicion, numero 8, posicion 2\n";
    lista.altaXPosicion(8,2);
    lista.emiteLista();

    cout << "\nBaja en ultima posicion\n";
    lista.bajaFinal();
    lista.emiteLista();

    cout <<"\nPrueba de funcion que elimina todas las apariciones de un dato\n";
    lista.altaFinal(17);
    lista.altaFinal(5);
    lista.altaFinal(99);
    lista.altaFinal(17);
    lista.altaFinal(17);
    lista.altaFinal(23);
    lista.altaFinal(85);
    lista.altaFinal(17);
    cout <<"\nEmitimos la lista\n";
    lista.emiteLista();
    cout <<"\nUsamos la funcion\n";
    lista.eliminarDato(17);
    cout <<"\nEmitimos la lista\n";
    lista.emiteLista();

    cout << "\nProbamos la funcion para obtener el primer valor de la lista\n";
    lista.mostrarPrimerElemento();

    cout << "\nProbamos la funcion para obtener el ultimo valor de la lista\n";
    lista.mostrarUltimoElemento();

    cout << "\nProbamos la funcion para obtener cualquier valor de la lista\n";
    cout <<"\nHacemos 2 casos de prueba diferentes\n";
    lista.mostrarXElemento(2);
    cout <<'\n';
    lista.mostrarXElemento(3);

    cout << endl;
    
    return 0;
}