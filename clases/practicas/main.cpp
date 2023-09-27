#include <iostream>
#include "lista.h"
using namespace std;

/*int submain(){
    
    listaEnteros lEnt;
    lEnt.ingresarDato(1);
    lEnt.ingresarDato(13);
    lEnt.ingresarDato(1000);
    lEnt.ingresarDato(195);
    lEnt.ingresarDato(18);
    lEnt.ingresarDato(17);
    lEnt.ingresarDato(88);
    

    cout << "SE RECORRE LA LISTA INICIAL" << endl;
    for(int i = 1; i <= lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    //INTENTO DE ELIMINAR UN DATO
    cout << "\nSE RECORRE LA LISTA Y SE ELIMINA SEGUN LA POSICION: (SE ELIMINA LA POSICION 3)" << endl;
    lEnt.borrar_X_Pos(3);
    for(int i = 1; i <= lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    //
    cout << "\nSE ELIMINA EL PRIMER DATO QUE COINCIDE: (DATO = 18)" << endl;
    lEnt.eliminarDato(18);
    for(int i = 1; i <= lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    cout <<"\nSE ELIMINA EL PRIMER DATO DE LA LISTA: (PRIMER DATO = 1)" << endl;
    lEnt.borrarPrimerDato();
    for(int i = 1; i <= lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    cout <<"\nSE ELIMINA EL ULTIMO ELEMENTO DE LA LISTA (ULTIMO DATO = 88)" << endl;
    lEnt.borrarUltimoDato();
    for(int i = 1; i <= lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    } 
    cout << "\nSE INGRESAN N CANTIDAD DE DATOS PARA PROBAR LA FUNCION" << endl;
    lEnt.ingresarDato(77);
    lEnt.ingresarDato(4);
    lEnt.ingresarDato(20);
    lEnt.ingresarDato(25);
    lEnt.ingresarDato(77);
    lEnt.ingresarDato(22);
    lEnt.ingresarDato(77);
    cout << "\nFUNCION PARA ELIMINAR TODOS LOS ELEMENTOS IGUALES DE LA LISTA" << endl;
    cout << "\nELEMETOS ANTES DE ELIMINAR" << endl;
    for(int i = 1; i <= lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    cout << "\nELEMENTOS DESPUES DE ELIMINAR: (ELEMENTO A ELIMINAR = 77)" << endl;
    lEnt.eliminarDatoTotal(77);
    for(int i = 1; i <= lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    } 

    return 0;
}*/

int main(){

    lista *vector = new lista();
    int *punteroNumero;
    int numero = 25;
    punteroNumero = &numero;
    vector -> ingresarDato(punteroNumero);
    vector -> mostrarElementos();

    return 0;
}