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

        raiz=Insertar(nuevo,raiz);

    }

    NodoAVL *AVL::Insertar(NodoAVL *nuevo, NodoAVL *actual){

       //Si el nodo rcibido fuera nulo entonces el nuevo nodo se puede insertar
       //en esa posicion y se terminan las llamadas recursivas a este metodo......
       if(actual == NULL){
           actual = nuevo;

           //Si el nuevo valor fuera menor que el nodo de actual entonces...
       }else if(strcmp(nuevo->Nombre,actual->Nombre)<0){
           //Se llama recursivamente al metodo para explorar el subarbol izquierdo
           //porque el valor a insertar es menor que el del nodo actual.....
           actual->izq=Insertar(nuevo,actual->izq);
           if((Altura(actual->der)-Altura(actual->izq))==-2){
               //Si el factor de equilibrio esta desbalanceado, hay qu hacer
               //rotacion de nodos, como el fe=-2 hay dos posibilidades de
               //rotacion dependiendo de:...
               if(strcmp(nuevo->Nombre,actual->izq->Nombre)<0){
                   //Si el nuevo valor fuera menor que la izquierda del nodo desbalancado
                   //se sabe que el nuevo nodo sera insertado a la izquierda de la actual
                   //izquierda, entonces tenemos una rotacion simple por la izquierda o sea
                   //una IzquierdaIzquierda....
                   actual=Izquierda(actual);
               }else{
                   //de lo contrario se sabe que el neuvo nodo sera insertado
                   // a la derecha de la actual izquierda, por lo que se tiene
                   // un caso de rotacion doble por la izquirda
                   // o sea una IzquierdaDerecha....
                   actual=IzquierdaDerecha(actual);
               }

           }

       }else if(strcmp(nuevo->Nombre,actual->Nombre)>0){
           //Si el nuevo valor fuera mayor que el nodo de la actual entonces :
           //se llama recursivamente al metodo para explorar el sub arbol derecho
           //porque el valor a insertar es mayor que el del nodo actual.
           actual->der=Insertar(nuevo,actual->der);
           if((Altura(actual->der) - Altura(actual->izq)==2)){
               //Si el factor de equilibrio esta desbalanceado, hay que hacer
               //rotacion de nodos, como el fe=2 hay dos posibilidades de
               //rotacion dependiendo de:
               if(strcmp(nuevo->Nombre,actual->der->Nombre)>0){
                   //Si el nuevo valor fuera maor que la derecha del nodo desbalanceado
                   //se sabe que el neuvo nodo sera insertado a la derecha del actual derecha
                   //entonces tenemos una rotacion simple por la derecha o sea DerechaDerecha...
                   actual=Derecha(actual);

               }else{
                   //de lo contrario, se sabe que el nuevo nodo sera insertado
                   //a la izquierda de la actual derecha, por lo que se tiene
                   //un caso de rotacion doble por la derecha
                   //o sea una DerechaIzquierda.
                   actual = DerechaIzquierda(actual);
               }
           }
       }else{
           //De lo contrario significa que el valor que se quiere insertar ya existe
           //como no se permite la duplicidad de este dato no se hace nada.
           cout<<"No se permite los valores duplicados..  "<<endl;
           cout<<nuevo->Nombre<<endl;
       }
           //Finalmente, por cada llamada recursiva debe hacerse una reasignacion
           //de la altura esta se hara hasta para los nodos que no cambiaron de nivel
           //en el transcurso porque no hay forma de saber cuales cambiaron de nivel
           //y cuales no. La altura, sera la altura del hijo que tiene
           //la altrua mas grande, es decir, la rama mas profunda, mas 1.
           actual->altura = Mayor(Altura(actual->izq), Altura(actual->der)) + 1;
           return actual;

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

    ///************GRAFICAR ARBOL AVL*****************************
    void AVL::Graficar_AVL(){
        gra=fopen("ArbolAVL.dot","wt");
        fputs("digraph grafica{\n ",gra);
        fputs("rankdir=TB;\n",gra);
        fputs("node [\n" ,gra);
        fputs("shape =record, ",gra);
        fputs("fillcolor=seashell2, ",gra);
        fputs("style =filled, ",gra);
        fputs("];\n",gra);

        cout << endl;
        cout << "*****Graficar Arbol AVL*****" << endl;

         Graficar_AVL(raiz);

        fputs("}",gra);
        fclose(gra);
        system("dot -Tpng ArbolAVL.dot -o ArbolAVL.png");
        cout << "*****Fin Graficar InOrden*****" << endl;
    }

    void AVL::Graficar_AVL(NodoAVL *actual){
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
                fputs(",",gra);
                fprintf(gra, "%d",actual->Edad);
                fputs("\"];\n",gra);

            }else{
                fputs("\"",gra);
                fputs("nodo",gra);
                fprintf(gra,"%d",actual->contador);
                fputs("\"",gra);
                fputs("\n[ ",gra);
                fprintf(gra, "label=\"<C0>| " );
                fprintf(gra, "%s",actual->Nombre);
                fputs(",",gra);
                fprintf(gra, "%d",actual->Edad);
                fputs("|<C1>\"];\n",gra);

            }
            if(actual->izq!=NULL){
                Graficar_AVL(actual->izq);
                fputs("nodo",gra);
                fprintf(gra,"%d",actual->contador);
                fputs(":C0->nodo",gra);
                fprintf(gra,"%d",actual->izq->contador);
                fputs("\n",gra);

            }
            if(actual->der!=NULL){
                Graficar_AVL(actual->der);
                fputs("nodo",gra);
                fprintf(gra,"%d",actual->contador);
                fputs(":C1->nodo",gra);
                fprintf(gra,"%d",actual->der->contador);
                fputs("\n",gra);
            }


        }
    }



























