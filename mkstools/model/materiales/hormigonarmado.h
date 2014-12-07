#ifndef HORMIGONARMADO_H
#define HORMIGONARMADO_H

#include "material.h"
#include "hormigon.h"
#include "acero.h"

class HormigonArmado : public Material
{
    Q_OBJECT
public:
    explicit HormigonArmado(QObject *parent = 0);
    virtual ~HormigonArmado();
signals:

public slots:

private:
    HormigonPtr _hormigon;
    AceroPtr _acero;

    // IClonable interface
public:
    virtual QSharedPointer<Material> clone();

    // Material interface
public:
    virtual double tensionTraccion() const;
    virtual double tensionCompression() const;
    virtual double E() const;
};

typedef QSharedPointer<HormigonArmado> HormigonArmadoPtr;

#endif // HORMIGONARMADO_H
