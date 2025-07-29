#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "editarpeliculadialog.h" 
#include <QMessageBox>
#include <QTableWidgetItem>
#include "formview.h"

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
    ui->TablaMostrarPelis->horizontalHeader()->setStretchLastSection(true);
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
    }
}

void MainWindow::on_btnEditar_clicked()
{
    int fila = ui->TablaMostrarPelis->currentRow();
    if (fila >= 0) {
        FormView form(this);
        form.ui->lineEditNombre->setText(ui->TablaMostrarPelis->item(fila, 0)->text());
        form.ui->doubleSpinBoxCalificacion->setValue(ui->TablaMostrarPelis->item(fila, 1)->text().toInt());
        form.ui->textEditResena->setPlainText(ui->TablaMostrarPelis->item(fila, 2)->text());
        form.ui->comboBoxEstado->setCurrentText(ui->TablaMostrarPelis->item(fila, 3)->text());
        form.ui->lineEditDirector->setText(ui->TablaMostrarPelis->item(fila, 4)->text());

        if (form.exec() == QDialog::Accepted) {
            ui->TablaMostrarPelis->setItem(fila, 0, new QTableWidgetItem(form.ui->lineEditNombre->text()));
            ui->TablaMostrarPelis->setItem(fila, 1, new QTableWidgetItem(QString::number(form.ui->doubleSpinBoxCalificacion->value())));
            ui->TablaMostrarPelis->setItem(fila, 2, new QTableWidgetItem(form.ui->textEditResena->toPlainText()));
            ui->TablaMostrarPelis->setItem(fila, 3, new QTableWidgetItem(form.ui->comboBoxEstado->currentText()));
            ui->TablaMostrarPelis->setItem(fila, 4, new QTableWidgetItem(form.ui->lineEditDirector->text()));
        }
    } else {
        QMessageBox::warning(this, "Advertencia", "Seleccione una película para editar.");
    }
}

void MainWindow::on_btnEliminar_clicked() {
    int fila = ui->TablaMostrarPelis->currentRow();
    if (fila >= 0){
        auto respuesta = QMessageBox::question(this, "Eliminar", "¿Desea eliminar esta película?");
        if(respuesta == QMessageBox::Yes) {
            ui->TablaMostrarPelis->removeRow(fila);
        }
    } else {
        QMessageBox::warning(this, "Advertencia", "Seleccione una fila para eliminar.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BotonEditar_clicked() {
    int filaSelecccionada = ui->tablaMostrarPelis->currentRow();
    if (filaSeleccionada >= 0 && filaSeleccionada > listaPeliculas.size()) {
        EditarPeliculas dialog(this);
        dialog.cargarDatos(listaPeliculas[filaSeleccionada];
        if (dialog.exec() == QDialog::Accepted) {
            listaPeliculas[filaSeleccionada] = dialog.obtenerDatos();
            on_tablaMostrarPelis();
            QMessageBox::information(this, "Éxito", "Película actualizada");
        }
    }else{
        QMessageBox::warning(this, "Error", "Selecciona una película primero");
    }
}

void MainWindow::on_BotonEliminar_clicked() {
    int filaSeleccionada = ui->tablaMostrarPelis->currentRow();
    if (filaSeleccionada >= 0 && filaSeleccionada < listaPeliculas.size()) {
        QMessageBox::StandardButton confirmacion;
        confirmacion = QMessageBox::question(this, "Confirmar", 
                                          "¿Eliminar esta película?",
                                          QMessageBox::Yes | QMessageBox::No);

        if(confirmacion == QMassageBox::Yes) {
            listaPeliculas.remove(filaSeleccionada);
            on_tablaMostrarPelis();
            QMessageBox::information(this, "Éxito", "Película eliminada");
        }
    }else{
        QMesssageBox::warning(this, "Error", "Selecciona una pelicula primero");
    }
}

         
