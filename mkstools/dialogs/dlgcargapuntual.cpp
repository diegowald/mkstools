#include "dlgcargapuntual.h"
#include "ui_dlgcargapuntual.h"

DlgCargaPuntual::DlgCargaPuntual(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgCargaPuntual)
{
    ui->setupUi(this);
}

DlgCargaPuntual::~DlgCargaPuntual()
{
    delete ui;
}

void DlgCargaPuntual::setPosicion(double value)
{
    ui->txtPosicion->setText(QString::number(value));
}

void DlgCargaPuntual::setFuerzaX(double value)
{
    ui->txtFuerzaX->setText(QString::number(value));
}

void DlgCargaPuntual::setFuerzaY(double value)
{
    ui->txtFuerzaY->setText(QString::number(value));
}

double DlgCargaPuntual::posicion() const
{
    return ui->txtPosicion->text().toDouble();
}

double DlgCargaPuntual::fuerzaX() const
{
    return ui->txtFuerzaX->text().toDouble();
}

double DlgCargaPuntual::fuerzaY() const
{
    return ui->txtFuerzaY->text().toDouble();
}
