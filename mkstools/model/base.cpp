#include "base.h"

Base::Base(const QString &name, QObject *parent) :
    QObject(parent)
{
    _name = name;
}

Base::~Base()
{
}

QString Base::name()
{
    return _name;
}
