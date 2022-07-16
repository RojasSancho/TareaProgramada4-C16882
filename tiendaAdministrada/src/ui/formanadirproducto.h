#ifndef FORMANADIRPRODUCTO_H
#define FORMANADIRPRODUCTO_H

#include "producto.h"
#include "tienda.h"
#include <QDialog>

namespace Ui {
class formAnadirProducto;
}

class formAnadirProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formAnadirProducto(QWidget *parent = nullptr);
    ~formAnadirProducto();
    QString nombreTexto();
    QString idNumero();
    QString existenciasNumero();

private slots:

private:
    Ui::formAnadirProducto *ui;
};

#endif // FORMANADIRPRODUCTO_H
