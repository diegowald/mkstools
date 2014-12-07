#include "dlgedithormigonarmado.h"
#include "ui_dlgedithormigonarmado.h"
#include "../model/materiales/acero.h"
#include "../model/materiales/hormigon.h"


DlgEditHormigonArmado::DlgEditHormigonArmado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEditHormigonArmado)
{
    ui->setupUi(this);
    llenarAceros();
    llenarHormigones();
}

DlgEditHormigonArmado::~DlgEditHormigonArmado()
{
    delete ui;
}

void DlgEditHormigonArmado::on_btnDetallesAcero_released()
{
    if (_acero.isNull() || ui->cboAcero->currentText() != _acero->name())
    {
        crearAcero();
    }
    _acero->edit();
}

void DlgEditHormigonArmado::on_btnDetallesHormigon_released()
{
    if (_hormigon.isNull() || ui->cboHormigon->currentText() != _hormigon->name())
    {
        crearHormigon();
    }
    _hormigon->edit();
}


void DlgEditHormigonArmado::setAcero(MaterialPtr mat)
{
    _acero = mat->clone();
}

void DlgEditHormigonArmado::setHormigon(MaterialPtr mat)
{
    _hormigon = mat->clone();
}

MaterialPtr DlgEditHormigonArmado::acero()
{
    return _acero;
}

MaterialPtr DlgEditHormigonArmado::hormigon()
{
    return _hormigon;
}

void DlgEditHormigonArmado::llenarAceros()
{
    ui->cboAcero->clear();
    ui->cboAcero->addItem("acero");
}

void DlgEditHormigonArmado::llenarHormigones()
{
    ui->cboHormigon->clear();
    ui->cboHormigon->addItem("hormigon");
}

void DlgEditHormigonArmado::crearAcero()
{
    QString a = ui->cboAcero->currentText();
    if (a == "acero")
    {
        _acero = AceroPtr::create();
    }
}

void DlgEditHormigonArmado::crearHormigon()
{
    QString h = ui->cboHormigon->currentText();
    if (h == "hormigon")
    {
        _hormigon = HormigonPtr::create();
    }
}
