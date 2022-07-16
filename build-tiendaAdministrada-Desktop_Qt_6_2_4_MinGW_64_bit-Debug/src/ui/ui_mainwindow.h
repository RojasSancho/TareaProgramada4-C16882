/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *layoutInfoTienda;
    QLineEdit *editNombreTienda;
    QLabel *labelNombreTienda;
    QLabel *labelDireccionInternetTienda;
    QLabel *labelDireccionFisicaTienda;
    QLineEdit *editDireccionFisicaTienda;
    QLabel *labelTelefonoTienda;
    QLineEdit *editTelefonoTienda;
    QLineEdit *editDireccionInternetTienda;
    QLabel *labelTitulo;
    QPushButton *btnNuevoProducto;
    QListWidget *listProductosDeTienda;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 70, 401, 141));
        layoutInfoTienda = new QFormLayout(formLayoutWidget);
        layoutInfoTienda->setObjectName(QString::fromUtf8("layoutInfoTienda"));
        layoutInfoTienda->setContentsMargins(0, 0, 0, 0);
        editNombreTienda = new QLineEdit(formLayoutWidget);
        editNombreTienda->setObjectName(QString::fromUtf8("editNombreTienda"));

        layoutInfoTienda->setWidget(0, QFormLayout::FieldRole, editNombreTienda);

        labelNombreTienda = new QLabel(formLayoutWidget);
        labelNombreTienda->setObjectName(QString::fromUtf8("labelNombreTienda"));

        layoutInfoTienda->setWidget(0, QFormLayout::LabelRole, labelNombreTienda);

        labelDireccionInternetTienda = new QLabel(formLayoutWidget);
        labelDireccionInternetTienda->setObjectName(QString::fromUtf8("labelDireccionInternetTienda"));

        layoutInfoTienda->setWidget(1, QFormLayout::LabelRole, labelDireccionInternetTienda);

        labelDireccionFisicaTienda = new QLabel(formLayoutWidget);
        labelDireccionFisicaTienda->setObjectName(QString::fromUtf8("labelDireccionFisicaTienda"));

        layoutInfoTienda->setWidget(2, QFormLayout::LabelRole, labelDireccionFisicaTienda);

        editDireccionFisicaTienda = new QLineEdit(formLayoutWidget);
        editDireccionFisicaTienda->setObjectName(QString::fromUtf8("editDireccionFisicaTienda"));

        layoutInfoTienda->setWidget(2, QFormLayout::FieldRole, editDireccionFisicaTienda);

        labelTelefonoTienda = new QLabel(formLayoutWidget);
        labelTelefonoTienda->setObjectName(QString::fromUtf8("labelTelefonoTienda"));

        layoutInfoTienda->setWidget(3, QFormLayout::LabelRole, labelTelefonoTienda);

        editTelefonoTienda = new QLineEdit(formLayoutWidget);
        editTelefonoTienda->setObjectName(QString::fromUtf8("editTelefonoTienda"));

        layoutInfoTienda->setWidget(3, QFormLayout::FieldRole, editTelefonoTienda);

        editDireccionInternetTienda = new QLineEdit(formLayoutWidget);
        editDireccionInternetTienda->setObjectName(QString::fromUtf8("editDireccionInternetTienda"));

        layoutInfoTienda->setWidget(1, QFormLayout::FieldRole, editDireccionInternetTienda);

        labelTitulo = new QLabel(centralwidget);
        labelTitulo->setObjectName(QString::fromUtf8("labelTitulo"));
        labelTitulo->setGeometry(QRect(370, 20, 63, 20));
        btnNuevoProducto = new QPushButton(centralwidget);
        btnNuevoProducto->setObjectName(QString::fromUtf8("btnNuevoProducto"));
        btnNuevoProducto->setGeometry(QRect(600, 500, 171, 29));
        listProductosDeTienda = new QListWidget(centralwidget);
        listProductosDeTienda->setObjectName(QString::fromUtf8("listProductosDeTienda"));
        listProductosDeTienda->setGeometry(QRect(20, 230, 751, 251));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelNombreTienda->setText(QCoreApplication::translate("MainWindow", "Nombre:", nullptr));
        labelDireccionInternetTienda->setText(QCoreApplication::translate("MainWindow", "Direcci\303\263n Internet:", nullptr));
        labelDireccionFisicaTienda->setText(QCoreApplication::translate("MainWindow", "Direcci\303\263n F\303\255sica:", nullptr));
        labelTelefonoTienda->setText(QCoreApplication::translate("MainWindow", "Tel\303\251fono:", nullptr));
        labelTitulo->setText(QCoreApplication::translate("MainWindow", "TIENDA", nullptr));
        btnNuevoProducto->setText(QCoreApplication::translate("MainWindow", "A\303\261adir nuevo producto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
