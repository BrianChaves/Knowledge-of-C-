#include <iostream>
#include "JuegoTorresHanoi.cpp"
int main() {
    try{
        JuegoTorresHanoi<int> *juego = new JuegoTorresHanoi<int>;
        juego->jugar();
        delete juego;
    }catch (RuntimeException e){
        cout<<"Error: "<<e.getMessage()<< '\n';
    }
    return 0;
}
