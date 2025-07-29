#include "editarpeliculadialog.h"
#include "ui_editarpeliculadialog.h"
#include <QMessageBox>  

EditarPeliculaDialog::EditarPeliculaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditarPeliculaDialog),
    m_debeEliminar(false)  
{
    ui->setupUi(this);
}

EditarPeliculaDialog::~EditarPeliculaDialog()
{
    delete ui;
}


bool EditarPeliculaDialog::debeEliminar() const
{
    return m_debeEliminar;
}

void EditarPeliculaDialog::on_btnEliminar_clicked()
{
    QMessageBox::StandardButton respuesta;
    respuesta = QMessageBox::question(this, 
                                    "Confirmar eliminación",
                                    "¿Estás seguro de eliminar esta película?",
                                    QMessageBox::Yes|QMessageBox::No);
    
    if(respuesta == QMessageBox::Yes) {
        m_debeEliminar = true;
        this->accept();
    }
}

void EditarPeliculaDialog::on_btnGuardar_clicked()
{
    if(ui->lineEditTitulo->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Error", "El título no puede estar vacío");
        return;
    }
    this->accept();
}


void EditarPeliculaDialog::cargarDatos(const Pelicula &pelicula) {
    
}

Pelicula EditarPeliculaDialog::obtenerDatos() const {
   
}
