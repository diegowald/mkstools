#include "seccionrectangular.h"
#include "../../dialogs/dlgeditseccionrectangular.h"

SeccionRectangular::SeccionRectangular(QObject *parent) :
    Seccion("seccion rectangular", parent)
{
    _areaAceroInferior = 0.;
    _areaAceroSuperior = 0.;
    _base = 0.;
    _altura = 0.;
}

SeccionRectangular::~SeccionRectangular()
{
}


QSharedPointer<Seccion> SeccionRectangular::clone()
{
    SeccionRectangularPtr s = SeccionRectangularPtr::create();
    s->_areaAceroInferior = _areaAceroInferior;
    s->_areaAceroSuperior = _areaAceroSuperior;
    s->_base =_base;
    s->_altura = _altura;
    return s;
}

double SeccionRectangular::area()
{
    return _base * _altura;
}

void SeccionRectangular::edit()
{
    DlgEditSeccionRectangular dlg;
    dlg.setBase(_base);
    dlg.setAltura(_altura);
    dlg.setArmaduraInferior(_areaAceroInferior);
    dlg.setArmaduraSuperior(_areaAceroSuperior);
    if (dlg.exec() == QDialog::Accepted)
    {
        _base = dlg.base();
        _altura = dlg.altura();
        _areaAceroInferior = dlg.armaduraInferior();
        _areaAceroSuperior = dlg.armaduraSuperior();
    }
}

double SeccionRectangular::areaAceroInferior() const
{
    return _areaAceroInferior;
}

double SeccionRectangular::areaAceroSuperior() const
{
    return _areaAceroSuperior;
}

double SeccionRectangular::base()
{
    return _base;
}

double SeccionRectangular::altura()
{
    return _altura;
}

void SeccionRectangular::setAreaAceroInferior(double value)
{
    _areaAceroInferior = value;
}

void SeccionRectangular::setAreaAceroSuperior(double value)
{
    _areaAceroSuperior = value;
}

void SeccionRectangular::setBase(double value)
{
    _base = value;
}

void SeccionRectangular::setAltura(double value)
{
    _altura = value;
}
