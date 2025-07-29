#ifndef EDITARPELICULADIALOG_H
#define EDITARPELICULADIALOG_H

#include <QDialog>
#include "pelicula.h"

namespace Ui {
class EditarPeliculaDialog;
}

class EditarPeliculaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditarPeliculaDialog(QWidget *parent = nullptr);
    ~EditarPeliculaDialog();

    void cargarDatos(const Pelicula &pelicula);
    Pelicula obtenerDatos() const;
    bool debeEliminar() const;  

private slots:
    void on_btnGuardar_clicked();  
    void on_btnEliminar_clicked(); 

private:
    Ui::EditarPeliculaDialog *ui;
    bool m_debeEliminar = false;  
};

#endif // EDITARPELICULADIALOG_H
