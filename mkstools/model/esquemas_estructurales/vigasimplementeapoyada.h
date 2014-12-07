#ifndef VIGASIMPLEMENTEAPOYADA_H
#define VIGASIMPLEMENTEAPOYADA_H

#include "esquemaestructural.h"

class VigaSimplementeApoyada : public EsquemaEstructural
{
    Q_OBJECT
public:
    explicit VigaSimplementeApoyada(QObject *parent = 0);
    virtual ~VigaSimplementeApoyada();

    virtual void edit();
    virtual EsquemaEstructuralPtr clone();

signals:

public slots:

private:
    double _longitud;
};

typedef QSharedPointer<VigaSimplementeApoyada> VigaSimplementeApoyadaPtr;

#endif // VIGASIMPLEMENTEAPOYADA_H
