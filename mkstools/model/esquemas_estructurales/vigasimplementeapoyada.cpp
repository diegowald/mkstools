#include "vigasimplementeapoyada.h"
#include "../../dialogs/dlgeditvigasimplementeapoyada.h"

VigaSimplementeApoyada::VigaSimplementeApoyada(QObject *parent) :
    EsquemaEstructural("simplemente apoyada", parent)
{
    _longitud = 1.;
}

VigaSimplementeApoyada::~VigaSimplementeApoyada()
{
}

void VigaSimplementeApoyada::edit()
{
    DlgEditVigaSimplementeApoyada dlg;
    dlg.setLongitud(_longitud);
    if (dlg.exec() == QDialog::Accepted)
    {
        _longitud = dlg.longitud();
    }
}

EsquemaEstructuralPtr VigaSimplementeApoyada::clone()
{
    VigaSimplementeApoyadaPtr viga = VigaSimplementeApoyadaPtr::create();
    viga->_longitud = _longitud;
    return viga;
}
