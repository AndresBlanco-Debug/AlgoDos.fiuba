#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"
class Lista
{
private:
    Nodo *punteroNodo;
public:
    Lista();
    void altaFinal(int); //ALTA AL FINAL
    void altaPrincipio(int);//ALTA AL PRINCIPIO
    void bajaLista(int);//BAJA LA PRIMERA APARICION DE UN ELEMENTO
    bool enLista(int);//AVISA SI EL NUMERO ESTA EN LA LISTA
    void emiteLista();//EMITE LA LISTA
    ~Lista();
};

#endif