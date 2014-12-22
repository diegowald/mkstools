#ifndef HORMIGON_H
#define HORMIGON_H

#include "material.h"
#include "../forward.h"

class Hormigon : public Material
{
    Q_OBJECT
public:
    explicit Hormigon(QObject *parent = 0);
    virtual ~Hormigon();

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


#endif // HORMIGON_H
