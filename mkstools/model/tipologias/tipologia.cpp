#include "tipologia.h"
#include "dialogs/dlgedittopologia.h"

Tipologia::Tipologia(const QString &name, QObject *parent) :
    Base(name, parent)
{
    _tipoSeccion = "";
    _tipoEsquema = "";
}

Tipologia::~Tipologia()
{
}

void Tipologia::edit()
{
    dlgEditTopologia dlg;
    dlg.setSecciones(getValidSeccionTypes());
    dlg.setEsquemasEstructurales(getValidEsquemaEstructuralTypes());
    dlg.setCurrentSeccion(_seccion);
    dlg.setcurrentEsquema(_esquemaEstructural);
    dlg.setSolicitaciones(_solicitaciones);
    if (dlg.exec() == QDialog::Accepted)
    {
        _seccion = dlg.seccion();
        _esquemaEstructural = dlg.esquemaEstructural();
        _solicitaciones = dlg.solicitaciones();
    }
}
