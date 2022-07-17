#ifndef FORMMODIFICAREXISTENCIAS_H
#define FORMMODIFICAREXISTENCIAS_H

#include <QDialog>

namespace Ui {
class formmodificarexistencias;
}

class formmodificarexistencias : public QDialog
{
    Q_OBJECT

public:
    explicit formmodificarexistencias(QWidget *parent = nullptr);
    ~formmodificarexistencias();
    QString darNuevasExistencias();
    void cambiarLabelExistenciasActuales(QString existenciasActuales);

private:
    Ui::formmodificarexistencias *ui;
};

#endif // FORMMODIFICAREXISTENCIAS_H
