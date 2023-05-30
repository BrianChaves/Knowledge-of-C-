
#ifndef PROYECTO_DATOS_NODO_H
#define PROYECTO_DATOS_NODO_H
#include <iostream>
#include <sstream>

#include "Cliente.h"
class Nodo {
private:
    Cliente *info;
    Nodo *left;
    Nodo *right;
public:
    Nodo(Cliente *info = nullptr, Nodo *left = nullptr, Nodo *right = nullptr);
    virtual ~Nodo();
    Cliente *getInfo() const;
    void setInfo(Cliente *info);
    Nodo *getLeft() const;
    void setLeft(Nodo *left);
    Nodo *getRight() const;
    void setRight(Nodo *right);
    bool isExternal();
    bool isInternal();
};


#endif //PROYECTO_DATOS_NODO_H
