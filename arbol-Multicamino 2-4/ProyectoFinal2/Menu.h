//
// Created by brian on 9/11/2022.
//

#ifndef PROYECTO2_MENU_H
#define PROYECTO2_MENU_H
#include <iostream>
#include "TwoFour.h"
#include<cstdlib>
#include <exception>
#include <cstring>
#include <chrono>
#include <iostream>
#include <time.h>

using namespace std;
class Menu {
private:
    TwoFour *theTree ;
public:
    Menu();

    Menu(TwoFour *theTree);

    virtual ~Menu();
    void menuPrincipal();
    void opcion1();
    void opcion2();
    void opcion3();
    void opcion4();
    void opcion5();
    void opcion6();
    void opcion7();
    void opcion8();


};


#endif //PROYECTO2_MENU_H
