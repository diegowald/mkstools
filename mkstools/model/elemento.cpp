#include "elemento.h"
#include "../factory.h"
#include "dialogs/dlgnewelement.h"
#include "../model/materiales/material.h"
#include "../model/metodosCalculo/metodocalculo.h"
#include "../model/esquemas_estructurales/esquemaestructural.h"
#include "../model/secciones/seccion.h"

Elemento::Elemento(const QString &name, const QString &tipo, QObject *parent) :
    Base(name, parent)
{
    createInnerElement(tipo);
}

Elemento::Elemento(const QString &name, QObject *parent) :
    Base(name, parent)
{
    _elemento = Factory::crearTipologiaPorDefecto();
}

Elemento::~Elemento()
{
}

void Elemento::createInnerElement(const QString &tipo)
{
    _elemento = Factory::crearTipologia(tipo);
}

void Elemento::edit()
{
    _elemento->edit();
}


QString Elemento::description()
{
    return _elemento.isNull() ? "" : _elemento->description();
}

void Elemento::calcular()
{
    _elemento->calcular();
}

QString Elemento::reporteCalculo()
{
    return _elemento->reporteCalculo();
}

void Elemento::crearReporte(QTextEdit *textEdit)
{
    _elemento->crearReporte(textEdit);
}

QString Elemento::tipo()
{
    return _elemento->tipo();
}

QString Elemento::material()
{
    return _elemento->material()->name();
}

QString Elemento::metodoCalculo()
{
    return _elemento->metodoCalculo()->name();
}

bool Elemento::calculado()
{
    return _elemento->calculoOK();
}

QString Elemento::esquemaEstructural()
{
    return _elemento->esquemaEstructural()->name();
}

QString Elemento::seccion()
{
    return _elemento->seccion()->name();
}

void Elemento::setName(const QString &value)
{
    _name = value;
}

TipologiaPtr Elemento::tipologia()
{
    return _elemento;
}

void Elemento::setTipologia(TipologiaPtr value)
{
    _elemento = value->clone();
}
