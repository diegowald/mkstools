#include "material.h"
#include "../../dialogs/dlgeditacero.h"

Material::Material(const QString &name, QObject *parent) :
    Base(name, parent)
{
    _tensionTraccion = 0.;
    _tensionCompresion = 0.;
    _E = 0;
}

Material::~Material()
{
}

void Material::edit()
{
    DlgEditMaterial dlg;
    dlg.setTensionTraccion(_tensionTraccion);
    dlg.setTensionCompresion(_tensionCompresion);
    dlg.setModuloElasticidad(_E);
    if (dlg.exec() == QDialog::Accepted)
    {
        _tensionTraccion = dlg.tensionTraccion();
        _tensionCompresion = dlg.tensionCompresion();
        _E = dlg.moduloElasticidad();
    }
}
