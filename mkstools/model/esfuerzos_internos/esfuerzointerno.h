#ifndef ESFUERZOINTERNO_H
#define ESFUERZOINTERNO_H

#include <QObject>
#include "../base.h"

class EsfuerzoInterno : public Base
{
    Q_OBJECT
public:
    EsfuerzoInterno(QObject *parent = 0);
    ~EsfuerzoInterno();

    void setMomento(double value);
    void setNormal(double value);
    void setCorte(double value);
    void setPos(double value);

    double momento() const;
    double normal() const;
    double corte() const;
    double pos() const;

    QString reporteCalculo();
private:
    double _momento;
    double _normal;
    double _corte;
    double _pos;

    // Base interface
public:
    virtual QString description();
};

#endif // ESFUERZOINTERNO_H
