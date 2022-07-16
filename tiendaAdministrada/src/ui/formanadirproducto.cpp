#include "formanadirproducto.h"
#include "ui_formanadirproducto.h"


formAnadirProducto::formAnadirProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formAnadirProducto)
{
    ui->setupUi(this);
    this->setWindowTitle("Nuevo Producto");
}

formAnadirProducto::~formAnadirProducto()
{
    delete ui;
}

int formAnadirProducto::idNumero()
{
    return this->ui->editID->text().toInt();
}

QString formAnadirProducto::nombreText()
{
    return this->ui->editNombre->text();
}

int formAnadirProducto::existenciasNumero()
{
    return this->ui->editExistencias->text().toInt();
}
