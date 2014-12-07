#include "dlgeditacero.h"
#include "ui_dlgeditacero.h"

DlgEditMaterial::DlgEditMaterial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEditMaterial)
{
    ui->setupUi(this);
}

DlgEditMaterial::~DlgEditMaterial()
{
    delete ui;
}

void DlgEditMaterial::setTensionTraccion(double value)
{
    ui->txtTensionTraccion->setText(QString::number(value));
}

void DlgEditMaterial::setTensionCompresion(double value)
{
    ui->txtTensionCompresion->setText(QString::number(value));
}

void DlgEditMaterial::setModuloElasticidad(double value)
{
    ui->txtModuloElasticidad->setText(QString::number(value));
}

double DlgEditMaterial::tensionTraccion() const
{
    return ui->txtTensionTraccion->text().toDouble();
}

double DlgEditMaterial::tensionCompresion() const
{
    return ui->txtTensionCompresion->text().toDouble();
}

double DlgEditMaterial::moduloElasticidad() const
{
    return ui->txtModuloElasticidad->text().toDouble();
}
