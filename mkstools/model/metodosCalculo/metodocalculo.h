#ifndef METODOCALCULO_H
#define METODOCALCULO_H

#include "../IClonable.h"
#include "../forward.h"
#include "../base.h"

class MetodoCalculo : public Base, public IClonable<MetodoCalculo>
{
    Q_OBJECT
public:
    explicit MetodoCalculo(const QString &name,
            QObject *parent = 0);
    virtual void init(Tipologia* tipologia,
                      EsquemaEstructuralPtr esquemaEstructural,
                      const QList<SolicitacionPtr> &solicitacion,
                      MaterialPtr material,
                      SeccionPtr seccion);
    virtual void run() = 0;
    virtual QString reporteCalculo() = 0;

signals:

public slots:

protected:
    Tipologia *_tipologia;
    EsquemaEstructuralPtr _esquemaEstructural;
    QList<SolicitacionPtr> _solicitacion;
    MaterialPtr _material;
    SeccionPtr _seccion;

    // Base interface
public:
    virtual QString description();
};

#endif // METODOCALCULO_H
