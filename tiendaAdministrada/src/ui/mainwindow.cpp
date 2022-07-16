#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tienda");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_editNombreTienda_editingFinished()
{
    QString qstringNombre = this->ui->editNombreTienda->text();
    string nombreTienda = qstringNombre.toStdString();
    this->tienda->CambiarNombre(nombreTienda);
}

void MainWindow::on_editDireccionInternetTienda_editingFinished()
{
    QString qstringDireccionInternet = this->ui->editDireccionInternetTienda->text();
    string direccionInternetTienda = qstringDireccionInternet.toStdString();
    this->tienda->CambiarDireccionInternet(direccionInternetTienda);
}

void MainWindow::on_editDireccionFisicaTienda_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::on_editTelefonoTienda_editingFinished()
{
    QString qstringTelefono = this->ui->editTelefonoTienda->text();
    string telefonoTienda = qstringTelefono.toStdString();
    this->tienda->CambiarTelefono(telefonoTienda);
}


void MainWindow::on_editDireccionFisicaTienda_editingFinished()
{
    QString qstringDireccionFisica = this->ui->editDireccionFisicaTienda->text();
    string direccionFisicaTienda = qstringDireccionFisica.toStdString();
    this->tienda->CambiarDireccionFisica(direccionFisicaTienda);
}


void MainWindow::on_btnNuevoProducto_clicked()
{
    formAnadirProducto formProducto = formAnadirProducto(this);
    int result = formProducto.exec();

    if(result == QDialog::Accepted)
    {
        int id = formProducto.idNumero();
        string nombre = formProducto.nombreText().toStdString();
        int existencias = formProducto.existenciasNumero();

        Producto *producto = new Producto(id, nombre, existencias);
        QString nombreEnQstring = QString::fromStdString(producto->ConsultarNombre());
        this->ui->listProductosDeTienda->addItem(nombreEnQstring);
    }
}
