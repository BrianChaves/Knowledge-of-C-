
#include <cstring>
#include "Menu.h"

Menu::Menu(const ArbolBinario &arbol, const HeapColaPrioridad &pq) : arbol(arbol), pq(pq) {}

void Menu::menuPrincipal() {
    cargaDatos();
    cout<<"EL TAMANO DEL ARBOL ES: "<<arbol.getSize()<<endl;
    int opcion = 1;
    do {
        cout << "-----------------Menu Principal Banco Uno----------------------" << endl;
        cout << "( 1 )  Encolar todos los clientes" << endl;
        cout << "( 2 )  Encolar un cliente" << endl;
        cout << "( 3 )  Atender a los siguientes 5 clientes" << endl;
        cout << "( 4 )  Mostrar el siguiente cliente a ser atendido" << endl;
        cout << "( 5 )  Simulacion de Atencion de Clientes" << endl;
        cout << "( 6 )  Agregar un cliente nuevo" << endl;
        cout << "( 0 )  Salir  " << endl << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Digite una opcion del menu:  ";
        cout<<endl;
        cin >> opcion;
        switch (opcion){
            case 0:
                opcionSalir();
                exit(0);
            case 1 :
                cout<<endl;
                opcion1();
                break;
            case 2 :
               opcion2();
                break;
            case 3 :
                opcion3();
                break;
            case 4:
                opcion4();
                break;
            case 5:
                opcion5();
                break;
            case 6:
                opcion6();
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                break;
        }
    } while ( opcion != 0);
}

void Menu::opcion1() {
    ifstream archivo;
    string nom, id, uno, dos, tres, categoria;
    bool nino, embarazada, adultoM;
    try{
        archivo.open("../datos.txt",ios::in);
        if(archivo.fail()){
            throw 1;
        }
        else{
            while(!archivo.eof()){
                getline(archivo,nom,',');
                getline(archivo,id,',');
                getline(archivo,uno,',');
                getline(archivo,dos,',');
                getline(archivo,tres,',');
                getline(archivo,categoria,'\n');
                long long int ident = stoll(id, nullptr,10);
                if(uno == "Yes"){
                    nino = true;
                }else{
                    nino = false;
                }
                if(dos == "Yes"){
                    embarazada = true;
                }else{
                    embarazada = false;
                }
                if(tres == "Yes"){
                    adultoM = true;
                }else{
                    adultoM = false;
                }
                int categ = stoi(categoria);

                Cliente *client = new Cliente(nom, ident,nino,embarazada,adultoM,categ);
                pq.insertarFinal(client);
            }
        }
        archivo.close();
    }catch(int error){
        cout<<"Archivo no encontrado"<<endl;
    }
    pq.ordenarPQ();
    cout<<pq.mostrarCola();
}

void Menu::opcion2() {
    long long int id = 0;
    int k;
    cout << "Escriba el numero de cedula del cliente para encolar: ";
    cin >> id;
    k=isdigit(id);
    try {
        if (k == 0) {
        Cliente *aux = arbol.busca(id)->getInfo();
        pq.insertarFinal(aux);
        pq.ordenarPQ();
        cout << pq.mostrarCola();
        }
        else{
        throw 1;
    }
    }catch (int error){
    cout<<"Digitar una identificacion correctamente"<<endl;
    }
}

void Menu::opcion3() {
    try{
        if(!pq.empty()){
            cout<< "---------- 5 PROXIMOS CLIENTES A SER ATENDIDOS----------"<<endl;
            cout<<"CANTIDAD EN PQ: "<<pq.size()<<endl;
            for(int i = 0; i< 5; i++){
                cout<< "NOMBRE: "<<pq.max()->getNombre()<<endl;
                cout<< "ID: "<<pq.max()->getIdentificacion()<<endl;
                cout<< "% INFLUENCIA: "<<pq.max()->getInfluencia()<<endl;
                cout<<"-----------------------------"<<endl;
                pq.eliminarMax();
            }
        } else{
            throw 1;
        }

    }catch (int error){
        cout<<"NO HAY CLIENTES EN LA COLA PARA SER ATENDIDOS"<<endl;
    }
}

void Menu::opcion4() {
    try{
        if(!pq.empty()){
            cout<< "----------CLIENTE PROXIMO A SER ATENDIDO----------"<<endl;
            cout<< "NOMBRE: "<<pq.max()->getNombre()<<endl;
            cout<< "ID: "<<pq.max()->getIdentificacion()<<endl;
            cout<< "% INFLUENCIA: "<<pq.max()->getInfluencia()<<endl;
        } else{
            throw 1;
        }

    }catch (int error){
        cout<<"NO HAY CLIENTES EN LA COLA PARA SER ATENDIDOS"<<endl;
    }

}

