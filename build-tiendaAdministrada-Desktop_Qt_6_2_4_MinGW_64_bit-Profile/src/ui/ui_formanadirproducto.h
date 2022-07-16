/********************************************************************************
** Form generated from reading UI file 'formanadirproducto.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMANADIRPRODUCTO_H
#define UI_FORMANADIRPRODUCTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formAnadirProducto
{
public:
    QDialogButtonBox *boxbtnGuardarCancelar;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *editID;
    QLabel *labelID;
    QLineEdit *editNombre;
    QLabel *labelNombre;
    QLabel *labelExistencias;
    QLineEdit *editExistencias;

    void setupUi(QDialog *formAnadirProducto)
    {
        if (formAnadirProducto->objectName().isEmpty())
            formAnadirProducto->setObjectName(QString::fromUtf8("formAnadirProducto"));
        formAnadirProducto->resize(400, 300);
        formAnadirProducto->setModal(true);
        boxbtnGuardarCancelar = new QDialogButtonBox(formAnadirProducto);
        boxbtnGuardarCancelar->setObjectName(QString::fromUtf8("boxbtnGuardarCancelar"));
        boxbtnGuardarCancelar->setGeometry(QRect(30, 240, 341, 32));
        boxbtnGuardarCancelar->setOrientation(Qt::Horizontal);
        boxbtnGuardarCancelar->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        formLayoutWidget = new QWidget(formAnadirProducto);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 60, 361, 111));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        editID = new QLineEdit(formLayoutWidget);
        editID->setObjectName(QString::fromUtf8("editID"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editID);

        labelID = new QLabel(formLayoutWidget);
        labelID->setObjectName(QString::fromUtf8("labelID"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelID);

        editNombre = new QLineEdit(formLayoutWidget);
        editNombre->setObjectName(QString::fromUtf8("editNombre"));

        formLayout->setWidget(1, QFormLayout::FieldRole, editNombre);

        labelNombre = new QLabel(formLayoutWidget);
        labelNombre->setObjectName(QString::fromUtf8("labelNombre"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelNombre);

        labelExistencias = new QLabel(formLayoutWidget);
        labelExistencias->setObjectName(QString::fromUtf8("labelExistencias"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelExistencias);

        editExistencias = new QLineEdit(formLayoutWidget);
        editExistencias->setObjectName(QString::fromUtf8("editExistencias"));

        formLayout->setWidget(2, QFormLayout::FieldRole, editExistencias);


        retranslateUi(formAnadirProducto);
        QObject::connect(boxbtnGuardarCancelar, &QDialogButtonBox::accepted, formAnadirProducto, qOverload<>(&QDialog::accept));
        QObject::connect(boxbtnGuardarCancelar, &QDialogButtonBox::rejected, formAnadirProducto, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(formAnadirProducto);
    } // setupUi

    void retranslateUi(QDialog *formAnadirProducto)
    {
        formAnadirProducto->setWindowTitle(QCoreApplication::translate("formAnadirProducto", "Dialog", nullptr));
        labelID->setText(QCoreApplication::translate("formAnadirProducto", "ID:", nullptr));
        labelNombre->setText(QCoreApplication::translate("formAnadirProducto", "Nombre:", nullptr));
        labelExistencias->setText(QCoreApplication::translate("formAnadirProducto", "No. de Existencias:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class formAnadirProducto: public Ui_formAnadirProducto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMANADIRPRODUCTO_H
