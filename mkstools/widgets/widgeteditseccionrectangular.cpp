#include "widgeteditseccionrectangular.h"
#include "ui_widgeteditseccionrectangular.h"
#include "../model/secciones/seccionrectangular.h"

WidgetEditSeccionRectangular::WidgetEditSeccionRectangular(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetEditSeccionRectangular)
{
    ui->setupUi(this);
}

WidgetEditSeccionRectangular::~WidgetEditSeccionRectangular()
{
    delete ui;
}

void WidgetEditSeccionRectangular::setBase(double value)
{
    ui->txtBase->setText(QString::number(value));
}

void WidgetEditSeccionRectangular::setAltura(double value)
{
    ui->txtAltura->setText(QString::number(value));
}

void WidgetEditSeccionRectangular::setArmaduraInferior(double value)
{
    ui->txtArmaduraInferior->setText(QString::number(value));
}

void WidgetEditSeccionRectangular::setArmaduraSuperior(double value)
{
    ui->txtArmaduraSuperior->setText(QString::number(value));
}

double WidgetEditSeccionRectangular::base() const
{
    return ui->txtBase->text().toDouble();
}

double WidgetEditSeccionRectangular::altura() const
{
    return ui->txtAltura->text().toDouble();
}

double WidgetEditSeccionRectangular::armaduraInferior() const
{
    return ui->txtArmaduraInferior->text().toDouble();
}

double WidgetEditSeccionRectangular::armaduraSuperior() const
{
    return ui->txtArmaduraSuperior->text().toDouble();
}

void WidgetEditSeccionRectangular::setRecubrimientoInferior(double value)
{
    ui->txtRecubrimientoInferior->setText(QString::number(value));
}

void WidgetEditSeccionRectangular::setRecubrimientoSuperior(double value)
{
    ui->txtRecubrimientoSuperior->setText(QString::number(value));
}

double WidgetEditSeccionRectangular::recubrimientoInferior() const
{
    return ui->txtRecubrimientoInferior->text().toDouble();
}

double WidgetEditSeccionRectangular::recubrimientoSuperior() const
{
    return ui->txtRecubrimientoSuperior->text().toDouble();
}

void WidgetEditSeccionRectangular::setSeccion(SeccionRectangular *seccion)
{
    _seccion = seccion;
    setBase(_seccion->base());
    setAltura(_seccion->altura());
    setArmaduraInferior(_seccion->areaAceroInferior());
    setArmaduraSuperior(_seccion->areaAceroSuperior());
    setRecubrimientoInferior(_seccion->recubrimientoInferior());
    setRecubrimientoSuperior(_seccion->recubrimientoSuperior());
}

void WidgetEditSeccionRectangular::on_txtBase_textEdited(const QString &arg1)
{
    _seccion->setBase(arg1.toDouble());
}

void WidgetEditSeccionRectangular::on_txtAltura_textEdited(const QString &arg1)
{
    _seccion->setAltura(arg1.toDouble());
}

void WidgetEditSeccionRectangular::on_txtArmaduraInferior_textEdited(const QString &arg1)
{
    _seccion->setAreaAceroInferior(arg1.toDouble());
}

void WidgetEditSeccionRectangular::on_txtArmaduraSuperior_textEdited(const QString &arg1)
{
    _seccion->setAreaAceroSuperior(arg1.toDouble());
}

void WidgetEditSeccionRectangular::on_txtRecubrimientoInferior_textEdited(const QString &arg1)
{
    _seccion->setRecubrimientoInferior(arg1.toDouble());
}

void WidgetEditSeccionRectangular::on_txtRecubrimientoSuperior_textEdited(const QString &arg1)
{
    _seccion->setRecubrimientoSuperior(arg1.toDouble());
}
