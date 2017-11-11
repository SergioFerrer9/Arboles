#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <abb.h>


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
    abb->Mostrar_InOrden();
    abb->Graficar_ABB();
    QPixmap pixabb("/home/debian9/Escritorio/Arboles/ArbolABB.png");
    ui->label->setPixmap(pixabb);

}
