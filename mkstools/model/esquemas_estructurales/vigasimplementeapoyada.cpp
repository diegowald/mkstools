#include "vigasimplementeapoyada.h"
#include "../../dialogs/dlgeditvigasimplementeapoyada.h"
#include "../../widgets/widgetvigasimplementeapoyada.h"

#include "../solicitaciones/solicitacion.h"
#include <limits>
#include "../esfuerzos_internos/esfuerzointerno.h"

VigaSimplementeApoyada::VigaSimplementeApoyada(QObject *parent) :
    EsquemaEstructural("simplemente apoyada", parent)
{
    _longitud = 1.;
    _reaccionVerticalA = 0.;
    _reaccionHorizontalA = 0.;
    _reaccionVerticalB = 0.;
    _reaccionHorizontalB = 0.;
    _esfuerzosInternos.clear();
    _posicionApoyoDerecho = 0.;
    _posicionApoyoIzquierdo = 0.;
}

VigaSimplementeApoyada::~VigaSimplementeApoyada()
{
}

void VigaSimplementeApoyada::edit()
{
    DlgEditVigaSimplementeApoyada dlg;
    dlg.setLongitud(_longitud);
    dlg.setPosicionApoyoIzquierdo(_posicionApoyoIzquierdo);
    dlg.setPosicionApoyoDerecho(_posicionApoyoDerecho);
    if (dlg.exec() == QDialog::Accepted)
    {
        _longitud = dlg.longitud();
        _posicionApoyoIzquierdo = dlg.posicionApoyoIzquierdo();
        _posicionApoyoDerecho = dlg.posicinoApoyoDerecho();
    }
}

QWidget *VigaSimplementeApoyada::getEditWidget()
{
    WidgetVigaSimplementeApoyada *widget = new WidgetVigaSimplementeApoyada();
    widget->setLongitud(_longitud);
    widget->setPosicionApoyoIzquierdo(_posicionApoyoIzquierdo);
    widget->setPosicionApoyoDerecho(_posicionApoyoDerecho);
    return widget;
}

EsquemaEstructuralPtr VigaSimplementeApoyada::clone()
{
    VigaSimplementeApoyadaPtr viga = VigaSimplementeApoyadaPtr::create();
    viga->_longitud = _longitud;
    return viga;
}


void VigaSimplementeApoyada::calcularReacciones(const QList<SolicitacionPtr> &solicitaciones)
{
    double momentos = 0.;
    double cargas = 0.;
    foreach (SolicitacionPtr solicitacion, solicitaciones)
    {
        momentos += solicitacion->momento(_posicionApoyoDerecho);
        cargas += solicitacion->corteIzquierda(_longitud);
    }
    _reaccionHorizontalA = 0.;
    _reaccionVerticalA = - momentos / (_posicionApoyoDerecho - _posicionApoyoIzquierdo);
    _reaccionHorizontalB = 0.;
    _reaccionVerticalB = - cargas - _reaccionVerticalA;
}

