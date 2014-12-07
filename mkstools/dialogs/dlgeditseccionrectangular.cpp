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
