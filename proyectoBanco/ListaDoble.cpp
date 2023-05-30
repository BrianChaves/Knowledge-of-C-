
#include "ListaDoble.h"

ListaDoble::ListaDoble() {
    this->first = new Nodo();
    this->last = new Nodo();
    first->setRight(last);
    last->setLeft(first);
}

Cliente *ListaDoble::valorInicio(){
    Nodo*temp = first->getRight();
    if(temp == nullptr)
        return nullptr;
    return temp->getInfo();
}

Cliente *ListaDoble::valorFinal() {
    Nodo*temp = last->getRight();
    if(temp == nullptr) return nullptr;
    return temp->getInfo();
}

void ListaDoble::insertar(Nodo *referencia, Cliente *info) {
    Nodo *nuevo = new Nodo();
    nuevo->setInfo(info);
    nuevo->setRight(referencia);
    nuevo->setLeft(referencia->getLeft());
    referencia->getLeft()->setRight(nuevo);
    referencia->setLeft(nuevo);
}

void ListaDoble::borrar(Nodo* actual) {

        Nodo *ant = actual->getLeft();
        Nodo *sig = actual->getRight();
        ant->setRight(sig);
        sig->setLeft(ant);
        delete actual;
}



void ListaDoble::borrarInicio() {
    borrar(first->getRight());
}

void ListaDoble::borrarFinal() {
    borrar(last->getLeft());
}


bool ListaDoble::vacia() {
    return (first->getRight() == last);
}

void ListaDoble::insertarInicio(Cliente *info) {
    insertar(first->getRight(),info);
}

void ListaDoble::insertarFinal(Cliente *info) {
    insertar(last,info);
}

void ListaDoble::ordenar() {
    try {
        if (vacia()) {
            cout << "Lista vacia" << endl;
        } else {
            Nodo *q = first->getRight();
            while (q->getInfo() != nullptr) {
                Nodo *r = q->getRight();
                while (r->getInfo() != nullptr) {

                    if (q->getInfo()->getInfluencia() < r->getInfo()->getInfluencia()) {
                        Cliente *dato = q->getInfo();
                        q->setInfo(r->getInfo());
                        r->setInfo(dato);
                        mostrar();
                    }
                    r = r->getRight();
                }
                q = q->getRight();
            }
        }
    } catch (string err){
        cout<<"ERROR PRODUCIDO AL ORDENAR"<<endl;
    }
}

string ListaDoble::mostrar() {
    stringstream ss;
    Nodo *temp = first->getRight();
    try{
        if(temp == last) ss << "Lista vacia!"<<endl;
        else{
            ss << "Null <->";
            while(temp != last){
                ss << temp->getInfo()->getInfluencia()<<"<->";
                temp = temp->getRight();
            }
            ss<<"NULL" << endl;
        }
        return ss.str();
    }catch(string err){
        cout<<"ERROR PRODUCIDO AL MOSTRAR"<<endl;
    }
}


ListaDoble::~ListaDoble() {

}



