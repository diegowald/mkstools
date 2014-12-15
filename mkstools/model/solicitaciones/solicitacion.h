#ifndef SOLICITACION_H
#define SOLICITACION_H

#include "../IClonable.h"
#include "../forward.h"
#include "../base.h"

class Solicitacion : public Base, public IClonable<Solicitacion>
{
    Q_OBJECT
public:
    explicit Solicitacion(const QString &name, QObject *parent = 0);
    virtual ~Solicitacion();
    virtual double momentoIzquierda(double pos) = 0; // Calcula el momento hacia la izquierda
    virtual double corteIzquierda(double pos) = 0;
    virtual double resultanteX() = 0;
    virtual double resultanteY() = 0;
    virtual void edit() = 0;

    virtual void calcularSolicitacion(SeccionPtr seccion, EsquemaEstructuralPtr esquemaEstructural) = 0;

signals:

public slots:

};


Q_DECLARE_METATYPE(SolicitacionPtr)

#endif // SOLICITACION_H
