#include "cargauniformeconstante.h"
#include "../../dialogs/dlgeditcargauniformedistribuida.h"
#include <QTextFrame>

CargaUniformeConstante::CargaUniformeConstante(QObject *parent) :
    Solicitacion("carga uniforme constante", parent)
{
    _cargaX = 0.;
    _cargaY = 0.;
    _posInicio = 0.;
    _posFinal = 0.;
}


QSharedPointer<Solicitacion> CargaUniformeConstante::clone()
{
    CargaUniformeConstantePtr c = CargaUniformeConstantePtr::create();
    c->_cargaX = _cargaX;
    c->_cargaY = _cargaY;
    c->_posInicio = _posInicio;
    c->_posFinal = _posFinal;
    return c;
}

double CargaUniformeConstante::momentoIzquierda(double pos)
{
    if (pos < _posInicio)
    {
        return 0.;
    }

    double l0 = _posInicio;
    double l1 = _posFinal > pos ? pos : _posFinal;
    double delta = l1 - l0;

    double momento = _cargaY * delta * delta / 2.0;
    return momento;
}

double CargaUniformeConstante::momentoDerecha(double pos)
{
    if (pos > _posFinal)
    {
        return 0.;
    }

    double l0 = _posInicio < pos ? pos : _posInicio;
    double l1 = _posFinal;

    double delta = l1 - l0;

    double momento = - _cargaY * delta * (delta / 2);
    return momento;
}

double CargaUniformeConstante::momento(double pos)
{
    double centroCarga = (_posFinal + _posInicio) / 2;
    double longitud = _posFinal - _posInicio;
    double momento = _cargaY * longitud * (pos - centroCarga);
    return momento;
}

double CargaUniformeConstante::corteIzquierda(double pos)
{
    if (pos < _posInicio)
    {
        return 0;
    }
    double l0 = _posInicio;
    double l1 = _posFinal > pos ? pos : _posFinal;

    double corte = _cargaY * (l1 - l0);

    return corte;
}

double CargaUniformeConstante::corteDerecha(double pos)
{
    if (pos > _posFinal)
    {
        return 0;
    }

    double l0 = _posInicio > pos ? _posInicio : pos;
    double l1 = _posFinal;

    double corte = -_cargaY * (l1 - l0);

    return corte;
}

double CargaUniformeConstante::resultanteX()
{
    return _cargaX * (_posFinal - _posInicio);
}

double CargaUniformeConstante::resultanteY()
{
    return _cargaY * (_posFinal - _posInicio);
}

void CargaUniformeConstante::edit()
{
    DlgEditCargaUniformeDistribuida dlg;
    dlg.setPosicionInicial(_posInicio);
    dlg.setPosicionFinal(_posFinal);
    dlg.setCargaX(_cargaX);
    dlg.setCargaY(_cargaY);
    if (dlg.exec() == QDialog::Accepted)
    {
        _posInicio = dlg.posicionInicial();
        _posFinal = dlg.posicionFinal();
        _cargaX = dlg.cargaX();
        _cargaY = dlg.cargaY();
    }
}


void CargaUniformeConstante::calcularSolicitacion(SeccionPtr seccion, EsquemaEstructuralPtr esquemaEstructural)
{
    (void) seccion;
    (void) esquemaEstructural;
}


QString CargaUniformeConstante::description()
{
    return QString("<h5>Carga Uniforme</h5><br>Carga X: %1 t/cm<br>Carga Y: %2 t/cm<br>Posición inicial: %3 cm<br>Posicion final: %4cm<br>")
            .arg(_cargaX)
            .arg(_cargaY)
            .arg(_posInicio)
            .arg(_posFinal);
}

void CargaUniformeConstante::crearReporte(QTextEdit *textEdit)
{
    QTextCursor c = textEdit->document()->rootFrame()->lastCursorPosition();
    c.insertHtml(description());
}

void CargaUniformeConstante::trasladarOrigen(double nuevoOrigen, double maxLongitud)
{
    _posInicio -= nuevoOrigen;
    _posInicio = (_posInicio < 0.) ? 0. : _posInicio;
    _posFinal -= nuevoOrigen;
    double longitud = maxLongitud - nuevoOrigen;
    _posFinal = (_posFinal < longitud) ? _posFinal : longitud;
    _posFinal = (_posFinal < 0.) ? 0. : _posFinal;
}
