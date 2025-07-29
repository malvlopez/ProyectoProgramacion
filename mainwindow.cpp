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
    ui->TablaMostrarPelis->setSortingEnabled(true);
    ui->label->setVisible(true);
    ui->TablaMostrarPelis->setColumnCount(5);
    QStringList headers = {"Nombre", "Calificación", "Reseñas", "Estado", "Director"};
    ui->TablaMostrarPelis->setHorizontalHeaderLabels(headers);
    cargarPeliculasDesdeArchivo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAgregar_clicked()
{
    FormView form(this);
    if (form.exec() == QDialog::Accepted) {
        int fila = ui->TablaMostrarPelis->rowCount();
        ui->TablaMostrarPelis->insertRow(fila);
        ui->TablaMostrarPelis->setItem(fila, 0, new QTableWidgetItem(form.ui->lineEditNombre->text()));
        ui->TablaMostrarPelis->setItem(fila, 1, new QTableWidgetItem(QString::number(form.ui->doubleSpinBoxCalificacion->value())));
        ui->TablaMostrarPelis->setItem(fila, 2, new QTableWidgetItem(form.ui->textEditResena->toPlainText()));
        ui->TablaMostrarPelis->setItem(fila, 3, new QTableWidgetItem(form.ui->comboBoxEstado->currentText()));
        ui->TablaMostrarPelis->setItem(fila, 4, new QTableWidgetItem(form.ui->lineEditDirector->text()));
        guardarPeliculasEnArchivo();
    }
}

void MainWindow::on_btnEditar_clicked()
{
    int fila = ui->TablaMostrarPelis->currentRow();
    if (fila >= 0) {
        FormView form(this);
        form.ui->lineEditNombre->setText(ui->TablaMostrarPelis->item(fila, 0)->text());
        form.ui->doubleSpinBoxCalificacion->setValue(ui->TablaMostrarPelis->item(fila, 1)->text().toDouble());
        form.ui->textEditResena->setPlainText(ui->TablaMostrarPelis->item(fila, 2)->text());
        form.ui->comboBoxEstado->setCurrentText(ui->TablaMostrarPelis->item(fila, 3)->text());
        form.ui->lineEditDirector->setText(ui->TablaMostrarPelis->item(fila, 4)->text());

        if (form.exec() == QDialog::Accepted) {
            ui->TablaMostrarPelis->setItem(fila, 0, new QTableWidgetItem(form.ui->lineEditNombre->text()));
            ui->TablaMostrarPelis->setItem(fila, 1, new QTableWidgetItem(QString::number(form.ui->doubleSpinBoxCalificacion->value())));
            ui->TablaMostrarPelis->setItem(fila, 2, new QTableWidgetItem(form.ui->textEditResena->toPlainText()));
            ui->TablaMostrarPelis->setItem(fila, 3, new QTableWidgetItem(form.ui->comboBoxEstado->currentText()));
            ui->TablaMostrarPelis->setItem(fila, 4, new QTableWidgetItem(form.ui->lineEditDirector->text()));
            guardarPeliculasEnArchivo();
        }
    } else {
        QMessageBox::warning(this, "Advertencia", "Seleccione una película para editar.");
    }
}

void MainWindow::on_btnEliminar_clicked()
{
    int fila = ui->TablaMostrarPelis->currentRow();
    if (fila >= 0) {
        auto respuesta = QMessageBox::question(this, "Eliminar", "¿Desea eliminar esta película?");
        if (respuesta == QMessageBox::Yes) {
            ui->TablaMostrarPelis->removeRow(fila);
            guardarPeliculasEnArchivo();
        }
    } else {
        QMessageBox::warning(this, "Advertencia", "Seleccione una fila para eliminar.");
    }
}

void MainWindow::cargarPeliculasDesdeArchivo()
{
    QString rutaArchivo = QApplication::applicationDirPath() + "/peliculas.txt";
    QFile file(rutaArchivo);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo de películas para lectura:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    ui->TablaMostrarPelis->setRowCount(0);

    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList partes = linea.split("|||");
        if (partes.size() == 5) {
            int fila = ui->TablaMostrarPelis->rowCount();
            ui->TablaMostrarPelis->insertRow(fila);
            for (int i = 0; i < 5; ++i)
                ui->TablaMostrarPelis->setItem(fila, i, new QTableWidgetItem(partes[i]));
        }
    }

    file.close();
}

void MainWindow::guardarPeliculasEnArchivo()
{
    QString rutaArchivo = QApplication::applicationDirPath() + "/peliculas.txt";
    QFile file(rutaArchivo);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error al guardar", "No se pudo abrir el archivo de películas para escritura: " + file.errorString());
        qDebug() << "Error al abrir el archivo para escritura:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    int filas = ui->TablaMostrarPelis->rowCount();

    for (int i = 0; i < filas; ++i) {
        QStringList datos;
        for (int j = 0; j < 5; ++j)
            datos << (ui->TablaMostrarPelis->item(i, j) ? ui->TablaMostrarPelis->item(i, j)->text() : "");
        out << datos.join("|||") << "\n";
    }

    file.close();
}
