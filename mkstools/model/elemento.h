#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "base.h"
#include "tipologias/tipologia.h"

class Elemento : public Base
{
    Q_OBJECT
public:
    explicit Elemento(const QString &name, const QString &tipo, QObject *parent = 0);
    virtual ~Elemento();
    virtual void edit();
    virtual void calcular();
    QString reporteCalculo();

private:
    void createInnerElement();

signals:

public slots:
private:
    TipologiaPtr _elemento;
    QString _tipo;

    // Base interface
public:
    virtual QString description();
};



#endif // ELEMENTO_H
