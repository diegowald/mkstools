#ifndef SOLICITACION_H
#define SOLICITACION_H

#include "../base.h"
#include "../IClonable.h"

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
signals:

public slots:

};

typedef QSharedPointer<Solicitacion> SolicitacionPtr;

Q_DECLARE_METATYPE(SolicitacionPtr)

#endif // SOLICITACION_H
