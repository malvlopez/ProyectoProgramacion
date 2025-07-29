#include "editarpeliculadialog.h"
#include "ui_editarpeliculadialog.h"

EditarPeliculaDialog::EditarPeliculaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditarPeliculaDialog)
{
    ui->setupUi(this);
}

EditarPeliculaDialog::~EditarPeliculaDialog()
{
    delete ui;
}

void EditarPeliculaDialog::cargarDatos(const Pelicula &pelicula) {
    ui->lineEditTitulo->setText(pelicula.titulo);
    ui->lineEditDirector->setText(pelicula.director);
    ui->spinBoxAnio->setValue(pelicula.anio.toInt());
    ui->doubleSpinBoxCalificacion->setValue(pelicula.calificacion);
    ui->comboBoxEstado->setCurrentText(pelicula.estado);
}

Pelicula EditarPeliculaDialog::obtenerDatos() const {
    Pelicula p;
    p.titulo = ui->lineEditTitulo->text();
    p.director = ui->lineEditDirector->text();
    p.anio = ui->spinBoxAnio->text();
    p.calificacion = ui->doubleSpinBoxCalificacion->value();
    p.estado = ui->comboBoxEstado->currentText();
    return p;
}