void VigaSimplementeApoyada::calcularEsfuerzosInternos(const QList<SolicitacionPtr> &solicitaciones)
{
    _esfuerzosInternos.clear();
    for (double x = 0.0; x <= _longitud; x += 1.)
    {
        double momentoPto = 0.;
        double cortePto = 0.;
        if (x >= _posicionApoyoIzquierdo)
        {
            momentoPto = _reaccionVerticalA * (x - _posicionApoyoIzquierdo);
            cortePto = _reaccionVerticalA;
        }
        if (x >= _posicionApoyoDerecho)
        {
            momentoPto += _reaccionVerticalB * (x - _posicionApoyoDerecho);
            cortePto += _reaccionVerticalB;
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

void VigaSimplementeApoyada::calcularMaximosEsfuerzos()
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

double VigaSimplementeApoyada::minMomento() const
{
    return _esfuerzosInternos[_idMinMomento]->momento();
}

double VigaSimplementeApoyada::posMinMomento() const
{
    return _esfuerzosInternos[_idMinMomento]->pos();
}

double VigaSimplementeApoyada::maxMomento() const
{
    return _esfuerzosInternos[_idMaxMomento]->momento();
}

double VigaSimplementeApoyada::posMaxMomento() const
{
    return _esfuerzosInternos[_idMaxMomento]->pos();
}

double VigaSimplementeApoyada::maxCorte() const
{
    return _esfuerzosInternos[_idMaxCorte]->corte();
}

double VigaSimplementeApoyada::posMinCorte() const
{
    return _esfuerzosInternos[_idMaxCorte]->pos();
}

double VigaSimplementeApoyada::minCorte() const
{
    return _esfuerzosInternos[_idMinCorte]->corte();
}

double VigaSimplementeApoyada::posMaxCorte() const
{
    return _esfuerzosInternos[_idMinCorte]->pos();
}

QVarLengthArray<EsfuerzoInternoPtr, 1024> VigaSimplementeApoyada::esfuerzosInternos()
{
    return _esfuerzosInternos;
}


QString VigaSimplementeApoyada::description()
{
    return QString("<h5>Viga simplemente apoyada.</h5><br>Luz: %1 cm.<br>").arg(_longitud);
}

QString VigaSimplementeApoyada::reporteCalculo()
{
    QString reporte = QString("<h4>Cálculo de reacciones</h4><br>");

    reporte += QString("<h5>Reacción A</h5><br>");
    reporte += QString("Reacción horizontal: %1 t.<br>").arg(_reaccionHorizontalA);
    reporte += QString("Reacción vertical: %1 t.<br>").arg(_reaccionVerticalA);
    reporte += QString("<br>");
    reporte += QString("<h5>Reacción B</h5><br>");
    reporte += QString("Reacción horizontal: %1 t.<br>").arg(_reaccionHorizontalB);
    reporte += QString("Reacción vertical: %1 t.<br>").arg(_reaccionVerticalB);
    reporte += QString("<br>");

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

QGraphicsScene *VigaSimplementeApoyada::generarDiagrama(Diagrama diagrama)
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

QGraphicsScene *VigaSimplementeApoyada::generarDiagrama(Diagrama diagrama, QList<double> &valoresInferiores, QList<double> &valoresSupoeriores, QList<double> &seccionesArmaduraInferiores, QList<double> &seccionesArmarudaSuperiores)
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
        acumulado += valor * escala;
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

double VigaSimplementeApoyada::obtenerMinimo(Diagrama diagrama)
{
    switch (diagrama)
    {
    case Diagrama::corte:
        return obtenerValor(diagrama, _idMinCorte);
    case Diagrama::momentoFlector:
        return obtenerValor(diagrama, _idMinMomento);
    default:
        return 0.;
    }
}

double VigaSimplementeApoyada::obtenerMinimo(QList<double> &valores)
{
    double minimo = 1e308;
    foreach (double valor, valores)
    {
        minimo = (valor < minimo) ? valor : minimo;
    }
    return minimo;
}

double VigaSimplementeApoyada::obtenerMaximo(QList<double> &valores)
{
    double maximo = -1e308;
    foreach (double valor, valores)
    {
        maximo = (valor > maximo) ? valor : maximo;
    }
    return maximo;
}

double VigaSimplementeApoyada::obtenerMaximo(Diagrama diagrama)
{
    switch (diagrama)
    {
    case Diagrama::corte:
        return obtenerValor(diagrama, _idMaxCorte);
    case Diagrama::momentoFlector:
        return obtenerValor(diagrama, _idMaxMomento);
    default:
        return 0.;
    }
}

double VigaSimplementeApoyada::obtenerValor(Diagrama diagrama, int i)
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

void VigaSimplementeApoyada::setPosicionApoyoIzquierdo(double posicion)
{
    _posicionApoyoIzquierdo = posicion;
}

void VigaSimplementeApoyada::setPosicionApoyoDerecho(double posicion)
{
    _posicionApoyoDerecho = posicion;
}

void VigaSimplementeApoyada::setLongitud(double value)
{
    _longitud = value;
}

double VigaSimplementeApoyada::longitud()
{
    return _longitud;
}

double VigaSimplementeApoyada::reaccionVerticalDerecha()
{
    return _reaccionVerticalB;
}

double VigaSimplementeApoyada::reaccionVerticalIzquierda()
{
    return _reaccionVerticalA;
}
