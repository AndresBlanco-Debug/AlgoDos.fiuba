#include <iostream>
#include "lista.h"
using namespace std;

int main(){
    
    listaEnteros lEnt;
    lEnt.ingresarDato(1);
    lEnt.ingresarDato(13);
    lEnt.ingresarDato(1000);
    lEnt.ingresarDato(195);
    lEnt.ingresarDato(18);
    lEnt.ingresarDato(17);
    lEnt.ingresarDato(88);
    

    cout << "SE RECORRE LA LISTA" << endl;
    for(int i = 1; i < lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    //INTENTO DE ELIMINAR UN DATO
    cout << "SE RECORRE LA LISTA Y SE ELIMINA SEGUN LA POSICION" << endl;
    lEnt.borrar_X_Pos(3);
    for(int i = 1; i < lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    //
    cout << "SE ELIMINA EL PRIMER DATO QUE COINCIDE" << endl;
    lEnt.eliminarDato(18);
    for(int i = 1; i < lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    cout <<"SE ELIMINA EL PRIMER DATO DE LA LISTA" << endl;
    lEnt.borrarPrimerDato();
    for(int i = 1; i < lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    cout <<"SE ELIMINA EL ULTIMO ELEMENTO DE LA LISTA" << endl;
    for(int i = 1; i < lEnt.getLongLista(); i++){
        cout << "#-" << i << "-valor: " << lEnt.getValorActual(i) << endl;
    }
    cout << "" << endl; 

    return 0;
}