#ifndef NODO_H
#define NODO_H
#include <iostream>

class Nodo
{
    private:
        int info;
        Nodo *siguiente;
    public:
        Nodo(int, Nodo *);
        int getInfo();
        Nodo *getSigNodo();
        void setInfo(int i);
        void setSigNodo(Nodo *puntero);
        ~Nodo();
};




#endif