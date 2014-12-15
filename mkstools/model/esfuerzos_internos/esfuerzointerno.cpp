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
