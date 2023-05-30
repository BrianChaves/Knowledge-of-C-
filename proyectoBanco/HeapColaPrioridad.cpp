
#include "HeapColaPrioridad.h"

int HeapColaPrioridad::size() const {
    return cantidad;
}

bool HeapColaPrioridad::empty() const {
    return size() == 0;
}

void HeapColaPrioridad::insertarInicio(Cliente *info) {
    T->insertarInicio(info);
    cantidad++;
}

void HeapColaPrioridad::insertarFinal(Cliente *info) {
    T->insertarFinal(info);
    cantidad++;
}
Cliente* HeapColaPrioridad::max() {
    return T->valorInicio();
}

void HeapColaPrioridad::eliminarMax() {
    T->borrarInicio();
    cantidad--;
}

HeapColaPrioridad::HeapColaPrioridad() {
    T = new ListaDoble;
    cantidad = 0;
}


string HeapColaPrioridad::mostrarCola() {
    T->ordenar();
    return T->mostrar();
}

HeapColaPrioridad::~HeapColaPrioridad() {
    delete T;
}

void HeapColaPrioridad::ordenarPQ() {
    T->ordenar();
}
