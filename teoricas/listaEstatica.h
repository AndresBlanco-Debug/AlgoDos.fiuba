#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED

typedef char dato;
//Tamano maximo de la lista
const int MAX_TAM = 10;
/*Clase lista estatica implementada con un vector de elementos y tamano fijo*/
class Lista_estatica
{
private:
    //Vector donde se iran agregando los elementos
    dato lista[MAX_TAM];
    //tamano logico de la lista
    int tope;
public:
    //CONSTRUCTOR
    //PRE: ninguna
    //POST: crea una lista vacia con tope 0
    Lista_estatica();
    
    //Destructor
    //PRE: la lista fue creada
    //POST: nada(No tiene codigo ya que es estatica)
    ~Lista_estatica();

    //Isertar un dato
    //PRE: lista creada
    //POST: Si la lista no esta llena
    //  -se inserta al final el dato d
    //   -tope se incrementa en 1
    //  Si la lista esta llena no hace nada
    void insert(dato d);

    //Indica si la lista esta vacia o no:
    //PRE: lista creada
    //POST: devuelve true si la lista esta vacia, sino devuelve false
    bool lista_vacia();

    //Indica si la lista esta llena o no
    //PRE: LISTA CREADA
    //POST: devuelve true si la lista esta llena, sino devuelve false
    bool lista_llena();

    //Devuelve el dato que esta en posicion
    //PRE:   - Lista creada
    //       - no vacia
    //       - 0 < posicion <= tope
    //POST:  - devuelve el dato que esta en la posicion
    //       NOTA: se toma 1 como la primera posicion
    dato get_dato(int posicion); 

    //Borrado de un dato
    //PRE:   - Lista creada
    //      - no vacia
    //      - 0 < posicion <= tope
    //POST: - se borra el dato que esta en esa posicion
    //      - tope se decrementa en 1
    //      NOTA: se toma como 1 la primera posicion    
    void del_dato(int posicion);

    //Devuelve el tamano logico de la lista
    //PRE: lista creada
    //POST: devuelve el valor de tope
    int get_tope();
};
//INVARIANTES
//tope >= 0
//tope <= MAX_TAM

#endif