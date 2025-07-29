#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include "formview.h"

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
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
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
        }
    } else {
        QMessageBox::warning(this, "Advertencia", "Seleccione una fila para eliminar.");
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
