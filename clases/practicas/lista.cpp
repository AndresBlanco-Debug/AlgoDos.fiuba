#include "lista.h"
#include <iostream>
using namespace std;

Lista::Lista():punteroLista(0){}
//
void Lista::altaFinal(int elemento){
    //Se crea un nodo auxiliar para acceder al nodo original
    Nodo *puntAux = punteroLista;
    //se hace un while hasta que se llega al ultimo elemento
    while((puntAux) && (puntAux -> getSigNodo())){
        puntAux = puntAux -> getSigNodo();
    }
    if(puntAux){
        //Se evalua si el puntero es nulo, en caso de no serlo
        //se usa la funcion para asignarle el ultimo nodo de la lista, por eso el "0"
        puntAux -> setSigNodo(new Nodo(elemento,0));
    }
    else{
        punteroLista = new Nodo(elemento, punteroLista);
    }
}
//
void Lista::altaPrincipio(int elemento){
    punteroLista = new Nodo(elemento, punteroLista);
}
//FUNCION ORIGINAL.
void Lista::altaXPosicion(int elemento, int posicion){
    Nodo *punteroAux = punteroLista;
    int contador = 0;
    //CASo 1: LA LISTA TIENE ELEMENTOS
    //Este ciclo pide que el puntero exista, recorre todos los nodos hasta llegar a la posicion
    while((punteroAux) && (punteroAux -> getSigNodo()) && (contador < (posicion - 1))){
        punteroAux = punteroAux -> getSigNodo();
        contador++;
    }
    if(punteroAux){
        Nodo *nuevoNodo = new Nodo(elemento, punteroAux -> getSigNodo());
        punteroAux -> setSigNodo(nuevoNodo);
    }
    //CASO QUE LA LISTA ESTE VACIA
    else{
        punteroLista = new Nodo(elemento, punteroLista);
    }
}
//
void Lista::bajaLista(int elemento){
    if(punteroLista){
        if((punteroLista->getInfo() != elemento) && (punteroLista -> getSigNodo())){
            Nodo *puntAux1 = punteroLista, *puntAux2 = punteroLista -> getSigNodo();
            while((puntAux2->getInfo() != elemento) && (puntAux2 -> getSigNodo() != NULL)){
                puntAux1 = puntAux2;
                puntAux2 = puntAux2 -> getSigNodo();
            }
            if(puntAux2 -> getInfo() ==  elemento){
                puntAux1 -> setSigNodo(puntAux2 -> getSigNodo());
                delete puntAux2;
            }
        }
        else if(punteroLista -> getInfo() == elemento){
            Nodo *puntAux = punteroLista;
            punteroLista = punteroLista -> getSigNodo();
            delete puntAux;
        }
    }
}
//
bool Lista::datoEnLista(int elemento){
    Nodo *punteroAux = punteroLista;
    while(punteroAux){
        if(punteroAux -> getInfo() == elemento){
            return true;
        }else{
            punteroAux = punteroAux -> getSigNodo();
        }
    }
    return false;
}
//
void Lista::emiteLista(){
    Nodo *punteroAux = punteroLista;
    while(punteroAux){
        cout << punteroAux -> getInfo();
        punteroAux = punteroAux -> getSigNodo();
    }
}
//
Lista::~Lista(){
    //EN EL DESTRUCTOR HAY QUE RECORRER EL NODO DE LA LISTA ORIGINAL
    if(punteroLista){
        Nodo *puntAux;
        while(punteroLista){
            puntAux = punteroLista;
            punteroLista = punteroLista -> getSigNodo();
            delete puntAux;
        }
    }
}