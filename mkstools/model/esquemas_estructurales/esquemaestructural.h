#ifndef ESQUEMAESTRUCTURAL_H
#define ESQUEMAESTRUCTURAL_H

#include "../base.h"
#include "../IClonable.h"
#include "../solicitaciones/solicitacion.h"

class EsquemaEstructural : public Base, public IClonable<EsquemaEstructural>
{
    Q_OBJECT
public:
    explicit EsquemaEstructural(const QString &name, QObject *parent = 0);
    virtual ~EsquemaEstructural();
    virtual void edit() = 0;

signals:

public slots:

protected:
    QList<SolicitacionPtr> _solicitaciones;

};

typedef QSharedPointer<EsquemaEstructural> EsquemaEstructuralPtr;

#endif // ESQUEMAESTRUCTURAL_H
