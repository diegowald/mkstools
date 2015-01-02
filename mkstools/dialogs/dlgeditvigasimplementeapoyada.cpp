#include "dlgeditvigasimplementeapoyada.h"
#include "ui_dlgeditvigasimplementeapoyada.h"

DlgEditVigaSimplementeApoyada::DlgEditVigaSimplementeApoyada(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEditVigaSimplementeApoyada)
{
    ui->setupUi(this);
}

DlgEditVigaSimplementeApoyada::~DlgEditVigaSimplementeApoyada()
{
    delete ui;
}

void DlgEditVigaSimplementeApoyada::setLongitud(double value)
{
    ui->lineEdit->setText(QString::number(value));
}

double DlgEditVigaSimplementeApoyada::longitud() const
{
    return ui->lineEdit->text().toDouble();
}

void DlgEditVigaSimplementeApoyada::setPosicionApoyoIzquierdo(double value)
{
    ui->txtPosicionApoyoIzquierdo->setText(QString::number(value));
}

void DlgEditVigaSimplementeApoyada::setPosicionApoyoDerecho(double value)
{
    ui->txtPosicionApoyoDerecho->setText(QString::number(value));
}

double DlgEditVigaSimplementeApoyada::posicionApoyoIzquierdo()
{
    return ui->txtPosicionApoyoIzquierdo->text().toDouble();
}

double DlgEditVigaSimplementeApoyada::posicinoApoyoDerecho()
{
    return ui->txtPosicionApoyoDerecho->text().toDouble();
}
