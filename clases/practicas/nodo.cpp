#include <iostream>
#include "nodo.h"

//SE INICIALIZAN LOS PUNTEROS EN NULL
Nodo::Nodo(int valor, Nodo *primerNodo){
    info = valor;
    siguiente = primerNodo;
}
int Nodo::getInfo(){
    return info;
}
Nodo *Nodo::getSigNodo(){
    return siguiente;
}
void Nodo::setInfo(int elemento){
    info = elemento;
}
void Nodo::setSigNodo(Nodo *proxNodo){
    siguiente = proxNodo;
}
