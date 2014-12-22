#ifndef SECCIONRECTANGULAR_H
#define SECCIONRECTANGULAR_H

#include "../forward.h"
#include "seccion.h"

class SeccionRectangular : public Seccion
{
    Q_OBJECT
public:
    explicit SeccionRectangular(QObject *parent = 0);
    virtual ~SeccionRectangular();

    double areaAceroInferior() const;
    double areaAceroSuperior() const;
    double base();
    double altura();
    double recubrimientoInferior();
    double recubrimientoSuperior();

    void setAreaAceroInferior(double value);
    void setAreaAceroSuperior(double value);
    void setBase(double value);
    void setAltura(double value);
    void setRecubrimientoInferior(double value);
    void setRecubrimientoSuperior(double value);

signals:

public slots:


    // IClonable interface
public:
    virtual QSharedPointer<Seccion> clone();

    // Seccion interface
public:
    virtual double area();
    virtual void edit();

private:
    double _areaAceroInferior;
    double _areaAceroSuperior;
    double _base;
    double _altura;
    double _recubrimientoInferior;
    double _recubrimientoSuperior;

    // Base interface
public:
    virtual QString description();
};


#endif // SECCIONRECTANGULAR_H
