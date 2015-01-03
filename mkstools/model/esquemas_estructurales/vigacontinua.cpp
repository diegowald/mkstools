#include "vigacontinua.h"
#include "esquemaestructural.h"
#include "dialogs/dlgeditvigacontinua.h"
#include "widgets/widgeteditvigacontinua.h"
#include <QDebug>
#include "vigasimplementeapoyada.h"
#include "../esfuerzos_internos/esfuerzointerno.h"
#include "../solicitaciones/solicitacion.h"
#include <eigen3/Eigen/LU>


VigaContinua::VigaContinua(QObject *parent) : EsquemaEstructural("viga continua", parent)
{
    _longitud = 0;
    _apoyos.clear();
    _momentosApoyos.clear();
    _reaccionesVerticales.clear();
    _vigaAislada.clear();
    _esfuerzosInternos.clear();
    _idMinMomento = 0;
    _idMinCorte = 0;
    _idMaxMomento = 0;
    _idMaxCorte = 0;
}

VigaContinua::~VigaContinua()
{

}

EsquemaEstructuralPtr VigaContinua::clone()
{
    VigaContinuaPtr viga = VigaContinuaPtr::create();
    viga->_longitud = _longitud;
    viga->_apoyos.append(_apoyos);
    return viga;
}

QString VigaContinua::description()
{
    QString s = QString("<h5>Viga continua.</h5><br>Luz: %1 cm.<br>").arg(_longitud);

    s += QString("<h6>Ubicación apoyos</h6><br>");

    foreach (double apoyo, _apoyos)
    {
        s += QString("Apoyo: %1 cm.<br>").arg(apoyo);
    }
    return s;
}

void VigaContinua::edit()
{
    DlgEditVigaContinua dlg;
    dlg.setLongitud(_longitud);
    dlg.setApoyos(_apoyos);
    if (dlg.exec() == QDialog::Accepted)
    {
        _longitud = dlg.longitud();
        _apoyos = dlg.apoyos();
    }
}

QWidget* VigaContinua::getEditWidget()
{
    WidgetEditVigaContinua *widget = new WidgetEditVigaContinua();
    widget->setLongitud(_longitud);
    widget->setApoyos(_apoyos);
    return widget;
}

void VigaContinua::calcularReacciones(const QList<SolicitacionPtr> &solicitaciones)
{
    // Se emplea el metodo de clapeyron
    armarVigasAisladas();
    armarMatriz(solicitaciones);
    calcularMomentosApoyoPorClapeyron(solicitaciones);
    calcularReaccionesPorClapeyron();
}

void VigaContinua::calcularEsfuerzosInternos(const QList<SolicitacionPtr> &solicitaciones)
{
    _esfuerzosInternos.clear();
    for (double x = 0.0; x <= _longitud; x += 1.)
    {
        double momentoPto = 0.;
        double cortePto = 0.;

        for (int i = 0; i < _apoyos.size(); ++i)
        {
            if (x >= _apoyos.at(i))
            {
                momentoPto += _reaccionesVerticales.at(i) * (x - _apoyos.at(i));
                cortePto += _reaccionesVerticales.at(i);
            }
        }

        foreach (SolicitacionPtr s, solicitaciones)
        {
            momentoPto += s->momentoIzquierda(x);
            cortePto += s->corteIzquierda(x);
        }

        EsfuerzoInternoPtr esfuerzo = EsfuerzoInternoPtr::create();
        esfuerzo->setMomento(momentoPto);
        esfuerzo->setCorte(cortePto);
        esfuerzo->setNormal(0.0);
        esfuerzo->setPos(x);
        _esfuerzosInternos.append(esfuerzo);
    }
}

void VigaContinua::calcularMaximosEsfuerzos()
{
    double _minMomento = std::numeric_limits<double>::max();
    double _maxMomento = -std::numeric_limits<double>::max();
    double _maxCorte = -std::numeric_limits<double>::max();
    double _minCorte = std::numeric_limits<double>::max();

    for (int i = 0; i < _esfuerzosInternos.size(); ++i)
    {
        EsfuerzoInternoPtr esf = _esfuerzosInternos[i];
        if (esf->momento() < _minMomento)
        {
             _minMomento = esf->momento();
             _idMinMomento = i;
        }
        if (esf->corte() < _minCorte)
        {
            _minCorte = esf->corte();
            _idMinCorte = i;
        }
        if (esf->momento() > _maxMomento)
        {
            _maxMomento = esf->momento();
            _idMaxMomento = i;
        }
        if (esf->corte() > _maxCorte)
        {
            _maxCorte = esf->corte();
            _idMaxCorte = i;
        }
    }
}

