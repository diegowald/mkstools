#ifndef ACERO_H
#define ACERO_H

#include "material.h"
#include "../forward.h"

class Acero : public Material
{
    Q_OBJECT
public:
    explicit Acero(QObject *parent = 0);
    virtual ~Acero();

signals:

public slots:


    // IClonable interface
public:
    virtual QSharedPointer<Material> clone();

    // Material interface
public:
    virtual double E() const;


    // Material interface
public:
    virtual double tensionAdmisibleTraccion() const;
    virtual double tensionAdmisibleCompresion() const;
    virtual double tensionRoturaTraccion() const;
    virtual double tensionRoturaCompresion() const;
};


#endif // ACERO_H
