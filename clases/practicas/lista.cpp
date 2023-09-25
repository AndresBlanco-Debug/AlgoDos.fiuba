#include "lista.h"
#include <iostream>
#include <string>
using namespace std;

//METODOS DE CLASE LISTA PENSADO PARA UNA LISTA ESTATICA

listaEnteros::listaEnteros(){}
listaEnteros::~listaEnteros(){}
//SE TERMINAN LAS DECLARACIONES DE LOS CONSTRUCTORES
bool listaEnteros::listaLlena(){
    bool llena = false;
    if(topeLista == MAX_TAMANO){
        llena = true;
    }
    return llena;
}
void listaEnteros::ingresarDato(int numero){
    if(isdigit(numero)){
        //revisa si el ingreso es un numero
        if(!listaLlena()){
            //se revisa que la lista no este llena
            vectorLista[topeLista] = numero;
            topeLista++;
        }
        else{
            cout << "Error! la lista ya esta llena" << endl;
        }
    }
    else{
        cout << "Error! el ingreso no es un numero" << endl;
    }
}
//METODO PARA BORRAR UN ELEMENTO EN CUALQUIER POSICION
void