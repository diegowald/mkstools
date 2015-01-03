#include "widgeteditvoladizo.h"
#include "ui_widgeteditvoladizo.h"

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
