#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <abb.h>
#include <avl.h>
AVL *avl = new AVL();

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
    abb->Eliminar_ABB("A");
    abb->Mostrar_InOrden();
    abb->Graficar_ABB();
    QPixmap pixabb("/home/debian9/Escritorio/Arboles/ArbolABB.png");
    ui->label->setPixmap(pixabb);


    AVL *avl = new AVL();
    avl->Insertar("A",9);
    avl->Insertar("B",9);
    avl->Insertar("C",9);
    avl->Insertar("D",9);
    avl->Insertar("E",9);
    avl->Insertar("F",9);
    avl->Insertar("G",9);
    avl->Insertar("H",9);
    avl->Insertar("I",9);
    avl->Insertar("J",9);
    avl->Insertar("K",9);
    avl->Insertar("L",9);
    avl->Insertar("M",9);
    avl->Insertar("N",9);
    avl->Insertar("O",9);
    avl->Insertar("P",9);
    avl->Insertar("Q",9);
    avl->Insertar("R",9);
    avl->Insertar("S",9);
    avl->Insertar("T",9);
    avl->Insertar("U",9);
    avl->Insertar("V",9);
    avl->Insertar("W",9);
    avl->Insertar("X",9);
    avl->Insertar("Y",9);
    avl->Insertar("Z",9);


    avl->Mostrar_InOrden();
    avl->Graficar_AVL();
    QPixmap pixavl("/home/debian9/Escritorio/Arboles/ArbolAVL.png");
    ui->label_2->setPixmap(pixavl);




}

void MainWindow::on_pushButton_2_clicked()
{

    char *texto=strdup(ui->lineEdit->text().toUtf8().constData());
    avl->Insertar(texto,9);
    avl->Graficar_AVL();
    QPixmap pixavl("/home/debian9/Escritorio/Arboles/ArbolAVL.png");
    ui->label_2->setPixmap(pixavl);

}

















