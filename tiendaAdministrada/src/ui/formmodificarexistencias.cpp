#include "formmodificarexistencias.h"
#include "ui_formmodificarexistencias.h"

formmodificarexistencias::formmodificarexistencias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formmodificarexistencias)
{
    ui->setupUi(this);
}

formmodificarexistencias::~formmodificarexistencias()
{
    delete ui;
}

QString formmodificarexistencias::darNuevasExistencias()
{
    return this->ui->editNuevasExistencias->text();
}

void formmodificarexistencias::cambiarLabelExistenciasActuales(QString existenciasActuales)
{
   this->ui->labelExistenciasActuales->setText(existenciasActuales);
}
