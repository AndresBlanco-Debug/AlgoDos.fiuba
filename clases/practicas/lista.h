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

        ~Lista();
};

#endif