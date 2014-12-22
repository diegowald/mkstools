#ifndef CARGAUNIFORMECONSTANTE_H
#define CARGAUNIFORMECONSTANTE_H

#include "solicitacion.h"

class CargaUniformeConstante : public Solicitacion
{
    Q_OBJECT
public:
    explicit CargaUniformeConstante(QObject *parent = 0);

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
    virtual void edit();

private:
    double _cargaX;
    double _cargaY;
    double _posInicio;
    double _posFinal;

    // Solicitacion interface
public:
    virtual void calcularSolicitacion(SeccionPtr seccion, EsquemaEstructuralPtr esquemaEstructural);

    // Base interface
public:
    virtual QString description();
};


#endif // CARGAUNIFORMECONSTANTE_H
