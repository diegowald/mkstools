#include "hormigonarmado.h"
#include "../../dialogs/dlgedithormigonarmado.h"

HormigonArmado::HormigonArmado(QObject *parent) :
    Material("hormigon armado", parent)
{
}

HormigonArmado::~HormigonArmado()
{
}

QSharedPointer<Material> HormigonArmado::clone()
{
    return HormigonArmadoPtr::create();
}

double HormigonArmado::tensionTraccion() const
{
}

double HormigonArmado::tensionCompression() const
{
}

double HormigonArmado::E() const
{
}

void HormigonArmado::edit()
{
    DlgEditHormigonArmado dlg;
    dlg.setAcero(_acero);
    dlg.setHormigon(_hormigon);
    if (dlg.exec() == QDialog::Accepted)
    {
        _acero = qobject_cast<AceroPtr>(dlg.acero());
        _hormigon = qobject_cast<HormigonPtr>(dlg.hormigon());
    }
}

HormigonPtr HormigonArmado::hormigon()
{
    return _hormigon;
}

AceroPtr HormigonArmado::acero()
{
    return _acero;
}
