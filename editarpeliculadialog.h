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

private:
    Ui::EditarPeliculaDialog *ui;
};

#endif // EDITARPELICULADIALOG_H
