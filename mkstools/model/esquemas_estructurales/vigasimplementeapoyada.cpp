#include "vigasimplementeapoyada.h"
#include "../../dialogs/dlgeditvigasimplementeapoyada.h"
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
}

VigaSimplementeApoyada::~VigaSimplementeApoyada()
{
}

void VigaSimplementeApoyada::edit()
{
    DlgEditVigaSimplementeApoyada dlg;
    dlg.setLongitud(_longitud);
    if (dlg.exec() == QDialog::Accepted)
    {
        _longitud = dlg.longitud();
    }
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
        momentos += solicitacion->momentoIzquierda(_longitud);
        cargas += solicitacion->corteIzquierda(_longitud);
    }
    _reaccionHorizontalA = 0.;
    _reaccionVerticalA = momentos / _longitud;
    _reaccionHorizontalB = 0.;
    _reaccionVerticalB = cargas - _reaccionVerticalA;
}

void VigaSimplementeApoyada::calcularEsfuerzosInternos(const QList<SolicitacionPtr> &solicitaciones)
{
    double momentoPto = 0.;
    double cortePto = 0.;
    _esfuerzosInternos.clear();
    for (double x = 0.0; x <= _longitud; x += 1.)
    {
        momentoPto = _reaccionVerticalA * x;
        cortePto = _reaccionVerticalA;
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
    double _maxMomento = std::numeric_limits<double>::min();
    double _maxCorte = std::numeric_limits<double>::min();
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
