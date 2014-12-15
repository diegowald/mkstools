#ifndef ESQUEMAESTRUCTURAL_H
#define ESQUEMAESTRUCTURAL_H

#include "../base.h"
#include "../IClonable.h"
#include "../forward.h"

class EsquemaEstructural : public Base, public IClonable<EsquemaEstructural>
{
    Q_OBJECT
public:
    explicit EsquemaEstructural(const QString &name, QObject *parent = 0);
    virtual ~EsquemaEstructural();
    virtual void edit() = 0;

    virtual void calcularReacciones(const QList<SolicitacionPtr> &solicitaciones) = 0;
    virtual void calcularEsfuerzosInternos(const QList<SolicitacionPtr> &solicitaciones) = 0;
    virtual void calcularMaximosEsfuerzos() = 0;

    virtual double minMomento() const = 0;
    virtual double posMinMomento() const = 0;
    virtual double maxMomento() const = 0;
    virtual double posMaxMomento() const = 0;
    virtual double maxCorte() const = 0;
    virtual double posMinCorte() const = 0;
    virtual double minCorte() const = 0;
    virtual double posMaxCorte() const = 0;

    virtual QVarLengthArray<EsfuerzoInternoPtr, 1024> esfuerzosInternos() = 0;
signals:

public slots:

protected:

};


#endif // ESQUEMAESTRUCTURAL_H
