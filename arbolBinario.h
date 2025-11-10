//
// Creado por Luis Sebastian Correa Barreto - 20242020085
//    y Sebastian Camilo Sanchez Cardenas - 20242020086
//

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include <iostream>
#include "estructura1.h"
#include "pila1.h"
using namespace std;

template <typename T>
class arbolBinario {
private:
    Nodo<T>* raiz;

    // Inserción recursiva
    Nodo<T>* insertar(Nodo<T>* nodo, const T& valor) {
        if (nodo == nullptr)
            return new Nodo<T>(valor);
        if (valor < nodo->dato)
            nodo->izq = insertar(nodo->izq, valor);
        else
            nodo->der = insertar(nodo->der, valor);
        return nodo;
    }

public:
    arbolBinario() : raiz(nullptr) {}

    // Inserta un valor en el árbol
    void insertar(const T& valor) {
        raiz = insertar(raiz, valor);
    }

    void inorden() const {
        cout << "Inorden: ";
        Pila<Nodo<T>*> pila;
        Nodo<T>* actual = raiz;

        while (actual != nullptr || !pila.PilaVacia()) {
            while (actual != nullptr) {
                pila.Push(actual);
                actual = actual->izq;
            }

            actual = pila.Pop();
            cout << actual->dato << " ";
            actual = actual->der;
        }
        cout << endl;
    }

    void preorden() const {
        cout << "Preorden: ";
        if (!raiz) return;
        Pila<Nodo<T>*> pila;
        pila.Push(raiz);

        while (!pila.PilaVacia()) {
            Nodo<T>* nodo = pila.Pop();
            cout << nodo->dato << " ";

            if (nodo->der) pila.Push(nodo->der);
            if (nodo->izq) pila.Push(nodo->izq);
        }
        cout << endl;
    }

    void postorden() const {
        cout << "Postorden: ";
        if (!raiz) return;

        Pila<Nodo<T>*> pila1, pila2;
        pila1.Push(raiz);

        while (!pila1.PilaVacia()) {
            Nodo<T>* nodo = pila1.Pop();
            pila2.Push(nodo);

            if (nodo->izq) pila1.Push(nodo->izq);
            if (nodo->der) pila1.Push(nodo->der);
        }

        while (!pila2.PilaVacia()) {
            cout << pila2.Pop()->dato << " ";
        }
        cout << endl;
    }
};

#endif //ARBOLBINARIO_H
