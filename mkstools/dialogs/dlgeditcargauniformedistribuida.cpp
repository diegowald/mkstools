#include "dlgeditcargauniformedistribuida.h"
#include "ui_dlgeditcargauniformedistribuida.h"

DlgEditCargaUniformeDistribuida::DlgEditCargaUniformeDistribuida(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEditCargaUniformeDistribuida)
{
    ui->setupUi(this);
}

DlgEditCargaUniformeDistribuida::~DlgEditCargaUniformeDistribuida()
{
    delete ui;
}

void DlgEditCargaUniformeDistribuida::setPosicionInicial(double value)
{
    ui->txtPosicionInicial->setText(QString::number(value));
}

void DlgEditCargaUniformeDistribuida::setPosicionFinal(double value)
{
    ui->txtPosicionFinal->setText(QString::number(value));
}

void DlgEditCargaUniformeDistribuida::setCargaX(double value)
{
    ui->txtCargaX->setText(QString::number(value));
}

void DlgEditCargaUniformeDistribuida::setCargaY(double value)
{
    ui->txtCargaY->setText(QString::number(value));
}

double DlgEditCargaUniformeDistribuida::posicionInicial() const
{
    return ui->txtPosicionInicial->text().toDouble();
}

double DlgEditCargaUniformeDistribuida::posicionFinal() const
{
    return ui->txtPosicionFinal->text().toDouble();
}

double DlgEditCargaUniformeDistribuida::cargaX() const
{
    return ui->txtCargaX->text().toDouble();
}

double DlgEditCargaUniformeDistribuida::cargaY() const
{
    return ui->txtCargaY->text().toDouble();
}
