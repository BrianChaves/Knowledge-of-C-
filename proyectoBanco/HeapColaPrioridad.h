

#ifndef PROYECTO_DATOS_HEAPCOLAPRIORIDAD_H
#define PROYECTO_DATOS_HEAPCOLAPRIORIDAD_H

#include "ListaDoble.h"
#include "ArbolBinario.h"
class HeapColaPrioridad {
private:
    ListaDoble *T;
    int cantidad;
public:
    virtual ~HeapColaPrioridad();
    HeapColaPrioridad();
    int size() const;
    bool empty() const;
    void insertarInicio(Cliente *info);
    void insertarFinal(Cliente *info);
    Cliente* max();
    void eliminarMax();
    string mostrarCola();
    void ordenarPQ();
};

#endif //PROYECTO_DATOS_HEAPCOLAPRIORIDAD_H
