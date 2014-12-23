#include "elemento.h"
#include "../factory.h"

Elemento::Elemento(const QString &name, const QString &tipo, QObject *parent) :
    Base(name, parent)
{
    _tipo = tipo;
    createInnerElement();
}

Elemento::~Elemento()
{
}

void Elemento::createInnerElement()
{
    _elemento = Factory::crearTipologia(_tipo);
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

QString Elemento::tipo()
{
    return _elemento->tipo();
}

QString Elemento::material()
{
    return _elemento->material();
}

QString Elemento::metodoCalculo()
{
    return _elemento->metodoCalculo();
}

bool Elemento::calculado()
{
    return _elemento->calculoOK();
}

QString Elemento::esquemaEstructural()
{
    return _elemento->esquemaEstructural();
}

QString Elemento::seccion()
{
    return _elemento->seccion();
}
