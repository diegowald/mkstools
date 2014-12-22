#include "hametodoclasico.h"
#include "../tipologias/viga.h"
#include <cmath>
#include "../secciones/seccionrectangular.h"
#include "../materiales/hormigonarmado.h"
#include <QVarLengthArray>
#include "../esfuerzos_internos/esfuerzointerno.h"
#include "../solicitaciones/solicitacion.h"
#include "../esquemas_estructurales/esquemaestructural.h"

HAMetodoClasico::HAMetodoClasico(QObject *parent) :
    MetodoCalculo("metodo clasico", parent)
{
}

void HAMetodoClasico::run()
{
    if (qobject_cast<Viga*>(_tipologia))
    {
        calcularViga();
    }
}

void HAMetodoClasico::calcularViga()
{
    _seccionesCalculadas.clear();
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
    _seccionMayorArmaduraInferior.clear();
    _seccionMenorArmaduraSuperior.clear();
    _seccionMayorArmaduraInferior.clear();
    _seccionMenorArmaduraSuperior.clear();
    QVarLengthArray<EsfuerzoInternoPtr, 1024> esfuerzos = _esquemaEstructural->esfuerzosInternos();
    for (int i = 0; i < esfuerzos.size(); ++i)
    {
/*        // Usando tabla 42
        SeccionRectangularPtr seccion = qobject_cast<SeccionRectangularPtr>(_seccion);
        double k4 = seccion->base() * seccion->altura() / seccion->areaAceroInferior();
        double m = inversa(9.0, 300.0, k4, HAMetodoClasico::k4Tabla42);
        double kx = kxTabla42(m);
        double tensionAcero = esfuerzos[i]->momento() / (kx * seccion->altura() * seccion->areaAceroInferior());
        double tensionHormigon = tensionAcero / m;
*/
        // Usando tabla 56
        _seccionesCalculadas.append(verificarUsandoTabla56(esfuerzos[i]->momento()));
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
    if (aproximadamenteIgual(y_xMin, value))
    {
        return xMin;
    }

    if (aproximadamenteIgual(y_xMax, value))
    {
        return xMax;
    }

    bool funcionCreciente = (y_xMin < y_xMax);
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
        if (funcionCreciente)
        {
            return (value < y_xMin) ? xMin : xMax;
        }
        else
        {
            return (value > y_xMin) ? xMin : xMax;
        }
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
    QString reporte = "";
    // Verificacion de la tension de compresion del hormigon sin armadura de compresion
    SeccionRectangularPtr seccion = qobject_cast<SeccionRectangularPtr>(_seccion);
    SeccionRectangularPtr seccionCalculada = qobject_cast<SeccionRectangularPtr>(seccion->clone());
    if (momento == 0.)
    {
        reporte += "Momento == 0 -> No es necesario realizar verificaciones.";
        seccionCalculada->setReporte(reporte);
        seccionCalculada->setAreaAceroInferior(0.);
        seccionCalculada->setAreaAceroSuperior(0.);
    }
    else
    {
        reporte += QString("Momento %1 tcm.<br>").arg(momento);

        HormigonArmadoPtr material = qobject_cast<HormigonArmadoPtr>(_material);
        double h = seccion->altura() - seccion->recubrimientoInferior();
        reporte += QString("Altura de cálculo: %1 cm.<br>").arg(h);
        double k6 = (seccion->base() * pow(h, 2.0)) /  momento;
        reporte += QString("k6 = %1").arg(k6);
        double tensionHormigon = inversa(0.03, 0160, k6, k6Tabla56);
        reporte += QString("De tabla 56, para k6 = %1, obtengo tension de trabajo del hormigon = %2.<br>").arg(k6).arg(tensionHormigon);
        if (tensionHormigon < material->hormigon()->tensionAdmisibleCompresion())
        {
            reporte += QString("Tension de trabajo menor que tension admisible, no es necesario armadura de compresión.<br>");
            // El hormigon soporta la compresion.
            double armaduraTraccion = seccion->base() * h / k4Tabla56(tensionHormigon);
            seccionCalculada->setAreaAceroInferior(armaduraTraccion);
            seccionCalculada->setAreaAceroSuperior(0.0);
        }
        else
        {
            reporte += QString("La tension de compresion es mayor a la admisible. Se requiere armadura adicional de compresión.");
            // El hormigon no soporta la compresion por si solo y necesita armadura de compresion adicional
            tensionHormigon = material->hormigon()->tensionAdmisibleCompresion();
            reporte += QString("Se adopta la tensión admisible del hormigón como tensión de trabajo.<br>");
            k6 = k6Tabla56(tensionHormigon);
            reporte += QString("Se obtiene k6 de tabla. k6 = %1.<br>").arg(k6);

            double MomentoComplementario = momento - seccion->base() * pow(h, 2.0) / k6;
            reporte += QString("Momento complementario a absorver por la armadura de compresión: %1 tcm.<br>").arg(MomentoComplementario);

            double c = h - seccion->recubrimientoSuperior();
            reporte += QString("Brazo de palanca c = %1 cm.<br>").arg(c);

            double armaduraTraccion = seccion->base() * h / k6 + MomentoComplementario / (c * material->acero()->tensionAdmisibleTraccion());
            reporte += QString("Armaruda de tracción = %1 cm2.<br>").arg(armaduraTraccion);

            // Obtengo la tension de compresion del acero
            double x = kxTabla56(tensionHormigon) * h;
            double tensionCompresionAcero = 15 * tensionHormigon * (x - seccion->recubrimientoSuperior()) / x;
            reporte += QString("De tabla, tensión de compresión de acero = %1 t/cm2.<br>").arg(tensionCompresionAcero);

            double armaduraCompresion = MomentoComplementario / c / tensionCompresionAcero;
            reporte += QString("Armadura de compresión = %1 cm2.<br>").arg(armaduraCompresion);

            seccionCalculada->setAreaAceroInferior(armaduraTraccion);
            seccionCalculada->setAreaAceroSuperior(armaduraCompresion);
            seccionCalculada->setReporte(reporte);
        }
    }
    if (_seccionMayorArmaduraInferior.isNull())
    {
        _seccionMayorArmaduraInferior = seccionCalculada;
        _seccionMenorArmaduraInferior = seccionCalculada;
        _seccionMayorArmaduraSuperior = seccionCalculada;
        _seccionMenorArmaduraSuperior = seccionCalculada;
    }
    else
    {
        SeccionRectangularPtr s = qobject_cast<SeccionRectangularPtr>(_seccionMayorArmaduraInferior);
        if (s->areaAceroInferior() < seccionCalculada->areaAceroInferior())
        {
            _seccionMayorArmaduraInferior = seccionCalculada;
        }
        s = qobject_cast<SeccionRectangularPtr>(_seccionMenorArmaduraInferior);
        if (s->areaAceroInferior() > seccionCalculada->areaAceroInferior());
        {
            _seccionMenorArmaduraInferior = seccionCalculada;
        }
        s = qobject_cast<SeccionRectangularPtr>(_seccionMayorArmaduraSuperior);
        if (s->areaAceroSuperior() < seccionCalculada->areaAceroSuperior())
        {
            _seccionMayorArmaduraSuperior = seccionCalculada;
        }
        s = qobject_cast<SeccionRectangularPtr>(_seccionMenorArmaduraSuperior);
        if (s->areaAceroSuperior() > seccionCalculada->areaAceroSuperior())
        {
            _seccionMenorArmaduraSuperior = seccionCalculada;
        }
    }

    return seccionCalculada;
}


QSharedPointer<MetodoCalculo> HAMetodoClasico::clone()
{
    return HAMetodoClasicoPtr::create();
}

bool HAMetodoClasico::aproximadamenteIgual(double valor1, double valor2)
{
    return fabs(valor1 - valor2) < 1e-5;
}

QString HAMetodoClasico::reporteCalculo()
{
    QString reporte = "";
    reporte += QString("<h3>Metodo de Calculo %1</h3><br>").arg(name());

    reporte += _esquemaEstructural->reporteCalculo();

    reporte += QString("<h4>Secciones solicitadas</h4><br>");
    reporte += QString("<h5>Mayor armadura inferior</h5><br>");
    reporte += _seccionMayorArmaduraInferior->reporte();
    reporte += _seccionMayorArmaduraInferior->description();

    reporte += QString("<h5>Menor armadura inferior</h5><br>");
    reporte += _seccionMenorArmaduraInferior->reporte();
    reporte += _seccionMenorArmaduraInferior->description();

    reporte += QString("<h5>Mayor armadura superior</h5><br>");
    reporte += _seccionMayorArmaduraSuperior->reporte();
    reporte += _seccionMayorArmaduraSuperior->description();

    reporte += QString("<h5>Menor armadura superior</h5><br>");
    reporte += _seccionMenorArmaduraSuperior->reporte();
    reporte += _seccionMenorArmaduraSuperior->description();

    return reporte;
}
