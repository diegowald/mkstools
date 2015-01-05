#include "voladizo.h"
#include "../../dialogs/dlgeditvoladizo.h"
#include "../../widgets/widgeteditvoladizo.h"
#include "../solicitaciones/solicitacion.h"
#include "../esfuerzos_internos/esfuerzointerno.h"
#include <QDebug>

Voladizo::Voladizo(QObject *parent) :
    EsquemaEstructural("voladizo", parent), QEnableSharedFromThis()
{
    _longitud = 0.;
    _reaccionVertical = 0.;
    _reaccionHorizontal = 0.;
    _momentoEmpotramiento = 0.;
    _empotramientoUbicadoALaIzquierda = true;
    _esfuerzosInternos.clear();
    _idMinMomento = 0;
    _idMaxMomento = 0;
    _idMinCorte = 0;
    _idMaxCorte = 0;
}

Voladizo::~Voladizo()
{

}



EsquemaEstructuralPtr Voladizo::clone()
{
    VoladizoPtr viga = VoladizoPtr(new Voladizo());
    viga->_longitud = _longitud;
    viga->_empotramientoUbicadoALaIzquierda = _empotramientoUbicadoALaIzquierda;
    return viga;
}

QString Voladizo::description()
{
    return QString("<h5>Viga en voladizo.</h5><br>Luz: %1 cm.<br>Empotramiento ubicado a la %2.<br>")
            .arg(_longitud)
            .arg(_empotramientoUbicadoALaIzquierda ? "izquierda" : "derecha");
}

void Voladizo::edit()
{
    DlgEditVoladizo dlg;
    dlg.setLongitud(_longitud);
    dlg.setEmpotramiento(_empotramientoUbicadoALaIzquierda);
    if (dlg.exec() == QDialog::Accepted)
    {
        _longitud = dlg.longitud();

        _empotramientoUbicadoALaIzquierda = dlg.empotramientoEstaALaIzquierda();
    }
}

QWidget *Voladizo::getEditWidget()
{
    WidgetEditVoladizo *widget = new WidgetEditVoladizo();
    widget->setViga(sharedFromThis());
    return widget;
}

void Voladizo::calcularReacciones(const QList<SolicitacionPtr> &solicitaciones)
{
    double momentos = 0.;
    double cargas = 0.;
    foreach (SolicitacionPtr solicitacion, solicitaciones)
    {
        momentos += solicitacion->momento(_empotramientoUbicadoALaIzquierda ? 0 : _longitud);
        cargas += solicitacion->resultanteY();
    }
    _reaccionHorizontal = 0.;
    _reaccionVertical = -cargas;
    _momentoEmpotramiento = -momentos;
}

void Voladizo::calcularEsfuerzosInternos(const QList<SolicitacionPtr> &solicitaciones)
{
    double momentoPto = 0.;
    double cortePto = 0.;
    _esfuerzosInternos.clear();
    for (double x = 0.0; x <= _longitud; x += 1.)
    {
        if (_empotramientoUbicadoALaIzquierda)
        {
            momentoPto = _reaccionVertical * x + _momentoEmpotramiento;
            cortePto = _reaccionVertical;
        }
        foreach (SolicitacionPtr s, solicitaciones)
        {
            momentoPto += s->momentoIzquierda(x);
            cortePto += s->corteIzquierda(x);
        }

        qDebug() << momentoPto << ", " << cortePto;
        EsfuerzoInternoPtr esfuerzo = EsfuerzoInternoPtr::create();
        esfuerzo->setMomento(momentoPto);
        esfuerzo->setCorte(cortePto);
        esfuerzo->setNormal(0.0);
        esfuerzo->setPos(x);
        _esfuerzosInternos.append(esfuerzo);
    }
}

void Voladizo::calcularMaximosEsfuerzos()
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

double Voladizo::minMomento() const
{
    return _esfuerzosInternos[_idMinMomento]->momento();
}

double Voladizo::posMinMomento() const
{
    return _esfuerzosInternos[_idMinMomento]->pos();
}

double Voladizo::maxMomento() const
{
    return _esfuerzosInternos[_idMaxMomento]->momento();
}

double Voladizo::posMaxMomento() const
{
    return _esfuerzosInternos[_idMaxMomento]->pos();
}

double Voladizo::maxCorte() const
{
    return _esfuerzosInternos[_idMaxCorte]->corte();
}

double Voladizo::posMinCorte() const
{
    return _esfuerzosInternos[_idMaxCorte]->pos();
}

double Voladizo::minCorte() const
{
    return _esfuerzosInternos[_idMinCorte]->corte();
}

double Voladizo::posMaxCorte() const
{
    return _esfuerzosInternos[_idMinCorte]->pos();
}


QVarLengthArray<EsfuerzoInternoPtr, 1024> Voladizo::esfuerzosInternos()
{
    return _esfuerzosInternos;
}

QString Voladizo::reporteCalculo()
{
    QString reporte = QString("<h4>Cálculo de reacciones</h4><br>");

    reporte += QString("Reacción horizontal: %1 t.<br>").arg(_reaccionHorizontal);
    reporte += QString("Reacción vertical: %1 t.<br>").arg(_reaccionVertical);
    reporte += QString("Momento de empotramiento: %1 tcm.<br>").arg(_momentoEmpotramiento);
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

QGraphicsScene *Voladizo::generarDiagrama(Diagrama diagrama)
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

QGraphicsScene *Voladizo::generarDiagrama(Diagrama diagrama, QList<double> &valoresInferiores, QList<double> &valoresSupoeriores, QList<double> &seccionesArmaduraInferiores, QList<double> &seccionesArmarudaSuperiores)
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

double Voladizo::obtenerMinimo(QList<double> &valores)
{
    double minimo = 1e308;
    foreach (double valor, valores)
    {
        minimo = (valor < minimo) ? valor : minimo;
    }
    return minimo;
}

double Voladizo::obtenerMaximo(QList<double> &valores)
{
    double maximo = -1e308;
    foreach (double valor, valores)
    {
        maximo = (valor > maximo) ? valor : maximo;
    }
    return maximo;
}

double Voladizo::obtenerValor(Diagrama diagrama, int i)
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

double Voladizo::longitud()
{
    return _longitud;
}

bool Voladizo::empotramientoUbicadoALaIzquierda()
{
    return _empotramientoUbicadoALaIzquierda;
}

void Voladizo::setLongitud(double value)
{
    _longitud = value;
}

void Voladizo::setEmpotramientoUbicadoALaIzquierda(bool value)
{
    _empotramientoUbicadoALaIzquierda = value;
}
