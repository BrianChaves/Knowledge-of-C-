#include <iostream>
#include "Menu.h"
int main() {
    ArbolBinario arbol;
    HeapColaPrioridad pq;
    Menu m(arbol, pq);
    m.menuPrincipal();
    return 0;
}
