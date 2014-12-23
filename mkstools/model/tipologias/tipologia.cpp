#include "tipologia.h"
#include "dialogs/dlgedittopologia.h"
#include "model/esquemas_estructurales/esquemaestructural.h"
#include "model/secciones/seccion.h"
#include "model/solicitaciones/solicitacion.h"
#include "model/materiales/material.h"
#include "model/metodosCalculo/metodocalculo.h"

Tipologia::Tipologia(const QString &name, QObject *parent) :
    Base(name, parent)
{
    _tipoSeccion = "";
    _tipoEsquema = "";
    _solicitaciones.clear();
}

Tipologia::~Tipologia()
{
}

void Tipologia::edit()
{
    dlgEditTopologia dlg;
    dlg.setCurrentSeccion(_seccion);
    dlg.setcurrentEsquema(_esquemaEstructural);
    dlg.setSolicitaciones(_solicitaciones);
    dlg.setMaterial(_material);
    dlg.setMetodoCalculo(_metodoCalculo);
    if (dlg.exec() == QDialog::Accepted)
    {
        _seccion = dlg.seccion();
        _esquemaEstructural = dlg.esquemaEstructural();
        _solicitaciones = dlg.solicitaciones();
        _material = dlg.material();
        _metodoCalculo = dlg.metodoCalculo();
    }
}


QString Tipologia::description()
{
    QString solicitaciones("");
    foreach (SolicitacionPtr solicitacion, _solicitaciones)
    {
        solicitaciones += solicitacion->description();
    }
    return QString("Tipología: %1\nEsquema Estructural: %2\nSección: %3\nSolicitaciones: %4\nMaterial: %5\nMétodo de Cálculo: %6")
            .arg(_esquemaEstructural->description())
            .arg(_seccion->description())
            .arg(solicitaciones)
            .arg(_material->description())
            .arg(_metodoCalculo->description());
}

QString Tipologia::reporteCalculo()
{
    QString reporte = description();
    reporte += _esquemaEstructural->description() + "<br>";
    reporte += _seccion->description() + "<br>";
    reporte += _material->description() + "<br>";
    foreach (SolicitacionPtr solicitacion, _solicitaciones)
    {
        reporte += solicitacion->description() + "<br>";
    }
    reporte += "<br>" + _metodoCalculo->reporteCalculo();
    return reporte;
}

QString Tipologia::tipo()
{
    return _esquemaEstructural->name();
}

QString Tipologia::material()
{
    return _material->name();
}

QString Tipologia::metodoCalculo()
{
    return _metodoCalculo->name();
}

bool Tipologia::calculoOK()
{
    return _metodoCalculo->calculado();
}

QString Tipologia::esquemaEstructural()
{
    return _esquemaEstructural->name();
}

QString Tipologia::seccion()
{
    return _seccion->name();
}
