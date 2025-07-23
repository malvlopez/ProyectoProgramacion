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
    header -> setSectionResizeMode(0, QHeaderView::ResizeToContents); //Posicion
    header -> setSectionResizeMode(5, QHeaderView::ResizeToContents); //Calificacion
    header -> setSectionResizeMode(3, QHeaderView::ResizeToContents); //anio

    ui->tablaMostrarPelis->setColumnWidth(1, 200);
    ui->tablaMostrarPelis->setColumnWidth(5, 180);
    header->setSectionResizeMode(1, QHeaderView::Stretch);//Titulo
    header->setSectionResizeMode(2, QHeaderView::Stretch);//Director

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tablaMostrarPelis(){
    ui->tablaMostrarPelis->setRowCount(listaPeliculas.size());

    for (int i = 0; i < listaPeliculas.size(); ++i) {
        const pelicula& p = listaPeliculas[i];
        ui->tablaMostrarPelis->setItem(i, 1, new QTableWidgetItem(p.titulo));
        ui->tablaMostrarPelis->setItem(i, 2, new QTableWidgetItem(p.director));
        ui->tablaMostrarPelis->setItem(i, 3, new QTableWidgetItem(p.anio));
        ui->tablaMostrarPelis->setItem(i, 4, new QTableWidgetItem(p.estado));
        ui->tablaMostrarPelis->setItem(i, 5, new QTableWidgetItem(QString::number(p.calificacion)));
    }
}

void MainWindow::on_BotonAgregar_clicked()
{
    listaPeliculas.push_back({"Inception", 8.8, 2010, "Disponible", "Nolan"});
    listaPeliculas.push_back({"Naranja Mecanica", 9.0, 1990, "Disponible", "Enrique segoviano"});
    on_tablaMostrarPelis();
    QMessageBox::information(this, "Mensaje", "pelicula agregada");
}

