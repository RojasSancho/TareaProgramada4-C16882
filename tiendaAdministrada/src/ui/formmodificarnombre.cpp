#include "formmodificarnombre.h"
#include "ui_formmodificarnombre.h"

formModificarNombre::formModificarNombre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formModificarNombre)
{
    ui->setupUi(this);
    this->setWindowTitle("Modificar Nombre");
}

formModificarNombre::~formModificarNombre()
{
    delete ui;
}

QString formModificarNombre::darNuevoNombre()
{
    return this->ui->editNuevoNombre->text();
}
