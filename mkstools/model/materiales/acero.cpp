#include "acero.h"

Acero::Acero(QObject *parent) :
    Material("acero", parent)
{
    _tensionAdmisibleCompresion = 2.4;
    _tensionAdmisibleTraccion = 2.4;
    _tensionRoturaCompresion = 5.6;
    _tensionRoturaTraccion = 5.6;
    _E = 2100.0;
}

Acero::~Acero()
{
}

QSharedPointer<Material> Acero::clone()
{
    AceroPtr a = AceroPtr::create();
    a->_tensionAdmisibleCompresion = _tensionAdmisibleCompresion;
    a->_tensionAdmisibleTraccion = _tensionAdmisibleTraccion;
    a->_tensionRoturaCompresion = _tensionRoturaCompresion;
    a->_tensionRoturaTraccion = _tensionRoturaTraccion;
    a->_E = _E;
    return a;
}

double Acero::E() const
{
    return _E;
}


double Acero::tensionAdmisibleTraccion() const
{
    return _tensionAdmisibleTraccion;
}

double Acero::tensionAdmisibleCompresion() const
{
    return _tensionAdmisibleCompresion;
}

double Acero::tensionRoturaTraccion() const
{
    return _tensionRoturaTraccion;
}

double Acero::tensionRoturaCompresion() const
{
    return _tensionRoturaTraccion;
}
