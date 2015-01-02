#ifndef FORWARD_H
#define FORWARD_H

#include <QSharedPointer>

#define CONSTRUCT(X) \
    class X; \
    typedef QSharedPointer<X> X## Ptr;


CONSTRUCT(EsquemaEstructural)
CONSTRUCT(VigaSimplementeApoyada)
CONSTRUCT(Voladizo)
CONSTRUCT(VigaContinua)
CONSTRUCT(Acero)
CONSTRUCT(Hormigon)
CONSTRUCT(HormigonArmado)
CONSTRUCT(Material)
CONSTRUCT(Seccion)
CONSTRUCT(SeccionRectangular)
CONSTRUCT(CargaPuntual)
CONSTRUCT(CargaUniformeConstante)
CONSTRUCT(Solicitacion)
CONSTRUCT(Tipologia)
CONSTRUCT(Viga)
CONSTRUCT(Base)
CONSTRUCT(Elemento)
CONSTRUCT(Proyecto)
CONSTRUCT(EsfuerzoInterno)
CONSTRUCT(MetodoCalculo)
CONSTRUCT(HAMetodoClasico)

#endif // FORWARD_H
