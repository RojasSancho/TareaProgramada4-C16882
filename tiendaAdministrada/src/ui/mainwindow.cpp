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
    delete this->tienda;
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
        bool ok;
        bool ok2;
        formProducto.idNumero().toInt(&ok);
        formProducto.existenciasNumero().toInt(&ok2);
        if(!ok || !ok2)
        {
            QMessageBox* msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Atencion");
            msgbox->setText("Los campos de ID y existencias no permiten caracteres diferentes a numeros.");
            msgbox->open();
            return;
        }

        try
        {
            int id = formProducto.idNumero().toInt();
            string nombre = formProducto.nombreTexto().toStdString();
            int existencias = formProducto.existenciasNumero().toInt();

            Producto *producto = new Producto(id, nombre, existencias);
            QString nombreEnQstring = QString::fromStdString(producto->ConsultarNombre());
            QString idEnQString = QString::number(producto->ConsultarID());
            QString productoEnLista = "[" + idEnQString + "]"  + " - " + nombreEnQstring;
            tienda->InsertarProducto(producto);
            this->ui->listProductosDeTienda->addItem(productoEnLista);
        }
        catch (const ExcepcionNumeroNegativo& e)
        {
            QMessageBox* msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Atencion");
            msgbox->setText("Los campos de ID y existencias solo permiten numeros positivos.");
            msgbox->open();
        }
        catch (const ExcepcionDatosVacios& e)
        {
            QMessageBox* msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Atencion");
            msgbox->setText("El campo de nombre no puede dejarse vacio.");
            msgbox->open();
        }
    }
}

void MainWindow::on_btnEliminarProducto_clicked()
{
    try{
        int numeroDeFilaProducto = this->ui->listProductosDeTienda->currentRow();
        this->tienda->EliminarProducto(numeroDeFilaProducto);

        QListWidgetItem *item = this->ui->listProductosDeTienda->currentItem();
        delete item;
        this->ui->listProductosDeTienda->clearSelection(); //Para que cuando se elimine un producto no se seleccione otro de la lista automaticamente
    }
    catch(const ExcepcionNumeroNegativo& e)
    {
        QMessageBox* msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Atencion");
        msgbox->setText("Debe seleccionar un producto de la lista para eliminar.");
        msgbox->open();
        return;
    }
}

void MainWindow::on_btnModificarNombreProducto_clicked()
{
    if(this->ui->listProductosDeTienda->currentItem() == NULL)
    {
        QMessageBox* msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Atencion");
        msgbox->setText("Debe seleccionar un producto de la lista para modificar.");
        msgbox->open();
        return;
    }

    formModificarNombre formNuevoNombre = formModificarNombre(this);
    int resultNuevoNombre = formNuevoNombre.exec();

    if(resultNuevoNombre == QDialog::Accepted)
    {
        try
        {
            int numeroDeFilaProducto = this->ui->listProductosDeTienda->currentRow();
            Producto *producto = this->tienda->BuscarProductoPorPosicion(numeroDeFilaProducto);
            string nuevoNombre = formNuevoNombre.darNuevoNombre().toStdString();
            producto->CambiarNombre(nuevoNombre);

            QString idProducto = QString::number(producto->ConsultarID());
            QString nuevoNombreQString = QString::fromStdString(nuevoNombre);

            QString productoEnLista = "[" + idProducto + "]"  + " - " + nuevoNombreQString;
            this->ui->listProductosDeTienda->currentItem()->setText(productoEnLista);
        }
        catch(const ExcepcionDatosVacios& e)
        {
            QMessageBox* msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Atencion");
            msgbox->setText("El campo para el nuevo nombre no puede dejarse vacio.");
            msgbox->open();
        }
    }
}

void MainWindow::on_btnExistenciasProducto_clicked()
{
    if(this->ui->listProductosDeTienda->currentItem() == NULL)
    {
        QMessageBox* msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Atencion");
        msgbox->setText("Debe seleccionar un producto de la lista para modificar.");
        msgbox->open();
        return;
    }

    formmodificarexistencias formModificarExistencias = formmodificarexistencias(this);
    int numeroDeFilaProducto = this->ui->listProductosDeTienda->currentRow();
    Producto *producto = this->tienda->BuscarProductoPorPosicion(numeroDeFilaProducto);
    QString existenciasActuales = QString::number(producto->ConsultarNumeroDeExistencias());
    formModificarExistencias.cambiarLabelExistenciasActuales(existenciasActuales);

    int resultNuevasExistencias = formModificarExistencias.exec();

    if(resultNuevasExistencias == QDialog::Accepted)
    {
        bool ok;
        formModificarExistencias.darNuevasExistencias().toInt(&ok);
        if(!ok)
        {
            QMessageBox* msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Atencion");
            msgbox->setText("El campo para las nuevas existencias no permite caracteres diferentes a números.");
            msgbox->open();
            return;
        }

        try
        {
            int nuevasExistencias = formModificarExistencias.darNuevasExistencias().toInt();
            producto->CambiarNumeroDeExistencias(nuevasExistencias);
        }
        catch(const ExcepcionNumeroNegativo& e)
        {
            QMessageBox* msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Atencion");
            msgbox->setText("El campo para las nuevas existencias solo permite números positivos.");
            msgbox->open();
        }
    }
}

