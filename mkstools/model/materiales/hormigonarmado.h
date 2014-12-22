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

    HormigonPtr hormigon();
    AceroPtr acero();

    void setHormigon(HormigonPtr hormigon);
    void setAcero(AceroPtr acero);
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
    virtual double E() const;
    
    virtual void edit();

    // Base interface
public:
    virtual QString description();

    // Material interface
public:
    virtual double tensionAdmisibleTraccion() const;
    virtual double tensionAdmisibleCompresion() const;
    virtual double tensionRoturaTraccion() const;
    virtual double tensionRoturaCompresion() const;
};


#endif // HORMIGONARMADO_H
