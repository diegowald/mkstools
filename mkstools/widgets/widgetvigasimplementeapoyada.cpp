#include "widgetvigasimplementeapoyada.h"
#include "ui_widgetvigasimplementeapoyada.h"
#include "../model/esquemas_estructurales/vigasimplementeapoyada.h"

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

void WidgetVigaSimplementeApoyada::setViga(VigaSimplementeApoyadaPtr viga)
{
    _viga = viga;
    setLongitud(_viga->longitud());
    setPosicionApoyoIzquierdo(_viga->posicionApoyoIzquierdo());
    setPosicionApoyoDerecho(_viga->posicionApoyoDerecho());
}


void WidgetVigaSimplementeApoyada::on_txtPosicionApoyoIzquierdo_textEdited(const QString &arg1)
{
    (void) arg1;
    _viga->setPosicionApoyoIzquierdo(posicionApoyoIzquierdo());
}

void WidgetVigaSimplementeApoyada::on_lineEdit_textEdited(const QString &arg1)
{
    (void) arg1;
    _viga->setLongitud(longitud());
}


void WidgetVigaSimplementeApoyada::on_txtPosicionApoyoDerecho_textEdited(const QString &arg1)
{
    (void) arg1;
    _viga->setPosicionApoyoDerecho(posicinoApoyoDerecho());
}
