#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "pelicula.h"
#include <QMainWindow>
#include <QMessageBox>  
#include <QVector> 
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BotonAgregar_clicked();
    void on_tablaMostrarPelis();
    void on_BotonEditar_clicked();  
    void on_BotonEliminar_clicked();


private:
    Ui::MainWindow *ui;
    vector<pelicula> listaPeliculas;

};
#endif // MAINWINDOW_H
