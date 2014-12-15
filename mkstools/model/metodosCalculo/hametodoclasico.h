#ifndef HAMETODOCLASICO_H
#define HAMETODOCLASICO_H

#include "metodocalculo.h"
#include <functional>

class HAMetodoClasico : public MetodoCalculo
{
    Q_OBJECT
public:
    explicit HAMetodoClasico(TipologiaPtr tipologia,
                             EsquemaEstructuralPtr esquemaEstructural,
                             const QList<SolicitacionPtr> &solicitacion,
                             MaterialPtr material,
                             SeccionPtr seccion,
                             QObject *parent = 0);


signals:

public slots:


    // MetodoCalculo interface
public:
    virtual void run();

protected:
    double inversa(double xMin, double xMax, double value, std::function<double(double)> func);
    bool between(double value, double value1, double value2);
private:
    void calcularViga();

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
};

#endif // HAMETODOCLASICO_H
