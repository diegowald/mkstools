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
    HormigonArmadoPtr ha = HormigonArmadoPtr::create();
    ha->_acero = qobject_cast<AceroPtr>(_acero->clone());
    ha->_hormigon = qobject_cast<HormigonPtr>(_hormigon->clone());
    return ha;
}

double HormigonArmado::E() const
{
    return 0.;
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

void HormigonArmado::setAcero(AceroPtr acero)
{
    _acero = acero;
}

void HormigonArmado::setHormigon(HormigonPtr hormigon)
{
    _hormigon = hormigon;
}

QString HormigonArmado::description()
{
    return QString("<h4>Hormigón armado</h4><br>%1<br>%2")
            .arg(_hormigon->description())
            .arg(_acero->description());
}


double HormigonArmado::tensionAdmisibleTraccion() const
{
    return 0.;
}

double HormigonArmado::tensionAdmisibleCompresion() const
{
    return 0.;
}

double HormigonArmado::tensionRoturaTraccion() const
{
    return  0.;
}

double HormigonArmado::tensionRoturaCompresion() const
{
    return 0.;
}
