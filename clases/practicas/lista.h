#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

const int MAX_TAMANO = 1024;

class listaEnteros
{
    private:
        int vectorLista[MAX_TAMANO];
        int topeLista;
    public:
        //Constuctor de la lista
        listaEnteros();
        //Destructor de la clase
        ~listaEnteros();
        /*Casos que tiene que cumplir la lista
        -Borrar primero
        -Borrar el ultimo
        -Borrar uno en cualquier posicion
        -Borrar en primera aparicion = (Se indica que elemento se quiere robar y se elimina el primero)
        -Borrar elementos = (se indica que elemento se quiere borrar y se eliminan todos)
        -Obtener primero
        -Obtener ultimo
        -Obtener el elemento de una posicion determinada
        -Obtener el tamano de la lista
        -Listar todos los elementos de la lista
        -Listar en forma inversa*/
        void borrarPrimerDato();
        void borrarUltimoDato();
        void borrar_X_Pos(int posicion);
        bool listaLlena();
        void ingresarDato(int numero);
        
};

#endif