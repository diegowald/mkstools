#include "hormigonarmado.h"

HormigonArmado::HormigonArmado(QObject *parent) :
    Material("hormigon armado", parent)
{
}

HormigonArmado::~HormigonArmado()
{
}

QSharedPointer<Material> HormigonArmado::clone()
{
    return HormigonArmadoPtr::create();
}

double HormigonArmado::tensionTraccion() const
{
}

double HormigonArmado::tensionCompression() const
{
}

double HormigonArmado::E() const
{
}
