#include <iostream>
#include "lista.h"
using namespace std;

int main(){
    listaEstatica l;
    l.insertarDato('A');
    l.insertarDato('H');
    l.insertarDato('E');

    for(int i = 1; i <= l.get_tope(); i++){
        cout << l.get_dato(i) << endl;
    }
    l.del_dato(2);
    cout << "Listado luego de borrar la H " << endl;
    for(int i = 1; i <= l.get_tope(); i++){
        cout << l.get_dato(i) << endl;
    }
    return 0;
}