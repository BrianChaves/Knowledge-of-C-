#include "ArbolBinario.h"

ArbolBinario::ArbolBinario() {
    raiz = nullptr;
    size = 0;
}

ArbolBinario::~ArbolBinario() {
    destruyeArbol(raiz);
}

bool ArbolBinario::vacio() {
    return raiz == nullptr;
}

void ArbolBinario::insertaNorm(Cliente *valor) {
    Nodo* nuevo;
    Nodo *temp;
    temp = raiz;
    nuevo = new Nodo;
    nuevo->setInfo(valor);
    try{
        if(raiz == nullptr){
            raiz = nuevo;
            size++;
        }
        else
        {
            while(temp != nullptr)
            {
                if(temp->getInfo()->getIdentificacion() > valor->getIdentificacion())
                {
                    if(temp->getLeft() == nullptr)
                    {
                        temp->setLeft(nuevo);
                        size++;
                    }
                    else {
                        temp = temp->getLeft();
                    }
                }
                else if(temp->getInfo()->getIdentificacion() < valor->getIdentificacion())
                {
                    if(temp->getRight() == nullptr)
                    {
                        temp->setRight(nuevo);
                        size++;
                    }
                    else temp = temp->getRight();
                }
                else return;
            }
        }
    }catch(string err){
        cout<<"ERROR PRODUCIDO"<<endl;
    }
}

void ArbolBinario::insertaRecur(Cliente *valor, Nodo *hoja) {
    try {
        if (valor->getIdentificacion() < hoja->getInfo()->getIdentificacion()) {
            if (hoja->getLeft() != nullptr) {
                insertaRecur(valor, hoja->getLeft());
            } else {
                hoja->setLeft(new Nodo(valor, nullptr, nullptr));
            }
        } else {
            if (valor->getIdentificacion() > hoja->getInfo()->getIdentificacion()) {
                if (hoja->getRight() != nullptr) {
                    insertaRecur(valor, hoja->getRight());
                } else {
                    hoja->setRight(new Nodo);
                    hoja = hoja->getRight();
                    hoja->setInfo(valor);
                }
            }
        }
    } catch(string err){
        cout<<"ERROR PRODUCIDO"<<endl;
    }
}

void ArbolBinario::destruyeArbol(Nodo *nodo) {
    try {
        if (nodo != nullptr) {
            destruyeArbol(nodo->getLeft());
            destruyeArbol(nodo->getRight());
            delete nodo;
        }
    } catch(string err){
        cout<<"ERROR PRODUCIDO"<<endl;
    }
}

Nodo *ArbolBinario::buscaRecur(long long int valor, Nodo *hoja) {
    try {
        if (hoja != nullptr) {
            if (valor == hoja->getInfo()->getIdentificacion())
                return hoja;
            if (valor < hoja->getInfo()->getIdentificacion())
                return buscaRecur(valor, hoja->getLeft());
            else
                return buscaRecur(valor, hoja->getRight());
        }
        return nullptr;
    } catch(string err){
        cout<<"ERROR PRODUCIDO"<<endl;
    }

}



Nodo *ArbolBinario::busca(long long int id) {
    return buscaRecur(id, raiz);
}

int ArbolBinario::getSize() const {
    return size;
}

void ArbolBinario::setSize(int size) {
    ArbolBinario::size = size;
}


