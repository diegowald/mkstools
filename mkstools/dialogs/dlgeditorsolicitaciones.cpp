#include "dlgeditorsolicitaciones.h"
#include "ui_dlgeditorsolicitaciones.h"
#include "../model/solicitaciones/cargapuntual.h"
#include "../model/solicitaciones/cargauniformeconstante.h"

DlgEditorSolicitaciones::DlgEditorSolicitaciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEditorSolicitaciones)
{
    ui->setupUi(this);
    llenarSolicitaciones();
}

DlgEditorSolicitaciones::~DlgEditorSolicitaciones()
{
    delete ui;
}

void DlgEditorSolicitaciones::on_btnEditar_released()
{
    if (_solicitacion.isNull() || ui->cboTipoSolicitaciones->currentText() != _solicitacion->name())
    {
        crearSolicitacion();
    }
    _solicitacion->edit();
}


SolicitacionPtr DlgEditorSolicitaciones::solicitacion()
{
    return _solicitacion;
}

void DlgEditorSolicitaciones::setSolicitacion(SolicitacionPtr solicitacin)
{
    _solicitacion = solicitacin;
}

void DlgEditorSolicitaciones::llenarSolicitaciones()
{
    ui->cboTipoSolicitaciones->clear();
    ui->cboTipoSolicitaciones->addItem("carga puntual");
    ui->cboTipoSolicitaciones->addItem("carga uniformemente distribuida");
}

void DlgEditorSolicitaciones::crearSolicitacion()
{
    QString name = ui->cboTipoSolicitaciones->currentText();
    if (name == "carga puntual")
    {
        _solicitacion = CargaPuntualPtr::create();
    }
    else if (name == "carga uniformemente distribuida")
    {
        _solicitacion = CargaUniformeConstantePtr::create();
    }
}
