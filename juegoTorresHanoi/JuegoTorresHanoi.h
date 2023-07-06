
#ifndef EXAMEN_DATOS_JUEGOTORRESHANOI_H
#define EXAMEN_DATOS_JUEGOTORRESHANOI_H

#include "PilaLista.cpp"
#include "math.h"
template <class t>
class JuegoTorresHanoi {
private:
    PilaLista<t> *torre_uno;
    PilaLista<t> *torre_dos;
    PilaLista<t> *torre_tres;
public:
   JuegoTorresHanoi();
    ~JuegoTorresHanoi();
    void jugar();
    void menuSecundario();
    void opc3Principal(int clave);
    void dibujar();
    void generarNumeros();
};




#endif //EXAMEN_DATOS_JUEGOTORRESHANOI_H
