
#ifndef EXAMEN_DATOS_NODO_H
#define EXAMEN_DATOS_NODO_H
#include <iostream>
#include <sstream>
using namespace std;

template <class tipo>
class Nodo {
private:
    tipo *datos;
    Nodo *siguiente;

public:
    Nodo();
    tipo *getDatos() const ;
    void setDatos(tipo *datos);
    Nodo *getSiguiente() const;
    friend ostream &operator<<(ostream &os, const Nodo<tipo> &nodo);
    void setSiguiente(Nodo *siguiente);
};


#endif //EXAMEN_DATOS_NODO_H
