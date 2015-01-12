#ifndef HAMETODOCLASICO_H
#define HAMETODOCLASICO_H

#include "metodocalculo.h"
#include <functional>

class HAMetodoClasico : public MetodoCalculo
{
    Q_OBJECT
public:
    HAMetodoClasico(QObject *parent = 0);

signals:

public slots:


    // MetodoCalculo interface
public:
    virtual void run();
    virtual QString reporteCalculo();
    virtual void crearReporte(QTextEdit *textEdit);
    virtual bool calculado();
    virtual QGraphicsScene *generarDiagrama(Diagrama diagrama,
                                            QList<double> &armadurasInferiores,
                                            QList<double> &armadurasSuperiores);

protected:
    double inversa(double xMin, double xMax, double value, std::function<double(double)> func);
    bool aproximadamenteIgual(double valor1, double valor2);
    bool between(double value, double value1, double value2);
private:
    bool calcularViga();

    void predimensionarViga();
    void calcularSolicitaciones();
    void calcularReacciones();
    void calcularEsfuerzosInternos();
    void calcularMaximosEsfuerzos();
    void verificacionSecciones();
    SeccionPtr verificarUsandoTabla56(double momento);

    static double k1Tabla42(double m);
    static double k4Tabla42(double m);
    static double kxTabla42(double m);

    static double kxTabla56(double sb);
    static double kzTabla56(double sb);
    static double k2Tabla56(double sb);
    static double k3Tabla56(double sb);
    static double k4Tabla56(double sb);
    static double k6Tabla56(double sb);

    // IClonable interface
public:
    virtual QSharedPointer<MetodoCalculo> clone();

private:
    QList<SeccionPtr> _seccionesCalculadas;
    SeccionPtr _seccionMayorArmaduraInferior;
    SeccionPtr _seccionMenorArmaduraInferior;
    SeccionPtr _seccionMayorArmaduraSuperior;
    SeccionPtr _seccionMenorArmaduraSuperior;
    bool _calculado;
};

#endif // HAMETODOCLASICO_H
