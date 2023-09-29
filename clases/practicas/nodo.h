#ifndef NODO_H
#define NODO_H
#include <iostream>

class Nodo
{
    private:
        int info;
        Nodo *siguiente;
    public:
        //ESTRUCTURA DEL NODO
        Nodo(int, Nodo *);
        //INFO DEL NODO ACTUAL
        int getInfo();
        //DA PASO AL SIGUIENTE NODO
        Nodo *getSigNodo();
        //DA EL VALOR AL NODO ME PARECE
        void setInfo(int i);
        //SETEA EL SIGUIENTE NODO
        void setSigNodo(Nodo *puntero);
        //~Nodo();
};




#endif