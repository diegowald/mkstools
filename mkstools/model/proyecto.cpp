#include "proyecto.h"
#include <QDebug>


Proyecto::Proyecto(const QString &name, QObject *parent) :
    Base(name, parent)
{
}

Proyecto::~Proyecto()
{
}

void Proyecto::addElemento(ElementoPtr elemento)
{
    if (_elementos.contains(elemento->name()))
    {
        qDebug() << "Error, existe un elemento con ese nombre";
    }
    else
    {
        _elementos[elemento->name()] = elemento;
    }
}

void Proyecto::editElemento(const QString &name)
{
    ElementoPtr elemento = _elementos[name];
    elemento->edit();
}
