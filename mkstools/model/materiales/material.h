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
    virtual double tensionTraccion() const = 0;
    virtual double tensionCompression() const = 0;
    virtual double E() const = 0;

    virtual void edit();

signals:

public slots:

protected:
    double _tensionTraccion;
    double _tensionCompresion;
    double _E;

};


#endif // MATERIAL_H