double VigaContinua::minMomento() const
{
    return _esfuerzosInternos[_idMinMomento]->momento();
}

double VigaContinua::posMinMomento() const
{
    return _esfuerzosInternos[_idMinMomento]->pos();
}

double VigaContinua::maxMomento() const
{
    return _esfuerzosInternos[_idMaxMomento]->momento();
}

double VigaContinua::posMaxMomento() const
{
    return _esfuerzosInternos[_idMaxMomento]->pos();
}

double VigaContinua::maxCorte() const
{
    return _esfuerzosInternos[_idMaxCorte]->corte();
}

double VigaContinua::posMinCorte() const
{
    return _esfuerzosInternos[_idMinCorte]->pos();
}

double VigaContinua::minCorte() const
{
    return _esfuerzosInternos[_idMinCorte]->corte();
}

double VigaContinua::posMaxCorte() const
{
    return _esfuerzosInternos[_idMaxCorte]->pos();
}

QVarLengthArray<EsfuerzoInternoPtr, 1024> VigaContinua::esfuerzosInternos()
{
    return _esfuerzosInternos;
}

QString VigaContinua::reporteCalculo()
{
    QString reporte = QString("<h4>Cálculo de reacciones</h4><br>");

    for (int i = 0; i < _apoyos.size(); ++i)
    {
        reporte += QString("<h5>Reacción en pto Nro %1</h5><br>").arg(i);
        reporte += QString("Posición: %1 cm.").arg(_apoyos.at((i)));
        reporte += QString("Reacción vertical: %1 t.<br>").arg(_reaccionesVerticales.at(i));
        reporte += QString("Momento en el apoyo: %1 tcm.<br>").arg(_momentosApoyos.at(i));
        reporte += QString("<br>");
    }

    reporte += QString("<h4>Maximos esfuerzos internos</h4><br>");
    reporte += QString("<h5>Momento Mínimo</h5><br>");
    reporte += _esfuerzosInternos[_idMinMomento]->reporteCalculo();

    reporte += QString("<h5>Momento Máximo</h5><br>");
    reporte += _esfuerzosInternos[_idMaxMomento]->reporteCalculo();

    reporte += QString("<h5>Corte Mínimo</h5><br>");
    reporte += _esfuerzosInternos[_idMinCorte]->reporteCalculo();

    reporte += QString("<h5>Corte Máximo</h5><br>");
    reporte += _esfuerzosInternos[_idMaxCorte]->reporteCalculo();
    reporte += "<br>";

    return reporte;
}

QGraphicsScene *VigaContinua::generarDiagrama(Diagrama diagrama)
{
    QList<double> valoresInferiores;
    QList<double> valoresSuperiores;
    QList<double> armadurasInferiores;
    QList<double> armadurasSuperiores;
    for (int i = 0; i < _esfuerzosInternos.size(); i++)
    {
        valoresInferiores.append(obtenerValor(diagrama, i));
    }
    return generarDiagrama(diagrama, valoresInferiores, valoresSuperiores, armadurasInferiores, armadurasSuperiores);
}

