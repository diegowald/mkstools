#include "dlgeditseccionrectangular.h"
#include "ui_dlgeditseccionrectangular.h"

DlgEditSeccionRectangular::DlgEditSeccionRectangular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEditSeccionRectangular)
{
    ui->setupUi(this);
}

DlgEditSeccionRectangular::~DlgEditSeccionRectangular()
{
    delete ui;
}

void DlgEditSeccionRectangular::setBase(double value)
{
    ui->txtBase->setText(QString::number(value));
}

void DlgEditSeccionRectangular::setAltura(double value)
{
    ui->txtAltura->setText(QString::number(value));
}

void DlgEditSeccionRectangular::setArmaduraInferior(double value)
{
    ui->txtArmaduraInferior->setText(QString::number(value));
}

void DlgEditSeccionRectangular::setArmaduraSuperior(double value)
{
    ui->txtArmaduraSuperior->setText(QString::number(value));
}

double DlgEditSeccionRectangular::base() const
{
    return ui->txtBase->text().toDouble();
}

double DlgEditSeccionRectangular::altura() const
{
    return ui->txtAltura->text().toDouble();
}

double DlgEditSeccionRectangular::armaduraInferior() const
{
    return ui->txtArmaduraInferior->text().toDouble();
}

double DlgEditSeccionRectangular::armaduraSuperior() const
{
    return ui->txtArmaduraSuperior->text().toDouble();
}

void DlgEditSeccionRectangular::setRecubrimientoInferior(double value)
{
    ui->txtRecubrimientoInferior->setText(QString::number(value));
}

void DlgEditSeccionRectangular::setRecubrimientoSuperior(double value)
{
    ui->txtRecubrimientoSuperior->setText(QString::number(value));
}

double DlgEditSeccionRectangular::recubrimientoInferior() const
{
    return ui->txtRecubrimientoInferior->text().toDouble();
}

double DlgEditSeccionRectangular::recubrimientoSuperior() const
{
    return ui->txtRecubrimientoSuperior->text().toDouble();
}
