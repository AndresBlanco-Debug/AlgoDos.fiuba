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
        void altaPrincipio(int);
        void altaXPosicion(int,int);
        void bajaLista(int);
        bool datoEnLista(int);
        void emiteLista();
        ~Lista();
};

#endif