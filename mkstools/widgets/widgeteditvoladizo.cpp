#include "widgeteditvoladizo.h"
#include "ui_widgeteditvoladizo.h"
#include "../model/esquemas_estructurales/voladizo.h"

WidgetEditVoladizo::WidgetEditVoladizo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetEditVoladizo)
{
    ui->setupUi(this);
}

WidgetEditVoladizo::~WidgetEditVoladizo()
{
    delete ui;
}

void WidgetEditVoladizo::setLongitud(double value)
{
    ui->txtLongitud->setText(QString::number(value));
}

void WidgetEditVoladizo::setEmpotramiento(bool estaALaIzquierda)
{
    ui->radioIzquierda->setChecked(estaALaIzquierda);
    ui->radioDerecha->setChecked(!estaALaIzquierda);
}

double WidgetEditVoladizo::longitud()
{
    return ui->txtLongitud->text().toDouble();
}

bool WidgetEditVoladizo::empotramientoEstaALaIzquierda()
{
    return ui->radioIzquierda->isChecked();
}

void WidgetEditVoladizo::on_txtLongitud_textEdited(const QString &arg1)
{
    _viga->setLongitud(arg1.toDouble());
}

void WidgetEditVoladizo::setViga(Voladizo *viga)
{
    _viga = viga;
    setLongitud(_viga->longitud());
    setEmpotramiento(_viga->empotramientoUbicadoALaIzquierda());
}

void WidgetEditVoladizo::on_radioIzquierda_toggled(bool checked)
{
    _viga->setEmpotramientoUbicadoALaIzquierda(empotramientoEstaALaIzquierda());
}
