#include "metodocalculo.h"
#include "../tipologias/tipologia.h"

MetodoCalculo::MetodoCalculo(const QString &name,
                             QObject *parent) :
    Base(name, parent)
{
}

void MetodoCalculo::init(Tipologia* tipologia, EsquemaEstructuralPtr esquemaEstructural, const QList<SolicitacionPtr> &solicitacion, MaterialPtr material, SeccionPtr seccion)
{
    Q_ASSERT(tipologia != NULL);
    Q_ASSERT(!esquemaEstructural.isNull());
    Q_ASSERT(!material.isNull());
    Q_ASSERT(!seccion.isNull());

    _tipologia = tipologia;
    _esquemaEstructural = esquemaEstructural;
    _solicitacion = solicitacion;
    _material = material;
    _seccion = seccion;
}

QString MetodoCalculo::description()
{
    return QString("<h5>Método de cálculo: %1</h5><br>").arg(name());
}
