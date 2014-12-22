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

void DlgEditMaterial::setTensionAdmisibleCompresion(double value)
{
    ui->txtTensionAdmisibleCompresion->setText(QString::number(value));
}

void DlgEditMaterial::setTensionAdmisibleTraccion(double value)
{
    ui->txtTensionAdmisibleTraccion->setText(QString::number(value));
}

void DlgEditMaterial::setTensionRoturaCompresion(double value)
{
    ui->txtTensionRoturaCompresion->setText(QString::number(value));
}

void DlgEditMaterial::setTensionRoturaTraccion(double value)
{
    ui->txtTensionRoturaTraccion->setText(QString::number(value));
}

void DlgEditMaterial::setModuloElasticidad(double value)
{
    ui->txtModuloElasticidad->setText(QString::number(value));
}


double DlgEditMaterial::moduloElasticidad() const
{
    return ui->txtModuloElasticidad->text().toDouble();
}

double DlgEditMaterial::tensionAdmisibleCompresion() const
{
    return ui->txtTensionAdmisibleCompresion->text().toDouble();
}

double DlgEditMaterial::tensionAdmisibleTraccion() const
{
    return ui->txtTensionAdmisibleTraccion->text().toDouble();
}

double DlgEditMaterial::tensionRoturaCompresion() const
{
    return ui->txtTensionRoturaCompresion->text().toDouble();
}

double DlgEditMaterial::tensionRoturaTraccion() const
{
    return ui->txtTensionRoturaTraccion->text().toDouble();
}
