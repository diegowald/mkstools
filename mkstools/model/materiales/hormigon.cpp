#include "hormigon.h"

Hormigon::Hormigon(QObject *parent) :
    Material("hormigon", parent)
{
}

Hormigon::~Hormigon()
{
}

QSharedPointer<Material> Hormigon::clone()
{
    return HormigonPtr::create();
}

double Hormigon::tensionTraccion() const
{
    return 0.;
}

double Hormigon::tensionCompression() const
{
    return 210.0;
}

double Hormigon::E() const
{
    return 180000.0;
}
