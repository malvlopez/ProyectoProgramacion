#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto* header=ui->tablaMostrarPelis->horizontalHeader();
    header -> setSectionResizeMode(0, QHeaderView::ResizeToContents); //Anio
    header -> setSectionResizeMode(5, QHeaderView::ResizeToContents); //Calificacion
    header -> setSectionResizeMode(3, QHeaderView::ResizeToContents); //Estado

    ui->tablaMostrarPelis->setColumnWidth(1, 200);
    ui->tablaMostrarPelis->setColumnWidth(5, 180);
    header->setSectionResizeMode(1, QHeaderView::Stretch);//Titulo
    header->setSectionResizeMode(2, QHeaderView::Stretch);//Director
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Mensaje", "Hola mundo");
}
