#include "lista.h"
#include <iostream>
using namespace std;

Lista::Lista(){}

//NI IDEA PERO HAY QUE VER QUE HACE
void Lista::altaFinal(int numero){
    Nodo *auxPuntero = punteroNodo;
    //MIENTRAS EL NODO SEA SIFERENTE DE NULL AND:
    //MIENTRAS EL PROXIMO NODO SEA DIFERENTE DE NULL
    while((auxPuntero) && (auxPuntero -> getSigNodo())){
        auxPuntero = auxPuntero -> getSigNodo();
        if(auxPuntero){
            auxPuntero -> setSigNodo(new Nodo(numero,0));
        }
        else{
            punteroNodo = new Nodo(numero, punteroNodo);
        }

    }
}
//NI IDEA PERO VAMOS A VER QUE PEDO
void Lista::altaPrincipio(int numero){
    punteroNodo = new Nodo(numero, punteroNodo);
}
//FUNCION PARA REVISAR SI UN DATO ESTA EN LA LISTA
bool Lista::enLista(int elemento){
    bool encontrado = false;
    Nodo *pAux = punteroNodo;
    //MIENTRAS EL PUNTERO NO SEA NULO
    while(pAux){
        //REVISA EL VALOR PARA CADA NODO
        if(pAux -> getInfo() == elemento){
            //SI EL VALOR COINCIDE CON EL VALOR DE UN NODO, REGRESA TRUE
            encontrado = true;
        }
    }
    return encontrado;
}
//ELIMINA LA PRIMERA APARICION DEL ELEMENTO EN LA LISTA
void Lista::bajaLista(int numero){
    if(punteroNodo){
        //SE REVISA SI EL PUNTERO ES DIFERENTE DEL NUMERO Y QUE HAYA SIGUIENTE PUNTERO
        if((punteroNodo -> getInfo() != numero) && (punteroNodo -> getSigNodo())){
            //SE CREAN DOS NODOS AUXILIARES 
            Nodo *pAux = punteroNodo, *pAux2 = punteroNodo -> getSigNodo();
            //NODO 1: SE IGUALA AL PUNTERO ACTUAL
            //NODO 2: SE IGUALA AL SIGUIENTE NODO
            while((pAux2 -> getInfo() != numero) && pAux2 -> getSigNodo() != NULL){
                pAux = pAux2;
                pAux2 = pAux2 -> getSigNodo();
            }
            if(pAux2 -> getInfo() == numero){
                pAux -> setSigNodo(pAux2 -> getSigNodo());
                delete pAux2;
                
            }
        }    
        else if(punteroNodo -> getInfo() == numero){
            Nodo *punteroAux = punteroNodo;
            punteroNodo = punteroNodo -> getSigNodo();
            delete punteroAux;
        }
    }
}
//MUESTRA TODOS LOS ELEMENTOS DE LA LISTA
void Lista::emiteLista(){
    Nodo *punteroAux = punteroNodo;
    while(punteroAux){
        cout << punteroAux -> getInfo() << endl;
        punteroAux = punteroAux -> getSigNodo();
    }
}
//EL DESTRUCTOR DE LA LISTA
Lista::~Lista(){
    if(punteroNodo){
        Nodo *puntero = punteroNodo;
        while(puntero){
            punteroNodo = punteroNodo -> getSigNodo();
        }
    }
}