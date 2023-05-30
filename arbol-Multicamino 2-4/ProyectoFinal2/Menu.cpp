//
// Created by brian on 9/11/2022.
//



#include "Menu.h"

Menu::Menu() {
    TwoFour *theTree = new TwoFour();

}

void Menu::menuPrincipal() {
    int opcion = 1;
    do {
        try {
            cout << " " << endl;
            cout << "-----------------Menu de Arbol Multi-Camino 2-4----------------------" << endl;
            cout << "( 1 )   Insert n random Integers" << endl;
            cout << "( 2 )   Perform 2n operations with probability" << endl;
            cout << "( 3 )   Print In Order" << endl;
            cout << "( 4 )   View Tree level by level" << endl;
            cout << "( 5 )   Insert an element" << endl;
            cout << "( 6 )   Delete an element" << endl;
            cout << "( 7 )   Find an element  " << endl;
            cout << "( 8 )   User Manual  " << endl;
            cout << "( 0 )   Get out  " << endl << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Type a menu option:  ";
            cout << endl;
            cin >> opcion;
            switch (opcion) {
                case 0:
                    cout << "Thank you!!!";
                    exit(0);
                case 1 :
                    cout << endl;
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
                case 7:
                    opcion7();
                    break;
                case 8:
                    opcion8();
                    break;
                default:
                    cout << "Invalid entry\n";
                    break;
            }
        } catch (exception e) {
            cout << "Please enter valid input";
        }
    } while (opcion != 0);
}

void Menu::opcion1() {
    int n;
    cout << "Only INT values/Integers" << endl;

    cout << "Enter the value of n";
    cin >> n;
    try {
        if (!cin.fail()) {
            for (int a = 1; a < n + 1; a++) {
                Node *present = theTree->find(a);
                if (present != nullptr) {
                    cout << "Data Already present!!" << endl;
                } else {
                    theTree->insert(a);


                }
            }
            cout << "Inserted successfully" << endl;

        } else {
            cout << "WARNING" << endl;
            cout << "Type a number correctly" << endl;
            throw 1;
        }

    } catch (int error) {
        cout << "WARNING" << endl;
        cout << "Read the instructions correctly" << endl;
        throw 1;

    }


}

void Menu::opcion2() {
    int n;
    cout << "Only INT values/Integers" << endl;

    cout << "Enter the value of n";
    cin >> n;

    int operation = 0;
    int searchCount = 0;
    int insertCount = 0;
    int deleteCount = 0;
    int max;

    max = 100;
    srand(time(0));

    auto start = chrono::steady_clock::now();


    try {
        if (!cin.fail()) {

            while (operation < (2 * n)) {
                double num = rand() % max;
                if (num < 0.4) {
                    // Making sure insert operation runs at 0.4
                    // probability
                    int x = rand() % n;
                    Node *present = theTree->find(x);
                    if (present != nullptr) {
                        cout << "Data Already present!!" << endl;
                    } else {
                        theTree->insert(x);
                    }
                    operation++;
                    insertCount++;

                }
                num = rand() % max;
                if (num < 0.25) { // Making sure delete operation runs at 0.25 //
                    // probability
                    int x = rand() % n;
                    Node *del = theTree->find(x);
                    if (del != nullptr) {
                        if (theTree->deletes(del, x) != nullptr) {
                            cout << "Deleted" << x << "\n";
                        } else {
                            cout << "Not Deleted!!! \n";
                        }
                    } else
                        cout << "Could not find " << x << "\n";
                    operation++;
                    deleteCount++;

                }
                num = rand() % max;
                if (num < 0.35) { // Making sure search operation runs at 0.35 //
                    // probability
                    theTree->find(num);
                    operation++;
                    searchCount++;

                }

            }
        } else {
            cout << "WARNING" << endl;
            cout << "Type a number correctly" << endl;
            throw 1;
        }
    } catch (int error) {
        cout << "WARNING" << endl;
        cout << "Read the instructions correctly" << endl;
        throw 1;

    }


    cout << "Total No. of search operations performed :" << searchCount << endl;
    cout << "Total No. of delete operations performed :"
         << deleteCount << endl;
    cout << "Total No. of insert operations performed :"
         << insertCount << endl;

    auto end = chrono::steady_clock::now();

    cout << "Total Time Taken: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " ns nanoseconds" << endl;


}

void Menu::opcion3() {

    cout << "In Order: ";
    cout << "     " << endl;
    theTree->displayTree(1);
    cout << "     " << endl;

}

void Menu::opcion4() {
    cout << "Tree:";
    cout << "     " << endl;
    theTree->displayTree(0);

}

void Menu::opcion5() {
    int value;
    cout << "Only INT values/Integers" << endl;

    cout << "Enter value to insert: ";
    cin >> value;
    try {
        if (!cin.fail()) {


            Node *present = theTree->find(value);
            if (present != nullptr) {
                cout << "Data Already present!!" << endl;
            } else {
                theTree->insert(value);
                cout << "  Data is inserted correctly   " << endl;

            }
            cout << "     " << endl;
        } else {
            cout << "WARNING" << endl;
            cout << "Type a number correctly" << endl;
            throw 1;
        }

    } catch (int error) {
        cout << "WARNING" << endl;
        cout << "Read the instructions correctly" << endl;
        throw 1;

    }
}

