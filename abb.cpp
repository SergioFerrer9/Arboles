#include "abb.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;
int correlativo=1;

///*************CONSTRUCTORES*************************************
ABB::ABB(){
    this->raiz=NULL;
}

typedef struct NodoABB nodoABB;

///************BUSCAR SI EL NODO YA EXISTE EN EL ARBOL ABB*******
NodoABB *ABB::buscar(char *nombre){
    return buscar(this->raiz, nombre);
}

NodoABB *ABB::buscar(NodoABB *actual, char *nombre){
    if(actual==NULL){
        return NULL;
    }

    int comparacion = strcmp(nombre, actual->Nombre);
    if(comparacion==0){
        return actual;
    }else{
        return buscar(comparacion <0 ? actual->izq : actual->der, nombre);
    }
}

///***********INSERTAR UN NUEVO NODO EL EL ARBOL ABB***************
void ABB::Insertar(char *nombre,int edad){
    nodoABB *nuevo;
    nuevo=(nodoABB*)malloc(sizeof(struct NodoABB));
    nuevo->Nombre=nombre;
    nuevo->Edad=edad;
    nuevo->izq=NULL;
    nuevo->der=NULL;
    nuevo->contador=correlativo++;

    if(raiz==NULL){
        raiz=nuevo;
    }else{
        nodoABB *actual=raiz;
        if(buscar(nombre)==NULL){
                while(true){
                        if(strcmp(nombre,actual->Nombre)<0){
                            if(actual->izq==NULL){
                                actual->izq=nuevo;
                                return;
                            }else{
                                actual=actual->izq;
                            }

                    }else{
                            if(actual->der==NULL){
                                actual->der=nuevo;
                                return;
                            }else{
                                actual=actual->der;
                            }
                    }
                }//FIN WHILE
        }
        return;
    }

}


///**********MOSTRAR EL ARBOL ABB EN INORDEN**********************
void ABB::Mostrar_InOrden(){
    cout<<endl;
    cout<<"**********Arbol ABB, Recorrido InOrden******************"<<endl;
    Mostrar_InOrden(raiz);
    cout<<"**********FIN Recorrido InOrden*************************"<<endl;
}

void ABB::Mostrar_InOrden(NodoABB *actual){
    if(actual!=NULL){
        Mostrar_InOrden(actual->izq);
        cout<<actual->Nombre<<endl;
        Mostrar_InOrden(actual->der);
    }
}

///*********GRAFICAR ARBOL ABB***********************************
void ABB::Graficar_ABB(){
    gra=fopen("ArbolABB.dot","wt");
    fputs("digraph grafica{\n ",gra);
    fputs("rankdir=TB;\n",gra);
    fputs("node [\n" ,gra);
    fputs("shape =record, ",gra);
    fputs("fillcolor=seashell2, ",gra);
    fputs("style =filled, ",gra);
    fputs("];\n",gra);

    cout << endl;
    cout << "*****Graficar Arbol ABB*****" << endl;

     Graficar_ABB(raiz);

    fputs("}",gra);
    fclose(gra);
    system("dot -Tpng ArbolABB.dot -o ArbolABB.png");
    cout << "*****Fin Graficar InOrden*****" << endl;

}

void ABB::Graficar_ABB(NodoABB *actual){
    if(actual != NULL)
    {

        if(actual->izq ==NULL && actual->der==NULL){
            fputs("\"",gra);
            fputs("nodo",gra);
            fprintf(gra,"%d",actual->contador);
            fputs("\"",gra);
            fputs("\n[ ",gra);
            fprintf(gra, "label=\" " );
            fprintf(gra, "%s",actual->Nombre);
            fputs("\"];\n",gra);

        }else{
            fputs("\"",gra);
            fputs("nodo",gra);
            fprintf(gra,"%d",actual->contador);
            fputs("\"",gra);
            fputs("\n[ ",gra);
            fprintf(gra, "label=\"<C0>| " );
            fprintf(gra, "%s",actual->Nombre);
            fputs("|<C1>\"];\n",gra);

        }
        if(actual->izq!=NULL){
            Graficar_ABB(actual->izq);
            fputs("nodo",gra);
            fprintf(gra,"%d",actual->contador);
            fputs(":C0->nodo",gra);
            fprintf(gra,"%d",actual->izq->contador);
            fputs("\n",gra);

        }
        if(actual->der!=NULL){
            Graficar_ABB(actual->der);
            fputs("nodo",gra);
            fprintf(gra,"%d",actual->contador);
            fputs(":C1->nodo",gra);
            fprintf(gra,"%d",actual->der->contador);
            fputs("\n",gra);
        }


    }


}























