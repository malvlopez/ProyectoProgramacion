#include "formview.h"
#include "ui_formview.h"
#include <QDialogButtonBox>

FormView::FormView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FormView)
{
    ui->setupUi(this);

    ui->doubleSpinBoxCalificacion->setMaximum(10);
}

void FormView::setDatos(QString nombre, QString calificacion, QString reseña, QString estado, QString director) {
    ui->lineEditNombre->setText(nombre);
    ui->doubleSpinBoxCalificacion->setValue(calificacion.toInt());
    ui->textEditResena->setPlainText(reseña);
    ui->comboBoxEstado->setCurrentText(estado);
    ui->lineEditDirector->setText(director);
}

QString FormView::getNombre() const {
    return ui->lineEditNombre->text();
}

QString FormView::getCalificacion() const {
    return QString::number(ui->doubleSpinBoxCalificacion->value());
}

QString FormView::getReseña() const {
    return ui->textEditResena->toPlainText();
}

QString FormView::getEstado() const {
    return ui->comboBoxEstado->currentText();
}

QString FormView::getDirector() const {
    return ui->lineEditDirector->text();
}


FormView::~FormView()
{
    delete ui;
}
