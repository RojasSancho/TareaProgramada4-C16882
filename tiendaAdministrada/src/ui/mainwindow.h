#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tienda.h"
#include "formanadirproducto.h"
#include "formmodificarnombre.h"
#include "formmodificarexistencias.h"
#include "producto.h"
#include "excepcionNumeroNegativo.h"
#include "excepcionCaracterNoEsNumero.h"
#include "excepcionDatosVacios.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_editNombreTienda_editingFinished();

    void on_editDireccionInternetTienda_editingFinished();

    void on_editDireccionFisicaTienda_cursorPositionChanged(int arg1, int arg2);

    void on_editTelefonoTienda_editingFinished();

    void on_editDireccionFisicaTienda_editingFinished();

    void on_btnNuevoProducto_clicked();

    void on_btnEliminarProducto_clicked();

    void on_btnModificarNombreProducto_clicked();

    void on_btnExistenciasProducto_clicked();

    void on_btnGuardarEnArchivo_clicked();

    void on_btnCargarDesdeArchivo_clicked();

private:
    Ui::MainWindow *ui;
    Tienda *tienda = new Tienda();

};
#endif // MAINWINDOW_H
