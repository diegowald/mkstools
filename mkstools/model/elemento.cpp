#include "elemento.h"
#include "tipologias/viga.h"

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
    if (_tipo == "viga")
    {
        _elemento = VigaPtr::create(name());
    }
}

void Elemento::edit()
{
    _elemento->edit();
}
