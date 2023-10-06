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
//FUNCIONES ORIGINALES:::
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
void Lista::bajaPricipio() {
    //Hay que evaluar dos casos.
    //caso 1: la lista tiene elementos
    //caso 2: la lista esta vacia, entonces no hay nada que eliminar
    if(punteroLista){
        //Si hay nodos existentes entonces hay elementos en la lista
        //No hace falta recorrer toda la lista porque eliminamos el primer elemento atado al primer nodo.
        Nodo *pAux = punteroLista;
        delete(pAux);
    }
    else{
        cout << "\nActualmente no hay elementos en la lista, intente nuevamente\n" << endl;
    }
}
//
void Lista::bajaFinal() {
    //CASO 1: la lista tiene elementos
    Nodo *punteroAux = punteroLista, *punteroAnterior = punteroAux;
    while((punteroAux) && (punteroAux -> getSigNodo())){
        punteroAux = punteroAux -> getSigNodo();
    }//cuando se borra el nodo auxiliar
    if(punteroAux){
        punteroAnterior -> setSigNodo(0);
        delete punteroAux;
    }
    else{
        delete punteroLista;
        punteroLista = 0;
    }
}
//
void Lista::bajaXPosicion(int posicion) {
    Nodo *punteroAux = punteroLista, *nodoPrevio = punteroAux;
    int indice = 0;
    //Primero evaluamos el caso si esta en la primera posicion para evitar problemas.
    if(posicion > 0) {
        while ((punteroAux) && (punteroAux->getSigNodo()) && indice < (posicion - 1)) {
            //se recorre la lista hasta llegar a la posicion deseada o hasta que la lista se acabe en caso de pos > topeLista
            punteroAux = punteroAux->getSigNodo();
            indice++;
        }
        //CASO 1: es el ultimo elemento de la lista
        if ((punteroAux) && !(punteroAux->getSigNodo())) {
            bajaFinal();
        }
            //CASO 2: esta en otra posicion
        else if ((punteroAux) && (punteroAux->getSigNodo())) {
            //solo hay que actualizar el nodo anterior
            nodoPrevio->setSigNodo(punteroAux);
            delete punteroAux;
        }
    }
    else if(posicion == 0){
        bajaPricipio();
    }
    else{
        cout << "Error! No se aceptan posiciones negativas." << endl;
    }
}
//
void Lista::eliminarDato(int elemento) {
    Nodo *puntAux = punteroLista, *nodoAnterior;
    //primero hay que comprobar que el dato esta en la lista
    //se recorre la lista para saber la cantidad de elementos
    //Tenemos que considerar 6 casos
    //1er caso: lista con un unico elemento
    //2do caso: solo es el primer elemento de la lista
    //3er caso: eliminar el ultimo elemento de la lista
    //4to caso: eliminar el elemento a la mitad de la lista
    //5to caso: eliminar elementos consecutivos
    //6to caso: elemento a eliminar no esta en la lista
    if(datoEnLista(elemento)){
        int indice  = 0;
        while(puntAux){
            if(puntAux->getInfo() == elemento){
                //Caso que sea el primer/unico elemeto de la lista
                if(punteroLista->getInfo() == elemento){
                    nodoAnterior = punteroLista;
                    punteroLista = punteroLista -> getSigNodo();
                    puntAux = puntAux -> getSigNodo();
                    delete nodoAnterior;
                }
                else{
                    if(puntAux->getSigNodo()){
                        //Entra aca si el valor no esta en el principio o en el final
                        nodoAnterior = puntAux; 
                        //se guarda la posicion del nodo anterior
                        Nodo *proxNodo = puntAux -> getSigNodo();
                        //se crea un nodo provicional que apunta al proximo nodo
                        delete puntAux;
                        //se borra el nodo con el dato que queremos eliminar
                        nodoAnterior ->setSigNodo(proxNodo);
                        //se enlaza el nodo anterior al proximo nodo
                    }
                    else{
                        //entra aca si si no se cumple todos los demas
                        //entonces el elemento esta al final de la lista
                        bajaFinal();
                    }
                }
            }
            puntAux = puntAux -> getSigNodo();
        }
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