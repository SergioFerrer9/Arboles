    #include "avl.h"
    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    using namespace std;
    using std::cout;
    using std::endl;
    int correlativo2=1;

    ///************CONSTRUCTORES**************************************
    AVL::AVL()
    {
        this->raiz=NULL;
    }

    typedef struct NodoAVL nodoAVL;

    ///*************ALTURA DEL ARBOL AVL******************************
    int Altura(NodoAVL *actual){
        if(actual==NULL){
            return -1;
        }else{
            return actual->altura;
        }
    }

    int Mayor(int num1, int num2){
        if(num1>num2){
            return num1;
        }else{
            return num2;
        }
    }

    ///****************ROTACIONES*************************************
    NodoAVL *AVL::Izquierda(NodoAVL *n1){
        NodoAVL *n2 =n1->izq;
        n1->izq=n2->der;
        n2->der=n1;
        n1->altura=Mayor(Altura(n1->izq),Altura(n1->der)) +1;
        n2->altura=Mayor(Altura(n2->izq), n1->altura) +1;
        return n2;
    }

    NodoAVL *AVL::Derecha(NodoAVL *n1){
        NodoAVL *n2 =n1->der;
        n1->der=n2->izq;
        n2->izq=n1;
        n1->altura=Mayor(Altura(n1->izq), Altura(n1->der)) +1;
        n2->altura=Mayor(Altura(n2->der), n1->altura) +1;
        return n2;
    }

    NodoAVL *AVL::IzquierdaDerecha(NodoAVL *n1){
        n1->izq=Derecha(n1->izq);
        return Izquierda(n1);
    }

    NodoAVL *AVL::DerechaIzquierda(NodoAVL *n1){
        n1->der=Izquierda(n1->der);
        return Derecha(n1);
    }
    ///***********BUSCAR**********************************************
    NodoAVL *AVL::Buscar(char *nombre, NodoAVL *actual){
        if(raiz==NULL){
                return NULL;
            }else if(strcmp(actual->Nombre,nombre)==0){
                return actual;
            }else if(strcmp(actual->Nombre,nombre)<0){
                return Buscar(nombre,actual->der);
            }else{
                return Buscar(nombre,actual->izq);
            }
         }


    ///***********INSERTAR EN EL ARBOL AVL****************************
    void AVL::Insertar(char *nombre, int edad){
        nodoAVL *nuevo;
        nuevo=(nodoAVL*)malloc(sizeof(struct NodoAVL));
        nuevo->Nombre=nombre;
        nuevo->Edad=edad;
        nuevo->izq=NULL;
        nuevo->der=NULL;
        nuevo->contador=correlativo2++;

        if(raiz==NULL){
            raiz=nuevo;
        }else{
            raiz=Insertar(nuevo,raiz);
           }


    }

    NodoAVL *AVL::Insertar(NodoAVL *nuevo, NodoAVL *actual){
        nodoAVL *Padre =actual;
        if(strcmp(nuevo->Nombre,actual->Nombre)<0){//nuevo->Nombre<actual->Nombre
            if(actual->izq==NULL){
                actual->izq=nuevo;

            }else{
                actual->izq=Insertar(nuevo,actual->izq);
                if((Altura(actual->izq)-Altura(actual->der))==2){
                    if(strcmp(nuevo->Nombre,actual->izq->Nombre)<0){
                        Padre=Izquierda(actual);
                    }else{
                        Padre=IzquierdaDerecha(actual);
                    }
                }
            }
        }else if (strcmp(nuevo->Nombre,actual->Nombre)>0) {
            if(actual->der==NULL){
                actual->der=nuevo;
            }else{
                actual->der=Insertar(nuevo,actual->der);
                if((Altura(actual->der)-Altura(actual->izq))==2){
                    if(strcmp(nuevo->Nombre,actual->der->Nombre)>0){
                        Padre=Derecha(actual);
                    }else{
                        Padre=DerechaIzquierda(actual);
                    }
                }
            }
        }else{
            cout<<"NODO DUPLICADO...."<<endl;
        }

        actual->altura = Mayor(Altura(actual->izq), Altura(actual->der)) + 1;

    }


    ///*************RECORRIDO EN INORDEN*****************************
    void AVL::Mostrar_InOrden(){
        cout << endl;
        cout << "*****Recorrido AVL InOrden*****" << endl;
        Mostrar_InOrden(raiz);
        cout << "*****Fin Recorrido AVL InOrden*****" << endl;
    }

    void AVL::Mostrar_InOrden(NodoAVL *actual){
        if(actual!=NULL){
            Mostrar_InOrden(actual->izq);
            cout<< actual->Nombre<<endl;
            Mostrar_InOrden(actual->der);
        }
    }


























