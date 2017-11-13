#ifndef AVL_H
#define AVL_H
#include <iostream>

///****************NODO ARBOL AVL*********************************
struct NodoAVL{
    char *Nombre;
    int Edad;
    struct NodoAVL *izq;
    struct NodoAVL *der;
    int altura;
    int contador;

};

///****************METODOS DEL ARBOL AVL**************************
struct AVL{
    void Insertar(char *nombre, int edad);
    NodoAVL *Insertar(NodoAVL *nuevo, NodoAVL *actual);
    void Mostrar_InOrden();
    void Mostrar_InOrden(NodoAVL *actual);
    NodoAVL *Buscar(char *nombre, NodoAVL *actual);
    void Graficar_ABB();
    void Graficar_ABB(NodoAVL *actual);
    int Factor_Equilibrio(NodoAVL *actual);
    NodoAVL *Izquierda(NodoAVL *actual);
    NodoAVL *Derecha(NodoAVL *actual);
    NodoAVL *IzquierdaDerecha(NodoAVL *actual);
    NodoAVL *DerechaIzquierda(NodoAVL *actual);
    NodoAVL *raiz;
    AVL();
    FILE *gra;
};


#endif // AVL_H
