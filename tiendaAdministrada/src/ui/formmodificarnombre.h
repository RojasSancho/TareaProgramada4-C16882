#ifndef FORMMODIFICARNOMBRE_H
#define FORMMODIFICARNOMBRE_H

#include <QDialog>

namespace Ui {
class formModificarNombre;
}

class formModificarNombre : public QDialog
{
    Q_OBJECT

public:
    explicit formModificarNombre(QWidget *parent = nullptr);
    ~formModificarNombre();
    QString darNuevoNombre();

private:
    Ui::formModificarNombre *ui;
};

#endif // FORMMODIFICARNOMBRE_H
