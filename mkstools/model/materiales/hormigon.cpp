#include "hormigon.h"

Hormigon::Hormigon(QObject *parent) :
    Material("hormigon", parent)
{
    _tensionAdmisibleCompresion = .08;
    _tensionRoturaCompresion = 2.1;
    _tensionAdmisibleTraccion = _tensionAdmisibleCompresion / 10.;
    _tensionRoturaTraccion = _tensionRoturaCompresion / 10.;
}

Hormigon::~Hormigon()
{
}

QSharedPointer<Material> Hormigon::clone()
{
    return HormigonPtr::create();
}

double Hormigon::E() const
{
    return _E;
}


double Hormigon::tensionAdmisibleTraccion() const
{
    return _tensionAdmisibleTraccion;
}

double Hormigon::tensionAdmisibleCompresion() const
{
    return _tensionAdmisibleCompresion;
}

double Hormigon::tensionRoturaTraccion() const
{
    return _tensionRoturaTraccion;
}

double Hormigon::tensionRoturaCompresion() const
{
    return _tensionRoturaCompresion;
}
