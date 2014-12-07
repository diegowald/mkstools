#include "viga.h"

Viga::Viga(const QString &name, QObject *parent) :
    Tipologia(name, parent)
{
}

Viga::~Viga()
{
}

QStringList Viga::getValidSeccionTypes()
{
    return QStringList()
            << "rectangular"
            << "placa";
}

QStringList Viga::getValidEsquemaEstructuralTypes()
{
    return QStringList()
            << "simplemente apoyada"
            << "voladizo"
            << "continua";
}
