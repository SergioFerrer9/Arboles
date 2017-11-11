#ifndef ABB_H
#define ABB_H
#include <iostream>

///************NODO ARBLOL ABB************************************
struct NodoABB{
    char *Nombre;
    int Edad;
    struct NodoABB *izq;
    struct NodoABB *der;
    int contador;
};

///////////////METODOS DEL ARBOL ABB******************************
struct ABB{
    NodoABB *buscar(char *nombre);
    NodoABB *buscar(NodoABB *actual, char *nombre);
    void Insertar(char *nombre, int edad);
    void Mostrar_InOrden();
    void Mostrar_InOrden(NodoABB *actual);
    void Graficar_ABB();
    void Graficar_ABB(NodoABB *actual);
    NodoABB *raiz;
    ABB();
    FILE *gra;


};

#endif // ABB_H