QGraphicsScene *VigaContinua::generarDiagrama(Diagrama diagrama, QList<double> &valoresInferiores, QList<double> &valoresSupoeriores,
                                        QList<double> &seccionesArmaduraInferiores, QList<double> &seccionesArmarudaSuperiores)
{
    (void) diagrama;
    QGraphicsScene *scene = new QGraphicsScene();

    scene->addEllipse(10, 10, 3, 5);

    // Dibujo la estructura
    scene->addLine(0, 0, _longitud, 0, QPen(Qt::black));

    // Dibujo el diagrama inferior
    double escala = 1.0;
    double delta = 0;
    if (valoresInferiores.size() > 0)
    {
        double minimoValor = obtenerMinimo(valoresInferiores);
        double maximoValor = obtenerMaximo(valoresInferiores);
        delta = fabs(maximoValor - minimoValor);
    }

    if (valoresSupoeriores.size() > 0)
    {
        double minimoValor = obtenerMinimo(valoresSupoeriores);
        double maximoValor = obtenerMaximo(valoresSupoeriores);
        double deltaSup = fabs(maximoValor - minimoValor);
        delta = (delta > deltaSup) ? delta : deltaSup;
    }

    escala = (delta == 0.) ? 1 : 0.5 * _longitud / delta;

    if (valoresInferiores.size() > 0)
    {
        double xAnt = 0.;
        double yAnt = 0.;
        for (int i = 0; i < _esfuerzosInternos.size(); i++)
        {
            double x = 1.0 * i;
            double y = valoresInferiores.at(i) * escala;
            scene->addLine(xAnt, yAnt, x, y, QPen(Qt::darkBlue));
            xAnt = x;
            yAnt = y;
        }
        scene->addLine(xAnt, yAnt, _longitud, 0, QPen(Qt::darkBlue));
    }

    // Dibujo el diagrama inferior
    if (valoresSupoeriores.size() > 0)
    {
        double xAnt = 0.;
        double yAnt = 0.;
        for (int i = 0; i < _esfuerzosInternos.size(); i++)
        {
            double x = 1.0 * i;
            double y = -valoresSupoeriores.at(i) * escala;
            scene->addLine(xAnt, yAnt, x, y, QPen(Qt::darkGreen));
            xAnt = x;
            yAnt = y;
        }
        scene->addLine(xAnt, yAnt, _longitud, 0, QPen(Qt::darkGreen));
    }

    // Dibujo las armaduras inferiores
    double acumulado = 0.;
    foreach (double valor, seccionesArmaduraInferiores)
    {
        acumulado += valor * escala
                ;
        scene->addLine(0, acumulado, _longitud, acumulado);
    }

    // Dibujo las armaduras superiores
    acumulado = 0.;
    foreach (double valor, seccionesArmarudaSuperiores)
    {
        acumulado -= valor * escala;
        scene->addLine(0, acumulado, _longitud, acumulado);
    }

    return scene;
}


void VigaContinua::armarMatriz(const QList<SolicitacionPtr> &solicitaciones)
{
    int numIncognitas = _apoyos.size() - 2;
    _matrix.resize(numIncognitas, numIncognitas);
    _terminoIndependiente.resize(numIncognitas, 1);
    for (int i = 0; i < numIncognitas; ++i)
    {
        for (int j = 0; j < numIncognitas; ++j)
        {
            double valor = 0.;
            switch (j - i)
            {
            case -1:
                valor = 1. * (_apoyos.at(j + 1) - _apoyos.at(j));
                break;
            case 0:
                valor = 2. *
                        ((_apoyos.at(j + 1) - _apoyos.at(j)) +
                         (_apoyos.at(j +2) - _apoyos.at(j + 1)));
                break;
            case 1:
                valor = 1. * (_apoyos.at(j + 2) - _apoyos.at(j + 1));
                break;
            default:
                valor = 0.;
                break;
            }
            _matrix(i, j) = valor;
        }
        armarTerminoIndependiente(i, solicitaciones);
    }
}

void VigaContinua::armarVigasAisladas()
{
    _vigaAislada.clear();
    for (int i = 1; i < _apoyos.count(); ++i)
    {
        crearViga(i - 1, i);
    }
}

void VigaContinua::crearViga(int apoyoIzquierdo, int apoyoDerecho)
{
    VigaSimplementeApoyadaPtr viga = VigaSimplementeApoyadaPtr::create();
    double offset = 0.;
    /*if (apoyoIzquierdo > 0)
    {*/
        offset = _apoyos.at(apoyoIzquierdo);
    /*}*/

    viga->setPosicionApoyoIzquierdo(_apoyos.at(apoyoIzquierdo) - offset);
    viga->setPosicionApoyoDerecho(_apoyos.at(apoyoDerecho) - offset);
    viga->setLongitud(_apoyos.at(apoyoDerecho) - offset);
    _vigaAislada.append(viga);
}

void VigaContinua::armarTerminoIndependiente(int i, const QList<SolicitacionPtr> &solicitaciones)
{
    QList<SolicitacionPtr> solicitacionesTrasladadas = trasladarSolicitaciones(i, solicitaciones);
    /*double omegaIzq = omega(_vigaAislada.at(i), solicitaciones);
    double Dizq = D(_vigaAislada.at(i), solicitaciones);*/
    double omegaDIzq = omegaD(_vigaAislada.at(i), solicitacionesTrasladadas);
    double Lizq = _vigaAislada.at(i)->longitud();

    /*double omegaDer = omega(_vigaAislada.at(i + 1), solicitaciones);
    double Dder = d(_vigaAislada.at(i + 1), solicitaciones);*/
    double omegadDer = omegad(_vigaAislada.at(i + 1), solicitacionesTrasladadas);
    double Lder = _vigaAislada.at(i + 1)->longitud();

    double mEmpotramiento = 0.;
    double L = 0.;
    if (i == 0)
    {
        mEmpotramiento = calcularMomentoEmpotramientoIzquierdo(solicitaciones);
        L = Lizq;
    }
    else if (i == _apoyos.size() - 3)
    {
        mEmpotramiento = calcularMomentoEmpotramientoDerecho(solicitaciones);
        L = Lder;
    }

    _terminoIndependiente(i, 0) = -6 * ((omegaDIzq / Lizq) + (omegadDer / Lder)) - mEmpotramiento * L;
}

