#include "widgetvigasimplementeapoyada.h"
#include "ui_widgetvigasimplementeapoyada.h"

WidgetVigaSimplementeApoyada::WidgetVigaSimplementeApoyada(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetVigaSimplementeApoyada)
{
    ui->setupUi(this);
}

WidgetVigaSimplementeApoyada::~WidgetVigaSimplementeApoyada()
{
    delete ui;
}

void WidgetVigaSimplementeApoyada::setLongitud(double value)
{
    ui->lineEdit->setText(QString::number(value));
}

double WidgetVigaSimplementeApoyada::longitud() const
{
    return ui->lineEdit->text().toDouble();
}

void WidgetVigaSimplementeApoyada::setPosicionApoyoIzquierdo(double value)
{
    ui->txtPosicionApoyoIzquierdo->setText(QString::number(value));
}

void WidgetVigaSimplementeApoyada::setPosicionApoyoDerecho(double value)
{
    ui->txtPosicionApoyoDerecho->setText(QString::number(value));
}

double WidgetVigaSimplementeApoyada::posicionApoyoIzquierdo()
{
    return ui->txtPosicionApoyoIzquierdo->text().toDouble();
}

double WidgetVigaSimplementeApoyada::posicinoApoyoDerecho()
{
    return ui->txtPosicionApoyoDerecho->text().toDouble();
}
