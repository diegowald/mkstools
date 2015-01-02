#include "cargapuntual.h"
#include "../../dialogs/dlgcargapuntual.h"

CargaPuntual::CargaPuntual(QObject *parent) :
    Solicitacion("carga puntual", parent)
{
    _fuerzaX = 0.;
    _fuerzaY = 0.;
    _posAplicacion = 0.;
}


QSharedPointer<Solicitacion> CargaPuntual::clone()
{
    CargaPuntualPtr c = CargaPuntualPtr::create();
    c->_fuerzaX = _fuerzaX;
    c->_fuerzaY = _fuerzaY;
    c->_posAplicacion = _posAplicacion;
    return c;
}

double CargaPuntual::momentoIzquierda(double pos)
{
    if (pos < _posAplicacion)
    {
        return 0.;
    }
    return _fuerzaY * (pos - _posAplicacion);
}

double CargaPuntual::momentoDerecha(double pos)
{
    if (pos > _posAplicacion)
    {
        return 0.;
    }
    return -_fuerzaY * (_posAplicacion - pos);
}

double CargaPuntual::momento(double pos)
{
    return _fuerzaY * (pos - _posAplicacion);
}

double CargaPuntual::corteIzquierda(double pos)
{
    if (pos < _posAplicacion)
    {
        return 0;
    }
    return _fuerzaY;
}

double CargaPuntual::resultanteX()
{
    return _fuerzaX;
}

double CargaPuntual::resultanteY()
{
    return _fuerzaY;
}


void CargaPuntual::edit()
{
    DlgCargaPuntual dlg;
    dlg.setPosicion(_posAplicacion);
    dlg.setFuerzaX(_fuerzaX);
    dlg.setFuerzaY(_fuerzaY);
    if (dlg.exec() == QDialog::Accepted)
    {
        _posAplicacion = dlg.posicion();
        _fuerzaX = dlg.fuerzaX();
        _fuerzaY = dlg.fuerzaY();
    }
}


void CargaPuntual::calcularSolicitacion(SeccionPtr seccion, EsquemaEstructuralPtr esquemaEstructural)
{
    (void) seccion;
    (void) esquemaEstructural;
}


QString CargaPuntual::description()
{
    return QString("<h5>Carga Puntual</h5><br>Fuerza horizontal: %1 t<br>Fuerza vertical %2 t<br>Posición: %3 cm<br>")
            .arg(_fuerzaX)
            .arg(_fuerzaY)
            .arg(_posAplicacion);
}

void CargaPuntual::trasladarOrigen(double nuevoOrigen, double maxLongitud)
{
    _posAplicacion -= nuevoOrigen;
    if ((_posAplicacion < 0) || (_posAplicacion > maxLongitud))
    {
        _fuerzaX = 0.;
        _fuerzaY = 0.;
    }
}
