
#ifndef EXAMEN_DATOS_PILALISTA_H
#define EXAMEN_DATOS_PILALISTA_H
#include "Lista.cpp"
#include "RuntimeException.h"

template <class tipo>
class PilaLista {
private:
    Lista<tipo> *S;
    int n;
public:
    PilaLista();
    ~PilaLista();
    int size();
    Lista<tipo> *getS() const;
    bool empty() const;
    tipo *top() throw(StackEmpty);
    void push(tipo *e);
    void pop() throw(StackEmpty);
    void imprimir();
};


#endif //EXAMEN_DATOS_PILALISTA_H
