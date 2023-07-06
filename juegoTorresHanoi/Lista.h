

#ifndef EXAMEN_DATOS_LISTA_H
#define EXAMEN_DATOS_LISTA_H

#include <ostream>
#include "Nodo.cpp"

template <class tipo>
class Lista{
private:
    Nodo<tipo> *raiz;
public:
    Lista();
    ~Lista();
    string toString();
    tipo *inicio();
    void borrarInicio();
    void agregarInicio(tipo*);
    void todos();
};


#endif //EXAMEN_DATOS_LISTA_H
