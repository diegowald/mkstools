#include "dlgedithormigonarmado.h"
#include "ui_dlgedithormigonarmado.h"
#include "../factory.h"
#include "../model/materiales/material.h"

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
    if (_acero.isNull())
    {
        crearAcero();
    }
    return _acero;
}

MaterialPtr DlgEditHormigonArmado::hormigon()
{
    if (_hormigon.isNull())
    {
        crearHormigon();
    }
    return _hormigon;
}

void DlgEditHormigonArmado::llenarAceros()
{
    ui->cboAcero->clear();
    ui->cboAcero->addItems(Factory::materiales(TipoMaterial::acero));
}

void DlgEditHormigonArmado::llenarHormigones()
{
    ui->cboHormigon->clear();
    ui->cboHormigon->addItems(Factory::materiales(TipoMaterial::hormigon));
}

void DlgEditHormigonArmado::crearAcero()
{
    _acero = Factory::crearMaterial(ui->cboAcero->currentText());
}

void DlgEditHormigonArmado::crearHormigon()
{
    _hormigon = Factory::crearMaterial(ui->cboHormigon->currentText());
}
