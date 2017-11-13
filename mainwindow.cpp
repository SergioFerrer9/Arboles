#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <abb.h>
#include <avl.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_pushButton_clicked()
{

    ABB *abb = new ABB();
    abb->Insertar("F",1);
    abb->Insertar("M",2);
    abb->Insertar("B",33);
    abb->Insertar("C",3);
    abb->Insertar("A",44);
    abb->Insertar("H",5);
    abb->Insertar("H",32);
    abb->Insertar("N",2);
    abb->Insertar("D",8);
    abb->Insertar("I",8);
    abb->Insertar("E",8);
    abb->Mostrar_InOrden();
    abb->Graficar_ABB();
    QPixmap pixabb("/home/debian9/Escritorio/Arboles/ArbolABB.png");
    ui->label->setPixmap(pixabb);


    AVL *avl = new AVL();
    avl->Insertar("F",2);
    avl->Insertar("M",3);
    avl->Insertar("B",5);
    avl->Insertar("C",6);
    avl->Insertar("A",7);
    avl->Insertar("H",8);
    avl->Insertar("H",8);
    avl->Insertar("N",9);
    avl->Insertar("Z",10);
    avl->Insertar("D",11);


    avl->Mostrar_InOrden();
    avl->Graficar_AVL();
    QPixmap pixavl("/home/debian9/Escritorio/Arboles/ArbolAVL.png");
    ui->label_2->setPixmap(pixavl);




}
