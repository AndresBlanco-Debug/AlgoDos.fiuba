#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
class Lista
{
    private:
        Nodo *punteroLista;
    public:
        Lista();
        void altaFinal(int);
        //Ingresa datos al final de la lista
        void altaPrincipio(int);
        //Ingresa datos al principio de la lista
        void altaXPosicion(int,int);
        //Ingresa datos en cualquier posicion de la lista
        void bajaLista(int);
        //Elimina el primer elemento que coincida con el ingresado
        bool datoEnLista(int);
        //revisa si un dato ya esta en la lista
        void emiteLista();
        //muestra la lista
        void bajaPricipio();
        //elimina el primer elemento de la lista
        void bajaFinal();
        //elimina el ultimo elemento de la lista
        void bajaXPosicion(int);
        //elimina el elemento en cualquier posicion
        void eliminarDato(int);
        //elimina todas las apariciones del mismo elemento en la lista
        void mostrarPrimerElemento();
        //muestra primer elemento de la lista, si tiene elementos
        void mostrarUltimoElemento();
        //muestra el ultimo elemento de la lista
        void mostrarXElemento(int);
        //muestra el elemento en la posicion ingresada
        void invertirLista();
        //EJERCICIO 7 PRACTICA DE LISTAS:
        /*Diseñar e implementar una nueva ListaEnteros donde el alta será únicamente en
        orden, por lo que no se indicará la posición. Tener en cuenta que puede haber
        elementos repetidos.*/
        void bajaEnOrden();
        //FUNCION QUE ELIMINA TODOS LOS DATOS REPETIDOS DEJADO UNA SOLA APARICION
        void bajaRepetida(int);
        /*Recibe una lista por parámetro e indica si ésta está incluida o no (devuelve
        true o false).*/
        bool subLista(Lista subLista);


        ~Lista();
};

#endif