#include "seccion.h"

Seccion::Seccion(const QString &name, QObject *parent) :
    Base(name, parent)
{
}

Seccion::~Seccion()
{
}

void Seccion::setReporte(const QString &reporte)
{
    _memoriaCalculo = reporte;
}

QString Seccion::reporte()
{
    return _memoriaCalculo;
}
