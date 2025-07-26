#include "formview.h"
#include "ui_formview.h"
#include <QDialogButtonBox>

FormView::FormView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormView)
{
    ui->setupUi(this);

    ui->spinBoxCalificacion->setMaximum(10);
}

void FormView::setDatos(QString nombre, QString calificacion, QString reseña, QString estado) {
    ui->lineEditNombre->setText(nombre);
    ui->spinBoxCalificacion->setValue(calificacion.toInt());
    ui->textEditResena->setPlainText(reseña);
    ui->comboBoxEstado->setCurrentText(estado);
}

QString FormView::getNombre() const {
    return ui->lineEditNombre->text();
}

QString FormView::getCalificacion() const {
    return QString::number(ui->spinBoxCalificacion->value());
}

QString FormView::getReseña() const {
    return ui->textEditResena->toPlainText();
}

QString FormView::getEstado() const {
    return ui->comboBoxEstado->currentText();
}


FormView::~FormView()
{
    delete ui;
}