QList<SolicitacionPtr> VigaContinua::trasladarSolicitaciones(int i, const QList<SolicitacionPtr> &solicitaciones)
{
    QList<SolicitacionPtr> solics;
    double posApoyoIzquierdo = _apoyos.at(i);
    double posApoyoDerecho = _apoyos.at(i + 1);
    foreach (SolicitacionPtr solicitacion, solicitaciones)
    {
        SolicitacionPtr s = solicitacion->clone();
        s->trasladarOrigen(posApoyoIzquierdo, posApoyoDerecho);
        solics.append(s);
    }
    return solics;
}

void VigaContinua::calcularMomentosApoyoPorClapeyron(const QList<SolicitacionPtr> &solicitaciones)
{
    // aca es donde debo resolver el sistema de ecuaciones.
    Eigen::FullPivHouseholderQR<Matriz> solver(_matrix);
    Vector momentosApoyos = solver.solve(_terminoIndependiente);
    _momentosApoyos.clear();
    _momentosApoyos.append(calcularMomentoEmpotramientoIzquierdo(solicitaciones));
    for (int i = 0; i < momentosApoyos.rows(); ++i)
    {
        _momentosApoyos.append(momentosApoyos(i, 0));
    }
    _momentosApoyos.append(calcularMomentoEmpotramientoDerecho(solicitaciones));
}

void VigaContinua::calcularReaccionesPorClapeyron()
{
    _reaccionesVerticales.clear();
    for (int i = 0; i < _momentosApoyos.size(); ++i)
    {
        double terminoIzquierdo = 0.;
        if (i > 0)
        {
            double m1 = (i == 0) ? 0. : _momentosApoyos.at(i - 1);
            double m2 = _momentosApoyos.at(i);
            double l = _vigaAislada.at(i - 1)->longitud();
            double R = _vigaAislada.at(i - 1)->reaccionVerticalDerecha();
            terminoIzquierdo = (m1 - m2) / l + R;
        }
        //((Mk-1 - Mk)/Lk + RkDerISO) + ((Mk+1 - Mk)/Lk+1 + Rk+1IzqISO)
        double terminoDerecho = 0.;
        if (i < _momentosApoyos.size() - 1)
        {
            double m1 = (i == _momentosApoyos.size() -1) ? 0. : _momentosApoyos.at(i + 1);
            double m2 = _momentosApoyos.at(i);
            double l = _vigaAislada.at(i)->longitud();
            double R = _vigaAislada.at(i)->reaccionVerticalIzquierda();
            terminoDerecho = (m1 - m2) / l + R;
        }

        double reaccion = terminoIzquierdo + terminoDerecho;
        _reaccionesVerticales.append(reaccion);
    }
}

double VigaContinua::omega(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones)
{
    // Omega es el area del diagrama de momentos.
    // Seria la integral en toda la long. de la viga de M(x) dx
    viga->calcularReacciones(solicitaciones);
    viga->calcularEsfuerzosInternos(solicitaciones);
    QVarLengthArray<EsfuerzoInternoPtr, 1024> esfuerzos = viga->esfuerzosInternos();
    // Se arma integracion por el metodo de Simpson (trapecios...)
    double acumulado = 0.;
    EsfuerzoInternoPtr esfuerzoAnterior;
    esfuerzoAnterior.clear();
    foreach (EsfuerzoInternoPtr esfuerzo, esfuerzos)
    {
        double areaTrapecio = 0.;
        if (!esfuerzoAnterior.isNull())
        {
            areaTrapecio = (esfuerzoAnterior->momento() + esfuerzo->momento()) / 2 * (esfuerzo->pos() - esfuerzoAnterior->pos());
        }
        acumulado += areaTrapecio;
        esfuerzoAnterior = esfuerzo;
    }
    return acumulado;
}

