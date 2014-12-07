#ifndef PROYECTO_H
#define PROYECTO_H

#include "base.h"
#include "elemento.h"
#include <QMap>

class Proyecto : public Base
{
    Q_OBJECT
public:
    explicit Proyecto(const QString &name, QObject *parent = 0);
    virtual ~Proyecto();

    void addElemento(ElementoPtr elemento);
    void editElemento(const QString &name);
signals:

public slots:

private:
    QMap<QString, ElementoPtr> _elementos;
};

typedef QSharedPointer<Proyecto> ProyectoPtr;

#endif // PROYECTO_H
