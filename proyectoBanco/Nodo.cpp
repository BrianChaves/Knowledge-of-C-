#include "Nodo.h"

Nodo::Nodo(Cliente *info, Nodo *left, Nodo *right): info(info), left(left), right(right){
}
Nodo::~Nodo() {
}

Cliente *Nodo::getInfo() const {
    return info;
}

void Nodo::setInfo(Cliente *info) {
    Nodo::info = info;
}
/*int Nodo::getInfo() const {
    return info;
}

void Nodo::setInfo(int info) {
    Nodo::info = info;
}*/

Nodo *Nodo::getLeft() const {
    return left;
}

void Nodo::setLeft(Nodo *left) {
    Nodo::left = left;
}

Nodo *Nodo::getRight() const {
    return right;
}

void Nodo::setRight(Nodo *right) {
    Nodo::right = right;
}

bool Nodo::isExternal() {
    return (getLeft() == nullptr && getRight() == nullptr);
}

bool Nodo::isInternal() {
    return (getLeft() != nullptr || getRight() != nullptr);
}










