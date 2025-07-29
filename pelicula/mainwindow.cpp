#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include "formview.h"
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setSortingEnabled(true);

    ui->label->setVisible(true);

    ui->tableWidget->setColumnCount(4);
    QStringList headers = {"Nombre", "Calificación", "Reseñas", "Estado"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    cargarPeliculasDesdeArchivo();
}

void MainWindow::on_btnAgregar_clicked()
{
    FormView form(this);
    if (form.exec() == QDialog::Accepted) {
        int fila = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(fila);

        ui->tableWidget->setItem(fila, 0, new QTableWidgetItem(form.ui->lineEditNombre->text()));
        ui->tableWidget->setItem(fila, 1, new QTableWidgetItem(QString::number(form.ui->spinBoxCalificacion->value())));
        ui->tableWidget->setItem(fila, 2, new QTableWidgetItem(form.ui->textEditResena->toPlainText()));
        ui->tableWidget->setItem(fila, 3, new QTableWidgetItem(form.ui->comboBoxEstado->currentText()));
        guardarPeliculasEnArchivo();
    }
}


void MainWindow::on_btnEditar_clicked()
{
    int fila = ui->tableWidget->currentRow();
    if (fila >= 0) {
        FormView form(this);
        form.ui->lineEditNombre->setText(ui->tableWidget->item(fila, 0)->text());
        form.ui->spinBoxCalificacion->setValue(ui->tableWidget->item(fila, 1)->text().toInt());
        form.ui->textEditResena->setPlainText(ui->tableWidget->item(fila, 2)->text());
        form.ui->comboBoxEstado->setCurrentText(ui->tableWidget->item(fila, 3)->text());


        if (form.exec() == QDialog::Accepted) {
            ui->tableWidget->setItem(fila, 0, new QTableWidgetItem(form.ui->lineEditNombre->text()));
            ui->tableWidget->setItem(fila, 1, new QTableWidgetItem(QString::number(form.ui->spinBoxCalificacion->value())));
            ui->tableWidget->setItem(fila, 2, new QTableWidgetItem(form.ui->textEditResena->toPlainText()));
            ui->tableWidget->setItem(fila, 3, new QTableWidgetItem(form.ui->comboBoxEstado->currentText()));
            guardarPeliculasEnArchivo();
        }
    } else {
        QMessageBox::warning(this, "Advertencia", "Seleccione una película para editar.");
    }
}



void MainWindow::on_btnEliminar_clicked() {
    int fila = ui->tableWidget->currentRow();
    if (fila >= 0){
        auto respuesta = QMessageBox::question(this, "Eliminar", "¿Desea eliminar esta pelicula?");
        if(respuesta == QMessageBox::Yes) {
            ui->tableWidget->removeRow(fila);
            guardarPeliculasEnArchivo();
        }
    } else {
        QMessageBox::warning(this, "Advertencia", "Seleccione una fila para eliminar.");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::cargarPeliculasDesdeArchivo() {
    QString rutaArchivo = QApplication::applicationDirPath() + "/peliculas.txt";
    QFile file(rutaArchivo);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo de películas para lectura:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    ui->tableWidget->setRowCount(0);

    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList partes = linea.split("|||");

        if (partes.size() == 4) {
            int fila = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(fila);

            ui->tableWidget->setItem(fila, 0, new QTableWidgetItem(partes[0]));
            ui->tableWidget->setItem(fila, 1, new QTableWidgetItem(partes[1]));
            ui->tableWidget->setItem(fila, 2, new QTableWidgetItem(partes[2]));
            ui->tableWidget->setItem(fila, 3, new QTableWidgetItem(partes[3]));
        }
    }
    file.close();
    qDebug() << "Películas cargadas desde:" << rutaArchivo;
}
void MainWindow::guardarPeliculasEnArchivo() {
    QString rutaArchivo = QApplication::applicationDirPath() + "/peliculas.txt";
    QFile file(rutaArchivo);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error al guardar", "No se pudo abrir el archivo de películas para escritura: " + file.errorString());
        qDebug() << "Error al abrir el archivo para escritura:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    int numeroDeFila = ui->tableWidget->rowCount();

    for (int i = 0; i < numeroDeFila; ++i) {
        QString nombre = "";
        QString calificacion = "";
        QString resena = "";
        QString estado = "";

        if (ui->tableWidget->item(i, 0)) {
            nombre = ui->tableWidget->item(i, 0)->text();
        }
        if (ui->tableWidget->item(i, 1)) {
            calificacion = ui->tableWidget->item(i, 1)->text();
        }
        if (ui->tableWidget->item(i, 2)) {
            resena = ui->tableWidget->item(i, 2)->text();
        }
        if (ui->tableWidget->item(i, 3)) {
            estado = ui->tableWidget->item(i, 3)->text();
        }

        out << nombre << "|||" << calificacion << "|||" << resena << "|||" << estado << "\n";
    }
    file.close();
    qDebug() << "Películas guardadas en:" << rutaArchivo;
}
