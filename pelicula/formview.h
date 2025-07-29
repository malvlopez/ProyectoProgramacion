#ifndef FORMVIEW_H
#define FORMVIEW_H

#include <QDialog>
#include "ui_formview.h"

namespace Ui {
class FormView;
}

class FormView : public QDialog
{
    Q_OBJECT

public:
    explicit FormView(QWidget *parent = nullptr);
    ~FormView();

    QString getNombre() const;
    QString getCalificacion() const;
    QString getReseña() const;
    QString getEstado() const;

    void setDatos(QString nombre, QString calificacion, QString resena, QString estado);

public:
    Ui::FormView *ui;

};

#endif // FORMVIEW_H
