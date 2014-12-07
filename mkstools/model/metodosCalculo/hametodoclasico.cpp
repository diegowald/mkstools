#include "hametodoclasico.h"
#include "../tipologias/viga.h"

HAMetodoClasico::HAMetodoClasico(TipologiaPtr tipologia,
                                 EsquemaEstructuralPtr esquemaEstructural,
                                 SolicitacionPtr solicitacion,
                                 MaterialPtr material,
                                 SeccionPtr seccion,
                                 QObject *parent) :
    MetodoCalculo("metodo clasico", tipologia, esquemaEstructural, solicitacion, material, seccion, parent)
{
}


void HAMetodoClasico::run()
{
    if (!qobject_cast<VigaPtr>(_tipologia).isNull())
    {
        calcularViga();
    }
}

void HAMetodoClasico::calcularViga()
{
    calcularSolicitaciones();
    calcularReacciones();
    calcularEsfuerzosInternos();
    calcularMaximosEsfuerzos();
    verificacionSecciones();
}
