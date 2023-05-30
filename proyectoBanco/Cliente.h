#ifndef PROYECTO_DATOS_CLIENTE_H
#define PROYECTO_DATOS_CLIENTE_H

#include <iostream>
#include <sstream>
using namespace std;


class Cliente {
private:
    string nombre;
    long long int identificacion;
    bool ingresaNino;
    bool embarazada;
    bool adultoMayor;
    int categoria;
    int influencia;
public:
    Cliente(string nombre, long long int identificacion, bool ingresaNino, bool embarazada, bool adultoMayor,
            int categoria);
    Cliente();
    ~Cliente();
    string getNombre() const;
    void setNombre(string nombre);
    bool isIngresaNino() const;
    void setIngresaNino(bool ingresaNino);
    bool isEmbarazada() const;
    void setEmbarazada(bool embarazada);
    bool isAdultoMayor() const;
    void setAdultoMayor(bool adultoMayor);
    int getCategoria() const;
    void setCategoria(int categoria);
    long long int getIdentificacion() const;
    void setIdentificacion(long long int identificacion);

    int getInfluencia() const;

    void setInfluencia(int influencia);

    string toString();
};


#endif //PROYECTO_DATOS_CLIENTE_H
