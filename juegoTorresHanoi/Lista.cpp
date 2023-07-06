
#include "Lista.h"

template<class tipo>
Lista<tipo>::Lista() {
    raiz = new Nodo<tipo>;
}

template<class tipo>
Lista<tipo>::~Lista() {
    Nodo<tipo> *temp;
    Nodo<tipo> *anterior;
    if(raiz->getSiguiente() == nullptr){
        delete raiz;
    }else{
        while(raiz->getSiguiente() != nullptr){
            temp = raiz;
            while(temp->getSiguiente() != nullptr){
                anterior = temp;
                temp = temp->getSiguiente();
            }
            anterior->setSiguiente(nullptr);
            delete temp;
        }
    }
    cout<< "Lista borrada!" <<endl;
}

template<class tipo>
string Lista<tipo>::toString() {
    stringstream ss;
    Nodo<tipo> *temp = raiz;
    if(temp->getSiguiente() == nullptr){
        ss << "Lista vacia!"<<endl;
    }else{
        temp = temp->getSiguiente();
        do{
            ss << temp->getDatos();
            ss << "-->";
            temp = temp->getSiguiente();
        }while(temp != nullptr);
        ss<< "NULL" << endl;
    }
    return ss.str();
}

template<class tipo>
tipo *Lista<tipo>::inicio() {
    Nodo<tipo> *temp = raiz;
    if(temp->getSiguiente() != nullptr){
        temp = temp->getSiguiente();
        return temp->getDatos();
    }
    return nullptr;
}
template<class tipo>
void Lista<tipo>::todos() {
    Nodo<tipo> *temp = raiz;
    if(temp->getSiguiente() == nullptr){
        cout << " TORRE VACIA ";
    }else{
        temp = temp->getSiguiente();
        do{
            cout << *temp;
            temp = temp->getSiguiente();
        }while(temp != nullptr);
    }

}
template<class tipo>
void Lista<tipo>::borrarInicio() {
    Nodo<tipo> *temp = raiz;
    if(temp->getSiguiente() != nullptr){
        temp = temp->getSiguiente();
        raiz->setSiguiente(temp->getSiguiente());
        delete temp;
    }
}

template<class tipo>
void Lista<tipo>::agregarInicio(tipo *p) {
    Nodo<tipo> *nuevo = new Nodo<tipo>;
    nuevo->setDatos(p);
    nuevo->setSiguiente(raiz->getSiguiente());
    raiz->setSiguiente(nuevo);
}





