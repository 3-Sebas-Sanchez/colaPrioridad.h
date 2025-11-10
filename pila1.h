//
// Creado por Luis Sebastian Correa Barreto - 20242020085
//    y Sebastian Camilo Sanchez Cardenas - 20242020086
//

#ifndef PILA1_H
#define PILA1_H

#include <iostream>
#include "estructura1.h"
using namespace std;

template <typename T>
class Pila {
private:
    Nodo<T>* cab; // nodo cabecera (dummy)

public:
    // Constructor
    Pila() {
        cab = new Nodo<T>(T());
        cab->sig = nullptr;
    }

    // Destructor
    ~Pila() {
        Nodo<T>* t = cab;
        while (t != nullptr) {
            Nodo<T>* aux = t;
            t = t->sig;
            delete aux;
        }
    }

    // Inserta un elemento en la pila
    void Push(const T& v) {
        Nodo<T>* t = new Nodo<T>(v);
        t->sig = cab->sig;
        cab->sig = t;
    }

    // Saca un elemento de la pila
    T Pop() {
        if (PilaVacia()) throw runtime_error("Error: pila vacía");
        Nodo<T>* t = cab->sig;
        cab->sig = t->sig;
        T x = t->dato;
        delete t;
        return x;
    }

    // Verifica si la pila está vacía
    bool PilaVacia() const {
        return cab->sig == nullptr;
    }

};

#endif //PILA1_H