void Menu::opcion5() {
    int i = 1;
    try{
        if(!pq.empty()){
            do{
                cout<< "----------CLIENTE PROXIMO A SER ATENDIDO----------"<<endl;
                cout<<"CLIENTE NUMERO #"<<i<<" EN SER ATENDIDO"<<endl;
                cout<< "POSICION EN LA COLA SEGUN INFLUENCIA: "<<i<<endl;
                cout<< "NOMBRE: "<<pq.max()->getNombre()<<endl;
                cout<< "ID: "<<pq.max()->getIdentificacion()<<endl;
                cout<< "% INFLUENCIA: "<<pq.max()->getInfluencia()<<endl;
                cout<<"---------------------------------------------------"<<endl;
                i++;
                pq.eliminarMax();
            }while(pq.size() != 0);
        } else{
            throw 1;
        }

    }catch (int error){
        cout<<"NO HAY CLIENTES EN LA COLA PARA SER ATENDIDOS"<<endl;
    }
}

void Menu::opcion6() {
    string apellido,nino, embarazada, adultoM, nombre, categoria;
    long long int id;
    int cate;
    bool ni, em, ad;
    cout<<"Escriba unicamente el NOMBRE del cliente:  "; cin >> nombre;
    cout<<endl;
    cout<<"Escriba unicamente el PRIMER APELLIDO del cliente:  "; cin >> apellido;
    cout<<endl;
    cout<<"Escriba la identificacion del cliente: "; cin >> id;
    cout<<endl;
    cout<<"Escriba si ingresa con un nino (Yes o No) : "; cin >> nino;
    cout<<endl;
    cout<<"Escriba si esta embarazada (Yes o No) : "; cin >> embarazada;
    cout<<endl;
    cout<<"Escriba si es adulto mayor (Yes o No) : "; cin >> adultoM;
    cout<<endl;
    cout<<"Escriba la categoria del cliente (1-2-3) : "; cin >> categoria;
    cate = stoi(categoria);
    if(nino == "Yes" ||nino == "yes" ){
        ni = true;
    }else{
        ni = false;
    }
    if(embarazada == "Yes"||embarazada == "yes"){
        em = true;
    }else{
        em = false;
    }
    if(adultoM == "Yes"||adultoM == "yes"){
        ad = true;
    }else{
        ad = false;
    }
    Cliente *cliente = new Cliente(nombre+" "+apellido,id,ni,em,ad,cate);
    arbol.insertaNorm(cliente);
    pq.insertarFinal(cliente);
    pq.ordenarPQ();
    cout<<"CANTIDAD DE ELEMENTOS EN EL ARBOL: "<<arbol.getSize()<<endl;
}

void Menu::cargaDatos() {
    ifstream archivo;
    string nom, id, uno, dos, tres, categoria;
    bool nino, embarazada, adultoM;

    try{
        archivo.open("../datos.txt",ios::in);
        if(archivo.fail()){
            throw 1;
        }
        else{
            while(!archivo.eof()){
                getline(archivo,nom,',');
                getline(archivo,id,',');
                getline(archivo,uno,',');
                getline(archivo,dos,',');
                getline(archivo,tres,',');
                getline(archivo,categoria,'\n');
                long long int ident = stoll(id, nullptr,10);
                if(uno == "Yes"){
                    nino = true;
                }else{
                    nino = false;
                }
                if(dos == "Yes"){
                    embarazada = true;
                }else{
                    embarazada = false;
                }
                if(tres == "Yes"){
                    adultoM = true;
                }else{
                    adultoM = false;
                }
                int categ = stoi(categoria);

                Cliente *client = new Cliente(nom, ident,nino,embarazada,adultoM,categ);
                arbol.insertaNorm(client);
            }
        }
        archivo.close();
    }catch(int error){
        cout<<"Archivo no encontrado"<<endl;
    }

}

Menu::~Menu() {

}

void Menu::opcionSalir() {
    fstream archivo;
    HeapColaPrioridad aux = pq;
    try{
    int can = pq.size();
        if(can == 0) throw 1;
        remove("../datos.txt");
        archivo.open("../datos.txt", ios::out);
        if(!archivo.is_open()){
            throw 1;
        }
        else{
            do{
                archivo << aux.max()->getNombre()<<","<<aux.max()->getIdentificacion()<<",";
                if(aux.max()->isIngresaNino()){
                    archivo << "Yes,";
                }else archivo << "No,";
                if(aux.max()->isEmbarazada()){
                    archivo << "Yes,";
                }else archivo << "No,";
                if(aux.max()->isAdultoMayor()){
                    archivo << "Yes,";
                }else archivo << "No,";
                archivo << aux.max()->getCategoria()<<"\n";
                aux.eliminarMax();
                can--;
            }while(can > 0);
        }
        archivo.close();
    }catch(int error) {
        cout<<"NO SE PUDO CREAR UN ARCHIVO NUEVO Y AGREGAR LOS NUEVOS CLIENTES"<<endl;
    }
}
