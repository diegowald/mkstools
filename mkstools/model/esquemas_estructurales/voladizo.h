#ifndef VOLADIZO_H
#define VOLADIZO_H

#include "../forward.h"
#include "esquemaestructural.h"
#include <QVarLengthArray>

class Voladizo : public EsquemaEstructural
{
    Q_OBJECT
public:
    explicit Voladizo(QObject *parent = 0);
    ~Voladizo();

    double longitud();
    bool empotramientoUbicadoALaIzquierda();
    void setLongitud(double value);
    void setEmpotramientoUbicadoALaIzquierda(bool value);
signals:

public slots:

    // IClonable interface
public:
    virtual EsquemaEstructuralPtr clone();

    // Base interface
public:
    virtual QString description();

    // EsquemaEstructural interface
public:
    virtual void edit();
    virtual QWidget *getEditWidget();
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
    virtual QGraphicsScene *generarDiagrama(Diagrama diagrama);
    virtual QGraphicsScene *generarDiagrama(Diagrama diagrama, QList<double> &valoresInferiores, QList<double> &valoresSupoeriores,
                                            QList<double> &seccionesArmaduraInferiores, QList<double> &seccionesArmarudaSuperiores);


private:
    double obtenerMinimo(QList<double> &valores);
    double obtenerMaximo(QList<double> &valores);
    double obtenerValor(Diagrama diagrama, int i);

private:
    double _longitud;
    double _reaccionVertical;
    double _reaccionHorizontal;
    double _momentoEmpotramiento;
    bool _empotramientoUbicadoALaIzquierda;
    QVarLengthArray<EsfuerzoInternoPtr, 1024> _esfuerzosInternos;
    int _idMinMomento;
    int _idMaxMomento;
    int _idMinCorte;
    int _idMaxCorte;
};

#endif // VOLADIZO_H
