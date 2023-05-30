
#ifndef PROYECTO_DATOS_LISTADOBLE_H
#define PROYECTO_DATOS_LISTADOBLE_H

#include "Nodo.h"
class ListaDoble {
private:
    Nodo *first;
    Nodo *last;
public:
    virtual ~ListaDoble();
    ListaDoble();
    Cliente *valorInicio();
    Cliente *valorFinal();
    void insertar(Nodo *referencia, Cliente *info);
    void insertarFinal(Cliente *info);
    void insertarInicio(Cliente *info);
    void borrar(Nodo *actual);
    void borrarInicio();
    void borrarFinal();
    bool vacia();
    void ordenar();
    string mostrar();
};

#endif //PROYECTO_DATOS_LISTADOBLE_H
