#include "hametodoclasico.h"
#include "../tipologias/viga.h"
#include <cmath>
#include "../secciones/seccionrectangular.h"
#include "../materiales/hormigonarmado.h"
#include <QVarLengthArray>
#include "../esfuerzos_internos/esfuerzointerno.h"

HAMetodoClasico::HAMetodoClasico(TipologiaPtr tipologia,
                                 EsquemaEstructuralPtr esquemaEstructural,
                                 const QList<SolicitacionPtr> &solicitacion,
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
    predimensionarViga();
    calcularSolicitaciones();
    calcularReacciones();
    calcularEsfuerzosInternos();
    calcularMaximosEsfuerzos();
    verificacionSecciones();
}

void HAMetodoClasico::predimensionarViga()
{

}

void HAMetodoClasico::calcularSolicitaciones()
{
    foreach (SolicitacionPtr s, _solicitacion)
    {
        s->calcularSolicitacion(_seccion, _esquemaEstructural);
    }
}

void HAMetodoClasico::calcularReacciones()
{
    _esquemaEstructural->calcularReacciones(_solicitacion);
}

void HAMetodoClasico::calcularEsfuerzosInternos()
{
    _esquemaEstructural->calcularEsfuerzosInternos(_solicitacion);
}

void HAMetodoClasico::calcularMaximosEsfuerzos()
{
    _esquemaEstructural->calcularMaximosEsfuerzos();
}

void HAMetodoClasico::verificacionSecciones()
{
    QVarLengthArray<EsfuerzoInternoPtr, 1024> esfuerzos = _esquemaEstructural->esfuerzosInternos();
    for (int i = 0; i < esfuerzos.size(); ++i)
    {
        // Usando tabla 42
        SeccionRectangularPtr seccion = qobject_cast<SeccionRectangularPtr>(_seccion);
        double k4 = seccion->base() * seccion->altura() / seccion->areaAceroInferior();
        double m = inversa(9.0, 300.0, k4, HAMetodoClasico::k4Tabla42);
        double kx = kxTabla42(m);
        double tensionAcero = esfuerzos[i]->momento() / (kx * seccion->altura() * seccion->areaAceroInferior());
        double tensionHormigon = tensionAcero / m;

        // Usando tabla 56
        verificarUsandoTabla56(esfuerzos[i]->momento());
    }
}

double HAMetodoClasico::k1Tabla42(double m)
{
    return 0.0000000501297196683261 * pow(m, 3.0)
            + 0.133072072 * pow(m, 2.0)
            + 2.7059780137 * m
            + 1.4312463042;
}

double HAMetodoClasico::k4Tabla42(double m)
{
    return -0.00000000338892165005573 * pow(m, 3.0)
            + 0.1333415386 * pow(m, 2.0)
            + 1.9979135998 * m
            + 0.0301337888;
}

double HAMetodoClasico::kxTabla42(double m)
{
    return -1.72602484687457E-018 * pow(m, 8.0)
            + 2.1862269692099E-015 * pow(m, 7.0)
            - 0.0000000000011514926388692 * pow(m, 6.0)
            + 0.000000000327701398682491 * pow(m, 5.0)
            - 0.0000000549414379633304 * pow(m, 4.0)
            + 0.00000557944551351046 * pow(m, 3.0)
            - 0.000343391 * pow(m, 2.0)
            + 0.0127842697 * m
            + 0.7018468434;
}

double HAMetodoClasico::inversa(double xMin, double xMax, double value, std::function<double(double)> func)
{
    double y_xMin = func(xMin);
    double y_xMax = func(xMax);
    if (y_xMin == value)
    {
        return xMin;
    }

    if (y_xMax == value)
    {
        return xMax;
    }

    if (between(value, y_xMin, y_xMax))
    {
        double xmid = (xMin + xMax) / 2.0;
        double ymid = func(xmid);
        if (between(value, y_xMin, ymid))
        {
            return inversa(xMin, xmid, value, func);
        }
        else
        {
            return inversa(xmid, xMax, value, func);
        }
    }
    else
    {
        return 1e-308;
    }
}

