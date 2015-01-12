#include "material.h"
#include "../../dialogs/dlgeditacero.h"
#include <QTextFrame>


Material::Material(const QString &name, QObject *parent) :
    Base(name, parent)
{
    _tensionAdmisibleCompresion = 0.;
    _tensionAdmisibleTraccion = 0.;
    _tensionRoturaCompresion = 0.;
    _tensionRoturaTraccion = 0.;
    _E = 0;
}

Material::~Material()
{
}

void Material::edit()
{
    DlgEditMaterial dlg;
    dlg.setTensionAdmisibleTraccion(_tensionAdmisibleTraccion);
    dlg.setTensionAdmisibleCompresion(_tensionAdmisibleCompresion);
    dlg.setTensionRoturaCompresion(_tensionRoturaCompresion);
    dlg.setTensionRoturaTraccion(_tensionRoturaTraccion);
    dlg.setModuloElasticidad(_E);
    if (dlg.exec() == QDialog::Accepted)
    {
        _tensionAdmisibleTraccion = dlg.tensionAdmisibleTraccion();
        _tensionAdmisibleCompresion = dlg.tensionAdmisibleCompresion();
        _tensionRoturaTraccion = dlg.tensionRoturaTraccion();
        _tensionRoturaCompresion = dlg.tensionRoturaCompresion();
        _E = dlg.moduloElasticidad();
    }
}


QString Material::description()
{
    return QString("<h5>Material: %1</h5><br>Tensión Admisible Tracción: %2 t/cm2<br>Tensión Admisible Compresión %3 t/cm2<br>Tensión Rotura Tracción: %4 t/cm2<br>Tensión Rotura Compresión %5 t/cm2<br>Módulo de Elasticidad %6 t/cm2<br>")
            .arg(name())
            .arg(_tensionAdmisibleTraccion)
            .arg(_tensionAdmisibleCompresion)
            .arg(_tensionRoturaTraccion)
            .arg(_tensionRoturaCompresion)
            .arg(_E);
}

void Material::crearReporte(QTextEdit *textEdit)
{
    QTextCursor c = textEdit->document()->rootFrame()->lastCursorPosition();
    c.insertHtml(description());
}
