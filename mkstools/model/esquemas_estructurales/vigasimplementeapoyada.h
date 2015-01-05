#ifndef VIGASIMPLEMENTEAPOYADA_H
#define VIGASIMPLEMENTEAPOYADA_H

#include "../forward.h"
#include "esquemaestructural.h"
#include <QVarLengthArray>

class VigaSimplementeApoyada : public EsquemaEstructural, public QEnableSharedFromThis<VigaSimplementeApoyada>
{
    Q_OBJECT
public:
    explicit VigaSimplementeApoyada(QObject *parent = 0);
    virtual ~VigaSimplementeApoyada();

    virtual void edit();
    virtual QWidget *getEditWidget();
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

    void setPosicionApoyoIzquierdo(double posicion);
    void setPosicionApoyoDerecho(double posicion);
    void setLongitud(double value);

    double longitud();
    double posicionApoyoIzquierdo();
    double posicionApoyoDerecho();

    double reaccionVerticalDerecha();
    double reaccionVerticalIzquierda();

private:
    double obtenerMinimo(Diagrama diagrama);
    double obtenerMaximo(Diagrama diagrama);
    double obtenerValor(Diagrama diagrama, int i);
    double obtenerMinimo(QList<double> &valores);
    double obtenerMaximo(QList<double> &valores);

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
    double _posicionApoyoIzquierdo;
    double _posicionApoyoDerecho;

    // Base interface
public:
    virtual QString description();

    // EsquemaEstructural interface
public:
    virtual QGraphicsScene *generarDiagrama(Diagrama diagrama);
    virtual QGraphicsScene *generarDiagrama(Diagrama diagrama,
                                            QList<double> &valoresInferiores,
                                            QList<double> &valoresSupoeriores,
                                            QList<double> &seccionesArmaduraInferiores,
                                            QList<double> &seccionesArmarudaSuperiores);

};


#endif // VIGASIMPLEMENTEAPOYADA_H
