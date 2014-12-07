#ifndef HORMIGON_H
#define HORMIGON_H

#include "material.h"

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
    virtual double tensionTraccion() const;
    virtual double tensionCompression() const;
    virtual double E() const;
};

typedef QSharedPointer<Hormigon> HormigonPtr;

#endif // HORMIGON_H
