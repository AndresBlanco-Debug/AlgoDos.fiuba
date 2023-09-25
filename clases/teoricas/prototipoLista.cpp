#include <iostream>
using namespace std;
//Creacion de un espacio en memoria para almacenar un nodo
struct Nodo{
    int dato;
    Nodo *siguiente;
};//---------------------------------------------------------------------------
//Estructura basica del nodo
/*void agregarPila(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;
}//----------------------------------------------------------------------------*/
//eliminar elementos de una pila
void sacarPila(Nodo *&pila, int &n){
    Nodo *aux = pila;
    n = aux -> dato;
    pila = aux -> siguiente;
    delete aux;
}
//-----------------------------------------------------------------------------
void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;
    Nodo *aux1 = lista;
    Nodo *aux2;
    while((aux1 != NULL) && aux1 -> dato < n){
        aux2 = aux1;
        aux1 = aux1 -> siguiente;
    }
    if( lista== aux1){
        lista = nuevo_nodo;
    }
    else{
        aux2 -> siguiente = nuevo_nodo;
    }
    nuevo_nodo -> siguiente = aux1;
    cout << "\tElemento" << n << "insertdo correctamente" << endl;
}
//3 casos para agrgar elementos a la lista
//1. Lista = NULL
//2. Ya hay un nodo
//3. (2 o mas nodos) agergar en cualquier posicion
int main(){
    Nodo *lista = NULL;
    int dato;
    cout << "Digite un numero: ";
    cin >> dato;
    insertarLista(lista,dato);
    return 0;
}