bool HAMetodoClasico::between(double value, double value1, double value2)
{
    double vMin = value1 < value2 ? value1 : value2;
    double vMax = value1 > value2 ? value1 : value2;

    return (vMin <= value) && (value <= vMax);
}


double HAMetodoClasico::kxTabla56(double sb)
{
    return
            -172.0299068942 * pow(sb, 4.0)
            + 105.07273555339 * pow(sb, 3.0)
            - 30.2115449576 * pow(sb, 2.0)
            + 5.9476162597 * sb
            + 0.0040323853;
}

double HAMetodoClasico::kzTabla56(double sb)
{
    return
            37.9207822602 * pow(sb, 4.0)
            - 27.7028912489 * pow(sb, 3.0)
            + 9.099748036 * pow(sb, 2.0)
            - 1.9254290787 * sb
            + 0.9975041288;
}

double HAMetodoClasico::k2Tabla56(double sb)
{
    return 172461.584301746 * pow(sb, 4.0)
            - 79190.7290790824 * pow(sb, 3.0)
            + 13712.3671000937 * pow(sb, 2.0)
            - 1110.9266300902 * sb
            + 43.7109159596;
}

double HAMetodoClasico::k3Tabla56(double sb)
{
    return 7.8497529355 * pow(sb, 4.0)
            + 2.2836693231 * pow(sb, 3.0)
            - 2.465431471 * pow(sb, 2.0)
            + 0.8186547893 * sb
            + 0.4176061602;
}

double HAMetodoClasico::k4Tabla56(double sb)
{
    return 2.6541747922 * pow(sb, -1.6767140322);
}

double HAMetodoClasico::k6Tabla56(double sb)
{
    return 1.5258770702 * pow(sb, -1.5969740291);
}

SeccionPtr HAMetodoClasico::verificarUsandoTabla56(double momento)
{
    // Verificacion de la tension de compresion del hormigon sin armadura de compresion
    SeccionRectangularPtr seccion = qobject_cast<SeccionRectangularPtr>(_seccion);
    SeccionRectangularPtr seccionCalculada = qobject_cast<SeccionRectangularPtr>(seccion->clone());
    HormigonArmadoPtr material = qobject_cast<HormigonArmadoPtr>(_material);
    double h = seccion->altura() - seccion->recubrimientoInferior();
    double k6 = (seccion->base() - pow(h, 2.0)) /  momento;
    double tensionHormigon = inversa(0.03, 0160, k6, k6Tabla56);
    if (tensionHormigon < material->hormigon()->tensionCompression())
    {
        // El hormigon soporta la compresion.
        double armaduraTraccion = seccion->base() * h / k4Tabla56(tensionHormigon);
        seccionCalculada->setAreaAceroInferior(armaduraTraccion);
        seccionCalculada->setAreaAceroSuperior(0.0);
    }
    else
    {
        // El hormigon no soporta la compresion por si solo y necesita armadura de compresion adicional
        tensionHormigon = material->hormigon()->tensionCompression();
        k6 = k6Tabla56(tensionHormigon);
        double MomentoComplementario = momento - seccion->base() * pow(h, 2.0) / k6;

        double c = h - seccion->recubrimientoSuperior();

        double armaduraTraccion = seccion->base() * h / k6 + MomentoComplementario / (c * material->acero()->tensionTraccion());

        // Obtengo la tension de compresion del acero
        double x = kxTabla56(tensionHormigon) * h;
        double tensionCompresionAcero = 15 * tensionHormigon * (x - seccion->recubrimientoSuperior()) / x;

        double armaduraCompresion = MomentoComplementario / c / material->acero()->tensionCompression();
        seccionCalculada->setAreaAceroInferior(armaduraTraccion);
        seccionCalculada->setAreaAceroSuperior(armaduraCompresion);
    }
    return seccionCalculada;
}
