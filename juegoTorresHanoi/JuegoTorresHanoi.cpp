
#include "JuegoTorresHanoi.h"

template<class t>
JuegoTorresHanoi<t>::~JuegoTorresHanoi() {
    delete torre_uno;
    delete torre_dos;
    delete torre_tres;
}

template<class t>
JuegoTorresHanoi<t>::JuegoTorresHanoi() {
    torre_uno = new PilaLista<t>;
    torre_dos = new PilaLista<t>;
    torre_tres = new PilaLista<t>;
}

template<class t>
void JuegoTorresHanoi<t>::jugar() {
    int opcion = 1;
    int clave = 0;
    do {
        cout << "-----------------Menu Principal------------------------" << endl;
        cout << "( 1 )  Ingresar al Juego" << endl;
        cout << "( 2 )  Mostrar el minimo numero de movimientos para ganar" << endl;
        cout << "( 3 )  Mostrar el algoritmo completo paso a paso de la solucion" << endl;
        cout << "( 0 )  Salir  " << endl << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Digite una opcion del menu:  ";
        cout<<endl;
        cin >> opcion;
        switch (opcion){
            case 1 :
                cout<<endl;
                menuSecundario();
                break;
            case 2 :
                cout << "MOVIMIENTOS MINIMOS PARA GANAR: 15"<<endl;
                break;
            case 3 :
                cout<<"Digite clave: ";
                cin >> clave;
                opc3Principal(clave);
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                break;
        }
    } while ( opcion != 0);
}

template<class t>
void JuegoTorresHanoi<t>::menuSecundario() {
    generarNumeros();
    int opc = 1;
    int contador = 0;
    do {
        dibujar();
        cout<< "CANTIDAD DE MOVIMIENTOS REALIZADOS: "<<contador<<endl;
        cout << "-----------------Menu Juego------------------------" << endl;
        cout << "( 1 )  De la pila 1 a la pila 2 " << endl;
        cout << "( 2 )  De la pila 1 a la pila 3 " << endl;
        cout << "( 3 )  De la pila 2 a la pila 1 " << endl;
        cout << "( 4 )  De la pila 2 a la pila 3 " << endl;
        cout << "( 5 )  De la pila 3 a la pila 1 " << endl;
        cout << "( 6 )  De la pila 3 a la pila 2 " << endl;
        cout << "( 7 )  Reiniciar el juego  "  << endl;
        cout << "( 0 )  Salir  "  << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Digite una opcion del menu:  ";
        cin >> opc;
        cout<<endl;
        switch (opc){
            case 0:
                exit(0);
            case 1 :
                if(!torre_uno->empty()){
                    torre_dos->push(torre_uno->top());
                    torre_uno->pop();
                    contador++;
                }else
                contador++;
                cout<<"No se puede realizar el movimiento"<<endl;

                break;
            case 2 :
                if(!torre_uno->empty()){
                    torre_tres->push(torre_uno->top());
                torre_uno->pop();
                contador++;
                }else
                contador++;
                cout<<"No se puede realizar el movimiento"<<endl;

                break;
            case 3 :
                if(!torre_dos->empty()){
                    torre_uno->push(torre_dos->top());
                torre_dos->pop();
                contador++;
                }else
                contador++;
                cout<<"No se puede realizar el movimiento"<<endl;
                break;

            case 4 :
                if(!torre_dos->empty()){
                    torre_tres->push(torre_dos->top());
                torre_dos->pop();
                contador++;
                }else
                contador++;
                cout<<"No se puede realizar el movimiento"<<endl;
                break;

            case 5 :
                if(!torre_tres->empty()){
                    torre_uno->push(torre_tres->top());
                torre_tres->pop();
                contador++;
                }else
                contador++;
                cout<<"No se puede realizar el movimiento"<<endl;

                break;
            case 6 :
                if(!torre_tres->empty()){
                    torre_dos->push(torre_tres->top());
                torre_tres->pop();
                contador++;
                }else
                contador++;
                cout<<"No se puede realizar el movimiento"<<endl;

                break;
            case 7 :
                for(int i = 0; i <4; i++){
                    if(!torre_uno->empty()){
                        torre_uno->pop();
                    }
                    if(!torre_dos->empty()){
                        torre_dos->pop();
                    }
                    if(!torre_tres->empty()) {
                        torre_tres->pop();
                    }
                }
                menuSecundario();
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                break;
        }
    } while ( opc != 0);
}

template<class t>
void JuegoTorresHanoi<t>::opc3Principal(int clave) {
    if(clave == 123){
        cout <<" 1)   De la Pila 1 a la Pila 2\n"
               "  2)   De la Pila 1 a la Pila 3\n"
               "  3)   De la Pila 2 a la Pila 3\n"
               "  4)   De la Pila 1 a la Pila 2\n"
               "  5)   De la Pila 3 a la Pila 1\n"
               "  6)   De la Pila 3 a la Pila 2\n"
               "  7)   De la Pila 1 a la Pila 2\n"
               "  8)   De la Pila 1 a la Pila 3\n"
               "  9)   De la Pila 2 a la Pila 3\n"
               "  10)  De la Pila 2 a la Pila 1\n"
               "  11)  De la Pila 3 a la Pila 1\n"
               "  12)  De la Pila 2 a la Pila 3\n"
               "  13)  De la Pila 1 a la Pila 2\n"
               "  14)  De la Pila 1 a la Pila 3\n"
               "  15)  De la Pila 2 a la Pila 3\n";
    }else{
        cout <<" CLAVE INCORRECTA"<<endl;
    }
}
template<class t>
void JuegoTorresHanoi<t>::dibujar(){
    cout << "\n====================================" << endl;
    cout<< "                       ||"<<endl;
    torre_uno->imprimir();
    cout<< "||Torre 1"<<endl;
    cout<< "                       ||";cout << endl; cout <<endl;

    cout<< "                       ||"<<endl;
    torre_dos->imprimir();
    cout<< "||Torre 2"<<endl;
    cout<< "                       ||";cout << endl; cout <<endl;

    cout<< "                       ||"<<endl;
    torre_tres->imprimir();
    cout<< "||Torre 3"<<endl;
    cout<< "                       ||";cout << endl; cout <<endl;
    cout << "\n====================================" << endl;
}

template<class t>
void JuegoTorresHanoi<t>::generarNumeros(){
    for(int h = 3 ; h >= 0; h--){
        torre_uno->push(new int((h + 4)* pow((h + 9),h+1)));
    }
}


