#ifndef SECCION_H
#define SECCION_H
#include "../base.h"
#include "../IClonable.h"

class Seccion : public Base, public IClonable<Seccion>
{
    Q_OBJECT
public:
    explicit Seccion(const QString &name, QObject *parent = 0);
    virtual ~Seccion();

    virtual double area() = 0;

    virtual void edit() = 0;

    virtual void setReporte(const QString &reporte);
    virtual QString reporte();
signals:

public slots:

protected:
    QString _memoriaCalculo;
};


#endif // SECCION_H
