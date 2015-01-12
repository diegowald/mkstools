#include "tipologia.h"
#include "dialogs/dlgedittopologia.h"
#include "model/esquemas_estructurales/esquemaestructural.h"
#include "model/secciones/seccion.h"
#include "model/solicitaciones/solicitacion.h"
#include "model/materiales/material.h"
#include "model/metodosCalculo/metodocalculo.h"
#include "factory.h"
#include <QTextFrame>

Tipologia::Tipologia(const QString &name, QObject *parent) :
    Base(name, parent)
{
    _solicitaciones.clear();
    _esquemaEstructural = Factory::crearEsquemaEstructuralPorDefecto();
    _material = Factory::crearMaterialPorDefecto();
    _metodoCalculo = Factory::crearMetodoCalculoPorDefecto();
    _seccion = Factory::crearSeccionPorDefecto();
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

void Tipologia::crearReporte(QTextEdit *textEdit)
{
    QTextCursor c = textEdit->document()->rootFrame()->lastCursorPosition();
    c.insertHtml("<h5>" + description() + "</h5>");
    c.insertHtml("<br>");
    _esquemaEstructural->crearReporte(textEdit);
    c.insertHtml("<br>");
    _seccion->crearReporte(textEdit);
    c.insertHtml("<br>");
    _material->crearReporte(textEdit);
    c.insertHtml("<br>");
    foreach (SolicitacionPtr solicitacion, _solicitaciones)
    {
        solicitacion->crearReporte(textEdit);
        c.insertHtml("<br>");
    }
    _metodoCalculo->crearReporte(textEdit);
}

QString Tipologia::tipo()
{
    return _esquemaEstructural->name();
}

bool Tipologia::calculoOK()
{
    return _metodoCalculo->calculado();
}

MaterialPtr Tipologia::material()
{
    return _material;
}

MetodoCalculoPtr Tipologia::metodoCalculo()
{
    return _metodoCalculo;
}

EsquemaEstructuralPtr Tipologia::esquemaEstructural()
{
    return _esquemaEstructural;
}

SeccionPtr Tipologia::seccion()
{
    return _seccion;
}

void Tipologia::setMaterial(MaterialPtr value)
{
    _material = value;
}

void Tipologia::setMetodoCalculo(MetodoCalculoPtr value)
{
    _metodoCalculo = value;
}

void Tipologia::setEsquemaEstructural(EsquemaEstructuralPtr value)
{
    _esquemaEstructural = value;
}

void Tipologia::setSeccion(SeccionPtr value)
{
    _seccion = value;
}

void Tipologia::setSolicitaciones(QList<SolicitacionPtr> &solicitaciones)
{
    _solicitaciones.clear();
    _solicitaciones.append(solicitaciones);
}

QList<SolicitacionPtr> Tipologia::solicitaciones()
{
    return _solicitaciones;
}
