#include "lista.h"
#include <iostream>
#include <string>
using namespace std;

//METODOS DE CLASE LISTA PENSADO PARA UNA LISTA ESTATICA

listaEnteros::listaEnteros(){
    topeLista = 0;
}
listaEnteros::~listaEnteros(){}
//SE TERMINAN LAS DECLARACIONES DE LOS CONSTRUCTORES
//FUNCION PARA OBTENER LA LONGITUD ACTUALIZADA
int listaEnteros::getLongLista(){
    return topeLista;
}
//FUNCION PARA SABER SI LA LISTA ESTA LLENA
bool listaEnteros::listaLlena(){
    bool llena = false;
    if(topeLista == MAX_TAMANO){
        llena = true;
    }
    return llena;
}
//FUNCION PARA OBTENER EL VALOR EN UNA X POSICION
int listaEnteros::getValorActual(int posicion){
    return vectorLista[posicion - 1];
}
//FUNCION PARA SABER SI UN DATO ESTA EN LA LISTA
bool listaEnteros::elementoEnLista(int numero){
    bool encontrado = false;
    int indice = 0;
    while(indice < topeLista){
        if(vectorLista[indice] == numero){
            encontrado = true;
            break;
        }
        indice++;
    }
    return encontrado;
}
//FUNCION PARA AGREGAR CUALQUIER ENTERO A LA LISTA
void listaEnteros::ingresarDato(int numero){
    if(!listaLlena()){
        //Segmentation fault.
        vectorLista[topeLista] = numero;
        topeLista++;
    }
    else{
        cout << "la lista ya esta llena" << endl;
    }
}
//METODO PARA BORRAR UN ELEMENTO EN CUALQUIER POSICION
void listaEnteros::borrar_X_Pos(int posicion){
    while(posicion < topeLista){
        vectorLista[posicion] = vectorLista[posicion + 1];    
        posicion++;   
    }
    topeLista--;
}
//FUNCION PARA ELIMINAR LA PRIMERA APARICION DEL DATO INGRESADO
void listaEnteros::eliminarDato(int dato){
    //HAY QUE RECORRER LA LISTA ENTERA HASTA ENCONTRAR EL DATO
    int indice = 0;
    while(vectorLista[indice] != dato){
        indice++;
    }
    for(int i = indice; i < topeLista; i++){
        vectorLista[i] = vectorLista[i+1];
    }
    topeLista--;
}
//FUNCION QUE ELIMINA EL PRIMER DATO DE LA LISTA
void listaEnteros::borrarPrimerDato(){
    int posicion = 0;
    while(posicion < topeLista){
        vectorLista[posicion] = vectorLista[posicion+1];
        posicion++;
    }
    topeLista--;
}
void listaEnteros::borrarUltimoDato(){
    topeLista--;
}
//
void listaEnteros::eliminarDato(int dato){
    if(elementoEnLista(dato)){
        
    }
}