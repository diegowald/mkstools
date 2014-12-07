#include "acero.h"

Acero::Acero(QObject *parent) :
    Material("acero", parent)
{
}

Acero::~Acero()
{
}

QSharedPointer<Material> Acero::clone()
{
    AceroPtr a = AceroPtr::create();
    a->_tensionCompresion = _tensionCompresion;
    a->_tensionTraccion = _tensionTraccion;
    a->_E = _E;
    return a;
}

double Acero::tensionTraccion() const
{
    return _tensionTraccion;
}

double Acero::tensionCompression() const
{
    return _tensionCompresion;
}

double Acero::E() const
{
    return _E;
}
