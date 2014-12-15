#ifndef TIPOLOGIA_H
#define TIPOLOGIA_H

#include "../forward.h"
#include "../base.h"

class Tipologia : public Base
{
    Q_OBJECT
public:
    explicit Tipologia(const QString &name, QObject *parent = 0);
    virtual ~Tipologia();
    virtual void edit();
    virtual QStringList getValidSeccionTypes() = 0;
    virtual QStringList getValidEsquemaEstructuralTypes() = 0;
signals:

public slots:

protected:
    QString _tipoSeccion;
    SeccionPtr _seccion;
    QString _tipoEsquema;
    EsquemaEstructuralPtr _esquemaEstructural;
    QList<SolicitacionPtr> _solicitaciones;
};


#endif // TIPOLOGIA_H
