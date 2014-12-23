#ifndef TIPOLOGIA_H
#define TIPOLOGIA_H

#include "../forward.h"
#include "../base.h"
#include "../IClonable.h"

class Tipologia : public Base, public IClonable<Tipologia>, public QEnableSharedFromThis<Tipologia>
{
    Q_OBJECT
public:
    explicit Tipologia(const QString &name, QObject *parent = 0);
    virtual ~Tipologia();
    virtual void edit();
    virtual QStringList getValidSeccionTypes() = 0;
    virtual QStringList getValidEsquemaEstructuralTypes() = 0;
    virtual void calcular() = 0;
    virtual QString reporteCalculo();

    virtual QString tipo();
    virtual QString material();
    virtual QString metodoCalculo();
    virtual bool calculoOK();
    virtual QString esquemaEstructural();
    virtual QString seccion();
signals:

public slots:

protected:
    QString _tipoSeccion;
    SeccionPtr _seccion;
    QString _tipoEsquema;
    EsquemaEstructuralPtr _esquemaEstructural;
    QList<SolicitacionPtr> _solicitaciones;
    MaterialPtr _material;
    MetodoCalculoPtr _metodoCalculo;

    // Base interface
public:
    virtual QString description();
};


#endif // TIPOLOGIA_H
