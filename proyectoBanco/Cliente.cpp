#include "Cliente.h"

Cliente::Cliente() {
    nombre = "";
    identificacion = 0;
    ingresaNino = false;
    embarazada = false;
    adultoMayor = false;
    categoria = 0;
    influencia = 0;
}

long long int Cliente::getIdentificacion() const {
    return identificacion;
}

void Cliente::setIdentificacion(long long int identificacion) {
    Cliente::identificacion = identificacion;
}

Cliente::Cliente(string nombre, long long int identificacion, bool ingresaNino, bool embarazada,
                 bool adultoMayor, int categoria) : nombre(nombre), identificacion(identificacion),
                                                    ingresaNino(ingresaNino), embarazada(embarazada),
                                                    adultoMayor(adultoMayor), categoria(categoria) {
    int aux = 0;
    if(ingresaNino){
        aux = aux + 20;
    }
    if(embarazada){
        aux = aux + 25;
    }
    if(adultoMayor){
        aux = aux + 35;
    }
    switch (categoria) {
        case 1:
            aux = aux + 20;
            break;
        case 2:
            aux = aux + 10;
            break;
        case 3:
            aux = aux + 0;
            break;
    }
    influencia = aux;
}





string Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(string nombre) {
    Cliente::nombre = nombre;
}

bool Cliente::isIngresaNino() const {
    return ingresaNino;
}

void Cliente::setIngresaNino(bool ingresaNino) {
    Cliente::ingresaNino = ingresaNino;
}

bool Cliente::isEmbarazada() const {
    return embarazada;
}

void Cliente::setEmbarazada(bool embarazada) {
    Cliente::embarazada = embarazada;
}

bool Cliente::isAdultoMayor() const {
    return adultoMayor;
}

void Cliente::setAdultoMayor(bool adultoMayor) {
    Cliente::adultoMayor = adultoMayor;
}

int Cliente::getCategoria() const {
    return categoria;
}

void Cliente::setCategoria(int categoria) {
    Cliente::categoria = categoria;
}

string Cliente::toString() {
    stringstream os;
    os << "nombre: " << nombre << " identificacion: " << identificacion << " ingresaNino: "
       << ingresaNino << " embarazada: " << embarazada << " adultoMayor: " << adultoMayor
       << " categoria: " << categoria;
    return os.str();
}

int Cliente::getInfluencia() const {
    return influencia;
}

void Cliente::setInfluencia(int influencia) {
    Cliente::influencia = influencia;
}

Cliente::~Cliente() = default;


