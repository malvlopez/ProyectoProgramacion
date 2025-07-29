/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *btnAgregar;
    QPushButton *btnEditar;
    QPushButton *btnEliminar;
    QLabel *label_2;
    QTableWidget *TablaMostrarPelis;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(921, 581);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        btnAgregar = new QPushButton(centralwidget);
        btnAgregar->setObjectName("btnAgregar");

        verticalLayout->addWidget(btnAgregar);

        btnEditar = new QPushButton(centralwidget);
        btnEditar->setObjectName("btnEditar");

        verticalLayout->addWidget(btnEditar);

        btnEliminar = new QPushButton(centralwidget);
        btnEliminar->setObjectName("btnEliminar");

        verticalLayout->addWidget(btnEliminar);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        TablaMostrarPelis = new QTableWidget(centralwidget);
        if (TablaMostrarPelis->columnCount() < 5)
            TablaMostrarPelis->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignBottom);
        TablaMostrarPelis->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TablaMostrarPelis->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TablaMostrarPelis->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TablaMostrarPelis->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TablaMostrarPelis->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        TablaMostrarPelis->setObjectName("TablaMostrarPelis");
        TablaMostrarPelis->setMinimumSize(QSize(695, 0));
        TablaMostrarPelis->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        TablaMostrarPelis->horizontalHeader()->setMinimumSectionSize(180);
        TablaMostrarPelis->horizontalHeader()->setDefaultSectionSize(180);
        TablaMostrarPelis->verticalHeader()->setMinimumSectionSize(140);
        TablaMostrarPelis->verticalHeader()->setDefaultSectionSize(140);

        verticalLayout->addWidget(TablaMostrarPelis);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 921, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700; font-style:italic;\">Bienvenido a</span></p><p align=\"center\"><span style=\" font-size:20pt; font-weight:700; font-style:italic;\">CINETRACK</span></p></body></html>", nullptr));
        btnAgregar->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        btnEditar->setText(QCoreApplication::translate("MainWindow", "Editar", nullptr));
        btnEliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:700;\">Haz click en los encabezados para ordenar </span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TablaMostrarPelis->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TablaMostrarPelis->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Calificaci\303\263n", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TablaMostrarPelis->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Rese\303\261a", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TablaMostrarPelis->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Estado", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TablaMostrarPelis->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Director", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
