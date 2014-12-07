#include "metodocalculo.h"

MetodoCalculo::MetodoCalculo(const QString &name, TipologiaPtr tipologia, EsquemaEstructuralPtr esquemaEstructural, SolicitacionPtr solicitacion, MaterialPtr material, SeccionPtr seccion, QObject *parent) :
    Base(name, parent)
{
    Q_ASSERT(!tipologia.isNull());
    Q_ASSERT(!esquemaEstructural.isNull());
    Q_ASSERT(!solicitacion.isNull());
    Q_ASSERT(!material.isNull());
    Q_ASSERT(!seccion.isNull());

    _tipologia = tipologia;
    _esquemaEstructural = esquemaEstructural;
    _solicitacion = solicitacion;
    _material = material;
    _seccion = seccion;
}