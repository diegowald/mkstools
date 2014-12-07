#ifndef ACERO_H
#define ACERO_H

#include "material.h"

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
    virtual double tensionTraccion() const;
    virtual double tensionCompression() const;
    virtual double E() const;

};

typedef QSharedPointer<Acero> AceroPtr;

#endif // ACERO_H
