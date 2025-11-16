//
// Creado por Luis Sebastian Correa Barreto - 20242020085
//   y Sebastian Camilo Sanchez Cardenas - 20242020086
// 
#include <iostream>
#include <string>
#include <limits>
#include "ArbolBinOrdenado.h"

using namespace std;

int main() {
    int maxN;
    cout << "Tamano maximo del arbol: ";
    if(!(cin >> maxN)){
        cerr << "Entrada invalida. Saliendo.\n";
        return 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ArbolBinarioOrdenado arbol(maxN);

    //Insertar claves y su informacion
    cout << "Insercion de elementos" << endl;
    while(true){
        string opcion;
        cout << "Desea insertar una nueva clave? (s/n): ";
        if(!getline(cin, opcion)) break;
        if(opcion.empty()) continue;
        if(opcion[0] == 'n' || opcion[0] == 'N') break;

        int clave;
        cout << "Ingrese la clave en entero: ";
        if(!(cin >> clave)){
            cout << "Clave invalida, vuelva a intentar." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string info;
        cout << "Ingrese la informacion asociada: ";
        getline(cin, info);

        bool ok = arbol.insertar(clave, info);
        if(ok) cout << "Insertado correctamente." << endl;
        else cout << "Fallo la insercion (arbol lleno o clave duplicada)." << endl;
    }

    //Imprimir los 4 recorridos (clave + info)
    cout << "Primer recorrido: " << endl;
    arbol.inorden();
    arbol.preorden();
    arbol.posorden();
    arbol.porNiveles();

    // Menu para buscar y eliminar repetidamente
    int op;
    do {
        cout << " Menu: 1. Buscar  2. Eliminar  3. Mostrar recorridos  4. Salir" << endl;
        cout << "Elija una opcion: ";
        if(!(cin >> op)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(op == 1){
            int clave;
            cout << "Ingrese clave a buscar: ";
            if(!(cin >> clave)){
                cout << "Clave invalida." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string info = arbol.buscar(clave);
            cout << "Resultado: " << info << endl;
        }
        else if(op == 2){
            int clave;
            cout << "Ingrese clave a eliminar: ";
            if(!(cin >> clave)){
                cout << "Clave invalida." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool ex = arbol.eliminar(clave);
            if(ex) cout << "Eliminacion realizada." << endl;
            else cout << "Clave no encontrada, no se pudo eliminar." << endl;
        }
        else if(op == 3){
            cout << " Recorridos nuevos: " << endl;
            arbol.inorden();
            arbol.preorden();
            arbol.posorden();
            arbol.porNiveles();
        }
        else if(op == 4){
            cout << "El arbol se guardara en el destructor" << endl;
        }
        else
            cout << "Opcion invalida." << endl;
    }while(op != 4);

    return 0;
}
