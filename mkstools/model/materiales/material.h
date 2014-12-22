#ifndef MATERIAL_H
#define MATERIAL_H
#include "../base.h"
#include "../IClonable.h"

class Material : public Base, public IClonable<Material>
{
    Q_OBJECT
public:
    explicit Material(const QString &name, QObject *parent = 0);
    virtual ~Material();

    virtual double tensionAdmisibleTraccion() const = 0;
    virtual double tensionAdmisibleCompresion() const = 0;

    virtual double tensionRoturaTraccion() const = 0;
    virtual double tensionRoturaCompresion() const = 0;

    virtual double E() const = 0;


    virtual void edit();

signals:

public slots:

protected:
    double _tensionAdmisibleTraccion;
    double _tensionAdmisibleCompresion;
    double _tensionRoturaTraccion;
    double _tensionRoturaCompresion;

    double _E;


    // Base interface
public:
    virtual QString description();
};


#endif // MATERIAL_H
