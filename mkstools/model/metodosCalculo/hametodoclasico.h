#ifndef HAMETODOCLASICO_H
#define HAMETODOCLASICO_H

#include "metodocalculo.h"

class HAMetodoClasico : public MetodoCalculo
{
    Q_OBJECT
public:
    explicit HAMetodoClasico(TipologiaPtr tipologia,
                             EsquemaEstructuralPtr esquemaEstructural,
                             SolicitacionPtr solicitacion,
                             MaterialPtr material,
                             SeccionPtr seccion,
                             QObject *parent = 0);


signals:

public slots:


    // MetodoCalculo interface
public:
    virtual void run();

private:
    void calcularViga();
};

#endif // HAMETODOCLASICO_H
