#include <iostream>
#include "listaEstatica.h"

Lista_estatica::Lista_estatica(){
    tope = 0;
}
Lista_estatica::~Lista_estatica(){

}
bool Lista_estatica::lista_llena(){
    return (tope==MAX_TAM);
}
bool Lista_estatica::lista_vacia(){
    return (tope == 0);
}
void Lista_estatica::insert(dato d){
    if(!(this->lista_llena())){
        lista[tope++] = d;
    }
}
dato Lista_estatica::get_dato(int posicion){
    return lista[posicion - 1];
}
void Lista_estatica::del_dato(int posicion){
    posicion--;
    tope--;
    while(posicion < tope){
        lista[posicion] = lista[posicion + 1];
        posicion++;
    }
}
int Lista_estatica::get_tope(){
    return tope;
}