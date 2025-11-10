//
// Creado por Luis Sebastian Correa Barreto - 20242020085
//    y Sebastian Camilo Sanchez Cardenas - 20242020086
//

#ifndef ESTRUCTURA1_H
#define ESTRUCTURA1_H

template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* sig;
    Nodo<T>* izq;
    Nodo<T>* der;
};

#endif //ESTRUCTURA1_H
