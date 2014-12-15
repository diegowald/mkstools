#ifndef FORWARD_H
#define FORWARD_H

#include <QSharedPointer>

#define CONSTRUCT(X) \
    class X; \
    typedef QSharedPointer<X> X## Ptr;


CONSTRUCT(EsquemaEstructural)
CONSTRUCT(VigaSimplementeApoyada)
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


#endif // FORWARD_H