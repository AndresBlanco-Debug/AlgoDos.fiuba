#include "lista.h" 
 
using namespace std; 
 
int main() 
{ 
    Lista_SE l; 
 
    l.insert('A'); 
    l.insert('C'); 
    l.insert('F'); 
    l.insert('H'); 
 
    for (unsigned i = 1; i <= l.get_tam(); i++ ) 
    { 
        cout << l.get_dato(i) << endl; 
    } 
 
    // Se borra el segundo nodo 
    l.del_dato(2); 
    for (unsigned i = 1; i <= l.get_tam(); i++ ) 
    { 
        cout << l.get_dato(i) << endl; 
    } 
 
    return 0; 
} 