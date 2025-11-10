//
// Creado por Luis Sebastian Correa Barreto - 20242020085
//    y Sebastian Camilo Sanchez Cardenas - 20242020086
//

#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class colaPrioridad {
private:
    vector<T> cola;

    // Devuelve el índice del padre
    int padre(int i) const { return i / 2; }

    // Devuelve índice del hijo izquierdo
    int hijoIzquierdo(int i) const { return 2 * i; }

    // Devuelve índice del hijo derecho
    int hijoDerecho(int i) const { return 2 * i + 1; }

    // Mantiene el monticulo hacia arriba
    void flotar(int i) {
        while (i > 1 && cola[i] > cola[padre(i)]) {
            swap(cola[i], cola[padre(i)]);
            i = padre(i);
        }
    }

    // Mantiene el monticulo hacia abajo
    void hundir(int i) {
        int n = cola.size() - 1;
        while (true) {
            int izq = hijoIzquierdo(i);
            int der = hijoDerecho(i);
            int mayor = i;

            if (izq <= n && cola[izq] > cola[mayor])
                mayor = izq;
            if (der <= n && cola[der] > cola[mayor])
                mayor = der;

            if (mayor != i) {
                swap(cola[i], cola[mayor]);
                i = mayor;
            } else break;
        }
    }

public:
    // Constructor
    colaPrioridad() { cola.push_back(T()); } // índice 0 vacío

    // Inserta un elemento en la cola
    void insertar(const T& valor) {
        cola.push_back(valor);
        flotar(cola.size() - 1);
    }

    // Devuelve el de mayor prioridad
    const T& maximo() const {
        if (cola.size() <= 1) throw runtime_error("Cola vacía");
        return cola[1];
    }

    // Elimina el elemento de máxima prioridad
    void eliminarMaximo() {
        if (cola.size() <= 1) throw runtime_error("Cola vacía");
        cola[1] = cola.back();
        cola.pop_back();
        if (cola.size() > 1) hundir(1);
    }

    // Devuelve true si está vacía
    bool vacia() const {
        return cola.size() <=1;
    }

    // Devuelve el tamaño
    int tamano() const {
        return cola.size() - 1;
    }

    // Imprime el contenido del monticulo
    void mostrar() const {
        cout << "Cola: ";
        for (int i = 1; i < cola.size(); ++i)
            cout << cola[i] << " ";
        cout << endl;
    }
};

#endif //COLAPRIORIDAD_H
