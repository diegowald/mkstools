#include "esfuerzointerno.h"

EsfuerzoInterno::EsfuerzoInterno(QObject *parent)
    : Base("esfuerzo interno", parent), _momento(0.0), _normal(0.0), _corte(0.0), _pos(0.0)
{

}

EsfuerzoInterno::~EsfuerzoInterno()
{

}

void EsfuerzoInterno::setMomento(double value)
{
    _momento = value;
}

void EsfuerzoInterno::setNormal(double value)
{
    _normal = value;
}

void EsfuerzoInterno::setCorte(double value)
{
    _corte = value;
}

void EsfuerzoInterno::setPos(double value)
{
    _pos = value;
}

double EsfuerzoInterno::momento() const
{
    return _momento;
}

double EsfuerzoInterno::normal() const
{
    return _normal;
}

double EsfuerzoInterno::corte() const
{
    return _corte;
}

double EsfuerzoInterno::pos() const
{
    return _pos;
}


QString EsfuerzoInterno::description()
{
    return QString("<h5>Esfuerzos internos:</h5><br>Posición: %1<br>Momento: %2<br>Normal: %3<br>Corte: %4<br>")
            .arg(_pos).arg(_momento).arg(_normal).arg(_corte);
}

QString EsfuerzoInterno::reporteCalculo()
{
    QString reporte = QString("Posición: %1 cm<br>").arg(_pos);
    reporte += QString("Momento: %1 tcm<br>").arg(_momento);
    reporte += QString("Esfuerzo normal: %1 t<br>").arg(_normal);
    reporte += QString("Esfuerzo de corte: %1 t<br>").arg(_corte);
    return reporte;
}
