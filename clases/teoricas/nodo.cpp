#include "nodo.h" 
 
Nodo::Nodo(Dato d) 
{ 
     std::cout << "Se construye el nodo " << (unsigned)this << std::endl; 
     dato  = d; 
     psig  = 0; 
} 
 
Nodo::~Nodo() 
{ 
     std::cout << "Se destruye el nodo " << (unsigned)this << std::endl; 
} 
 
void Nodo::set_dato(Dato d) 
{ 
     dato = d; 
} 
 
Dato Nodo::get_dato() 
{ 
     return dato; 
} 
 
void Nodo::set_siguiente(Nodo* ps) 
{ 
     psig = ps; 
} 
 
Nodo* Nodo::get_siguiente() 
{ 
     return psig; 
}