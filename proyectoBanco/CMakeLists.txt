cmake_minimum_required(VERSION 3.19.2)
project(Proyecto_Datos)

set(CMAKE_CXX_STANDARD 14)

add_executable(Proyecto_Datos main.cpp Cliente.cpp Cliente.h Nodo.cpp Nodo.h ArbolBinario.cpp ArbolBinario.h Menu.cpp Menu.h ListaDoble.cpp ListaDoble.h HeapColaPrioridad.cpp HeapColaPrioridad.h)