void Menu::opcion6() {

    cout << "Only INT values/Integers" << endl;

    cout << "Enter value to delete: ";
    int value;

    cin >> value;
    try {
        if (!cin.fail()) {

            Node *del = theTree->find(value);
            if (del != nullptr) {
                if (theTree->deletes(del, value) != nullptr) {
                    cout << "Deleted " << value << endl;
                } else {
                    cout << "Not Deleted!!!" << endl;
                }
            } else
                cout << "Could not find " << value << endl;

            cout << "     " << endl;
        } else {
            cout << "WARNING" << endl;
            cout << "Type a number correctly" << endl;
            throw 1;
        }

    } catch (int error) {
        cout << "WARNING" << endl;
        cout << "Read the instructions correctly" << endl;
        throw 1;

    }
}

void Menu::opcion7() {
    cout << "Only INT values/Integers" << endl;

    cout << "Enter value to find: ";
    int value;
    cin >> value;

    try {
        if (!cin.fail()) {

            Node *found = theTree->find(value);
            if (found != nullptr) {
                cout << "Found " << value << endl;
            } else
                cout << "Could not find  " << value << endl;

            cout << "     " << endl;
        } else {
            cout << "WARNING" << endl;
            cout << "Type a number correctly" << endl;
            throw 1;
        }

    } catch (int error) {
        cout << "WARNING" << endl;
        cout << "Read the instructions correctly" << endl;
        throw 1;

    }


}

void Menu::opcion8() {
    cout << "Descripcion del Funcionamiento de la opcion 1 :\n "
            "Lo que se realiza en la opcion numero 1 es pedir un numero para ver cuantos valores van a entrar al arbol,"
            " se realiza una verificacion para ver si algunos de los valores ya estan dentro o del arbol\n "
            "Si estos no estan realiza la insercion de estos.   \n" << endl;
    cout << "--------------------------------------------------------------------------------------------------"
         << endl;
    cout << "Descripcion del Funcionamiento de la opcion 2 :\n"
            "Se solicita un valor y con este buscamos con que tantas operaciones se realizaron para encontrar este numero. "
            "En el siguiente se puede observar en cuantas operaciones fueron realizadas para que fuera eliminado"
            " Al igual con los pasados en este ultimo se busca el numero de operaciones realizadas"
            " para hacer la insercion del numero seleccionado .\n"
            "Para finalizar se muestra el tiempo utilizado para realizar todas estas operaciones, "
            "el tiempo esta en nanosegundos. \n"
            "Todos estos datos pueden variar, ya que esta realizado con posibilidades y "
            "siempre hay posibilidades diferentes. Ademas, el tiempo de ejecucion tambien va a variar.\n" << endl;
    cout << "--------------------------------------------------------------------------------------------------"
         << endl;

    cout << "Descripcion del Funcionamiento de la opcion 3 :\n"
            "Para la siguiente opcion se muestra el arbol en orden a como fue insertado.\n" << endl;
    cout << "--------------------------------------------------------------------------------------------------"
         << endl;

    cout << "Descripcion del Funcionamiento de la opcion 4 :\n"
            "Para la siguiente opcion se va a mostrar los niveles de este arbol y sus hijos.\n" << endl;
    cout << "--------------------------------------------------------------------------------------------------"
         << endl;

    cout << "Descripcion del Funcionamiento de la opcion 5 :\n"
            "Para la siguiente opcion lo que se realiza es la insercion de un dato al arbol.\n"
            "Ademas, si se inserta un numero ya existente, le va a dar una respuesta y no lo va a insertar.\n" << endl;
    cout << "--------------------------------------------------------------------------------------------------"
         << endl;

    cout << "Descripcion del Funcionamiento de la opcion 6 :\n"
            "Para la siguiente opcion es eliminar un elemento del arbol."
            "Se escribe el numero que se desea eliminar y se procede y el arbol cambia por el elemento eliminado.\n"
         << endl;
    cout << "--------------------------------------------------------------------------------------------------"
         << endl;

    cout << "Descripcion del Funcionamiento de la opcion 7 :\n"
            "Se va a solicitar un elemento este para ser buscado en el arbol."
            "Si se encuentra va a mostrar si se encontro o no.\n" << endl;
    cout << "--------------------------------------------------------------------------------------------------"
         << endl;

    cout << "Descripcion del Funcionamiento de la opcion 8 :\n"
            "Para la siguiente opcion se va a mostrar una pequena guia del manual de usuario.\n" << endl;
    cout << "--------------------------------------------------------------------------------------------------"
         << endl;

    cout << "Descripcion del Funcionamiento de la opcion 0 :\n"
            "En esta opcion se dara una salida del sistema  .\n" << endl;

    cout << "--------------------------------------------------------------------------------------------------"
         << endl;


}


Menu::~Menu() {

}

Menu::Menu(TwoFour *theTree) : theTree(theTree) {}
