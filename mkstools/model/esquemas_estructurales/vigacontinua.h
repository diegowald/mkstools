#ifndef VIGACONTINUA_H
#define VIGACONTINUA_H

#include "../forward.h"
#include "esquemaestructural.h"
#include <QVarLengthArray>
#include <eigen3/Eigen/Dense>

typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> Matriz;
typedef Eigen::Matrix<double, Eigen::Dynamic, 1> Vector;

class VigaContinua : public EsquemaEstructural, public QEnableSharedFromThis<VigaContinua>
{
    Q_OBJECT
public:
    explicit VigaContinua(QObject *parent = 0);
    ~VigaContinua();

    void setLongitud(double value);
    void setApoyos(QList<double> &value);

    double longitud();
    QList<double> apoyos();

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
    void armarMatriz(const QList<SolicitacionPtr> &solicitaciones);
    void armarTerminoIndependiente(int i, const QList<SolicitacionPtr> &solicitaciones);
    void armarVigasAisladas();
    void crearViga(int apoyoIzquierdo, int apoyoDerecho);
    void calcularMomentosApoyoPorClapeyron(const QList<SolicitacionPtr> &solicitaciones);
    void calcularReaccionesPorClapeyron();
    QList<SolicitacionPtr> trasladarSolicitaciones(int i, const QList<SolicitacionPtr> &solicitaciones);

    double omega(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones);
    double omegaD(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones);
    double D(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones);
    double omegad(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones);
    double d(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones);
    double calcularMomentoEmpotramientoIzquierdo(const QList<SolicitacionPtr> &solicitaciones);
    double calcularMomentoEmpotramientoDerecho(const QList<SolicitacionPtr> &solicitaciones);

    double obtenerMinimo(QList<double> &valores);
    double obtenerMaximo(QList<double> &valores);
    double obtenerValor(Diagrama diagrama, int i);

private:
    double _longitud;
    QList<double> _apoyos;
    Matriz _matrix;
    Vector _terminoIndependiente;
    QList<double> _momentosApoyos;
    QList<double> _reaccionesVerticales;
    QVector<VigaSimplementeApoyadaPtr> _vigaAislada;
    QVarLengthArray<EsfuerzoInternoPtr, 1024> _esfuerzosInternos;
    int _idMinMomento;
    int _idMinCorte;
    int _idMaxMomento;
    int _idMaxCorte;
};

#endif // VIGACONTINUA_H
