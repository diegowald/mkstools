#ifndef VIGASIMPLEMENTEAPOYADA_H
#define VIGASIMPLEMENTEAPOYADA_H

#include "../forward.h"
#include "esquemaestructural.h"
#include <QVarLengthArray>

class VigaSimplementeApoyada : public EsquemaEstructural
{
    Q_OBJECT
public:
    explicit VigaSimplementeApoyada(QObject *parent = 0);
    virtual ~VigaSimplementeApoyada();

    virtual void edit();
    virtual EsquemaEstructuralPtr clone();

signals:

public slots:

private:
    double _longitud;

    // EsquemaEstructural interface
public:
    virtual void calcularReacciones(const QList<SolicitacionPtr> &solicitaciones);
    virtual void calcularEsfuerzosInternos(const QList<SolicitacionPtr> &solicitaciones);
    virtual void calcularMaximosEsfuerzos();

    virtual double minMomento() const;
    virtual double posMinMomento() const;
    virtual double maxMomento() const;
    virtual double posMaxMomento() const;
    virtual double maxCorte() const;
    virtual double posMinCorte() const;
    virtual double minCorte() const;
    virtual double posMaxCorte() const;

    virtual QVarLengthArray<EsfuerzoInternoPtr, 1024> esfuerzosInternos();
    virtual QString reporteCalculo();

private:
    double _reaccionVerticalA;
    double _reaccionHorizontalA;
    double _reaccionVerticalB;
    double _reaccionHorizontalB;
    QVarLengthArray<EsfuerzoInternoPtr, 1024> _esfuerzosInternos;
    int _idMinMomento;
    int _idMaxMomento;
    int _idMinCorte;
    int _idMaxCorte;

    // Base interface
public:
    virtual QString description();
};


#endif // VIGASIMPLEMENTEAPOYADA_H
