#include "dlgeditvoladizo.h"
#include "ui_dlgeditvoladizo.h"

DlgEditVoladizo::DlgEditVoladizo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEditVoladizo)
{
    ui->setupUi(this);
}

DlgEditVoladizo::~DlgEditVoladizo()
{
    delete ui;
}

void DlgEditVoladizo::setLongitud(double value)
{
    ui->txtLongitud->setText(QString::number(value));
}

void DlgEditVoladizo::setEmpotramiento(bool estaALaIzquierda)
{
    ui->radioIzquierda->setChecked(estaALaIzquierda);
    ui->radioDerecha->setChecked(!estaALaIzquierda);
}

double DlgEditVoladizo::longitud()
{
    return ui->txtLongitud->text().toDouble();
}

bool DlgEditVoladizo::empotramientoEstaALaIzquierda()
{
    return ui->radioIzquierda->isChecked();
}