double VigaContinua::D(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones)
{
    return omegaD(viga, solicitaciones) / omega(viga, solicitaciones);
}

double VigaContinua::omegaD(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones)
{
    viga->calcularReacciones(solicitaciones);
    viga->calcularEsfuerzosInternos(solicitaciones);
    QVarLengthArray<EsfuerzoInternoPtr, 1024> esfuerzos = viga->esfuerzosInternos();

    // D = 1 / omega * integral en toda la long. de la viga de x M(x) dx
    double acumulado = 0.;
    // Se arma integracion por el metodo de Simpson (trapecios...)
    EsfuerzoInternoPtr esfuerzoAnterior;
    esfuerzoAnterior.clear();
    foreach (EsfuerzoInternoPtr esfuerzo, esfuerzos)
    {
        double areaTrapecio = 0.;
        if (!esfuerzoAnterior.isNull())
        {
            areaTrapecio = (esfuerzoAnterior->pos() * esfuerzoAnterior->momento() +
                            esfuerzo->pos() * esfuerzo->momento()) / 2
                    * (esfuerzo->pos() - esfuerzoAnterior->pos());
        }
        acumulado += areaTrapecio;
        esfuerzoAnterior = esfuerzo;
    }
    return acumulado;
}

double VigaContinua::omegad(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones)
{
    viga->calcularReacciones(solicitaciones);
    viga->calcularEsfuerzosInternos(solicitaciones);
    QVarLengthArray<EsfuerzoInternoPtr, 1024> esfuerzos = viga->esfuerzosInternos();

    // D = 1 / omega * integral en toda la long. de la viga de x M(x) dx
    double longitud = viga->longitud();
    double acumulado = 0.;
    // Se arma integracion por el metodo de Simpson (trapecios...)
    EsfuerzoInternoPtr esfuerzoAnterior;
    esfuerzoAnterior.clear();
    foreach (EsfuerzoInternoPtr esfuerzo, esfuerzos)
    {
        double areaTrapecio = 0.;
        if (!esfuerzoAnterior.isNull())
        {
            areaTrapecio = ((longitud - esfuerzoAnterior->pos()) * esfuerzoAnterior->momento() +
                            (longitud - esfuerzo->pos()) * esfuerzo->momento()) / 2
                    * (esfuerzo->pos() - esfuerzoAnterior->pos());
        }
        acumulado += areaTrapecio;
        esfuerzoAnterior = esfuerzo;
    }
    return acumulado;
}

double VigaContinua::d(VigaSimplementeApoyadaPtr viga, const QList<SolicitacionPtr> &solicitaciones)
{
    return omegad(viga, solicitaciones) / omega(viga, solicitaciones);
}

double VigaContinua::calcularMomentoEmpotramientoIzquierdo(const QList<SolicitacionPtr> &solicitaciones)
{
    double apoyoIzquierdo = _apoyos.first();
    if (apoyoIzquierdo == 0.)
    {
        return 0.;
    }
    double momento = 0.;
    foreach (SolicitacionPtr solicitacion, solicitaciones)
    {
        momento += solicitacion->momentoIzquierda(apoyoIzquierdo);
    }
    return momento;
}

double VigaContinua::calcularMomentoEmpotramientoDerecho(const QList<SolicitacionPtr> &solicitaciones)
{
    double apoyoDerecho = _apoyos.last();
    if (apoyoDerecho == _longitud)
    {
        return 0.;
    }
    double momento = 0.;
    foreach (SolicitacionPtr solicitacion, solicitaciones)
    {
        momento += solicitacion->momentoDerecha(apoyoDerecho);
    }
    return momento;
}


double VigaContinua::obtenerMinimo(QList<double> &valores)
{
    double minimo = 1e308;
    foreach (double valor, valores)
    {
        minimo = (valor < minimo) ? valor : minimo;
    }
    return minimo;
}

double VigaContinua::obtenerMaximo(QList<double> &valores)
{
    double maximo = -1e308;
    foreach (double valor, valores)
    {
        maximo = (valor > maximo) ? valor : maximo;
    }
    return maximo;
}

double VigaContinua::obtenerValor(Diagrama diagrama, int i)
{
    EsfuerzoInternoPtr esfuerzo = _esfuerzosInternos.at(i);
    switch (diagrama)
    {
    case Diagrama::corte:
        return -esfuerzo->corte();
    case Diagrama::momentoFlector:
        return esfuerzo->momento();
    default:
        return 0.;
    }
}
