#ifndef CARGAPUNTUAL_H
#define CARGAPUNTUAL_H

#include "solicitacion.h"

class CargaPuntual : public Solicitacion
{
    Q_OBJECT
public:
    explicit CargaPuntual(QObject *parent = 0);

signals:

public slots:


    // IClonable interface
public:
    virtual QSharedPointer<Solicitacion> clone();

    // Solicitacion interface
public:
    virtual double momentoIzquierda(double pos);
    virtual double corteIzquierda(double pos);
    virtual double resultanteX();
    virtual double resultanteY();

private:
    double _fuerzaX;
    double _fuerzaY;
    double _posAplicacion;

    // Solicitacion interface
public:
    virtual void edit();
};

typedef QSharedPointer<CargaPuntual> CargaPuntualPtr;

#endif // CARGAPUNTUAL_H
