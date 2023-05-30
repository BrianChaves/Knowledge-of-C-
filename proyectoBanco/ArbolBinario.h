#ifndef PROYECTO_DATOS_ARBOLBINARIO_H
#define PROYECTO_DATOS_ARBOLBINARIO_H

#include "Nodo.h"
class ArbolBinario {
private:
    int size;
    Nodo *raiz;
public:
    ArbolBinario();
    virtual ~ArbolBinario();
    bool vacio();
    void insertaNorm(Cliente *valor);
    void insertaRecur(Cliente *valor, Nodo* hoja);
    void destruyeArbol(Nodo *nodo);
    Nodo *buscaRecur(long long int valor, Nodo* hoja);
    Nodo *busca(long long int id);
    int getSize() const;
    void setSize(int size);
};


#endif //PROYECTO_DATOS_ARBOLBINARIO_H
