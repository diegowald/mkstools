#include "dlgedittopologia.h"
#include "ui_dlgedittopologia.h"
#include "dlgeditorsolicitaciones.h"
#include <QVariant>
#include <QListWidgetItem>
#include "../factory.h"
#include "../model/esquemas_estructurales/esquemaestructural.h"
#include "../model/secciones/seccion.h"
#include "dlgdiagramas.h"
#include "dlgsetarmadurasfelxion.h"

dlgEditTopologia::dlgEditTopologia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgEditTopologia)
{
    ui->setupUi(this);
    llenarSecciones();
    llenarEsquemasEstructurales();
    llenarMateriales();
    llenarMetodosCalculo();
}

dlgEditTopologia::~dlgEditTopologia()
{
    delete ui;
}

void dlgEditTopologia::setcurrentEsquema(EsquemaEstructuralPtr esquema)
{
    _esquemaPrevio = esquema;
    if (!esquema.isNull())
    {
        _esquema = esquema->clone();
    }
}

void dlgEditTopologia::setCurrentSeccion(SeccionPtr seccion)
{
    _seccionPrevia = seccion;
    if (!seccion.isNull())
    {
        _seccion = seccion->clone();
    }
}

void dlgEditTopologia::on_btnDetailsEsquemas_released()
{
    if (_esquema.isNull() || ui->cboEsquemasEstructurales->currentText() != _esquema->name())
    {
        crearEsquema();
    }
    _esquema->edit();
}

void dlgEditTopologia::on_btnDetailsSection_released()
{
    if (_seccion.isNull() || ui->cboSecciones->currentText() != _seccion->name())
    {
        crearSeccion();
    }
    _seccion->edit();
}

void dlgEditTopologia::crearEsquema()
{
    _esquema = Factory::crearEsquemaEstructural(ui->cboEsquemasEstructurales->currentText());
}

void dlgEditTopologia::crearSeccion()
{
    _seccion = Factory::crearSeccion(ui->cboSecciones->currentText());
}

void dlgEditTopologia::on_btnAddSolicitacion_released()
{
    DlgEditorSolicitaciones dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        SolicitacionPtr solicitacion = dlg.solicitacion();
        QListWidgetItem *item = new QListWidgetItem(ui->listSolicitaciones);
        item->setText(solicitacion->name());
        QVariant v;
        v.setValue(solicitacion);
        item->setData(Qt::UserRole, v);
        ui->listSolicitaciones->addItem(item);
    }
}

void dlgEditTopologia::on_listSolicitaciones_itemDoubleClicked(QListWidgetItem *item)
{
    SolicitacionPtr solicitacion = item->data(Qt::UserRole).value<SolicitacionPtr>();
}

SeccionPtr dlgEditTopologia::seccion()
{
    if (_seccion.isNull())
    {
        crearSeccion();
    }
    return _seccion;
}

EsquemaEstructuralPtr dlgEditTopologia::esquemaEstructural()
{
    if (_esquema.isNull())
    {
        crearEsquema();
    }
    return _esquema;
}

void dlgEditTopologia::setSolicitaciones(QList<SolicitacionPtr> &listaSolicitaciones)
{
    ui->listSolicitaciones->clear();
    foreach (SolicitacionPtr solicitacion, listaSolicitaciones)
    {
        QListWidgetItem *item = new QListWidgetItem(ui->listSolicitaciones);
        item->setText(solicitacion->name());
        QVariant v;
        v.setValue(solicitacion);
        item->setData(Qt::UserRole, v);
    }
}

QList<SolicitacionPtr> dlgEditTopologia::solicitaciones()
{
    QList<SolicitacionPtr> lista;
    for (int i = 0; i < ui->listSolicitaciones->count(); ++i)
    {
        QListWidgetItem* item = ui->listSolicitaciones->item(i);
        lista.append(item->data(Qt::UserRole).value<SolicitacionPtr>());
    }
    return lista;
}

void dlgEditTopologia::llenarSecciones()
{
    ui->cboSecciones->clear();
    ui->cboSecciones->addItems(Factory::secciones());
}

void dlgEditTopologia::llenarEsquemasEstructurales()
{
    ui->cboEsquemasEstructurales->clear();
    ui->cboEsquemasEstructurales->addItems(Factory::esquemasEstructurales());
}

void dlgEditTopologia::llenarMateriales()
{
    ui->cboMaterial->clear();
    ui->cboMaterial->addItems(Factory::materiales(TipoMaterial::todos));
}

void dlgEditTopologia::llenarMetodosCalculo()
{
    ui->cboMetodoCalculo->clear();
    ui->cboMetodoCalculo->addItems(Factory::metodosCalculo());
}

void dlgEditTopologia::crearMaterial()
{
    _material = Factory::crearMaterial(ui->cboMaterial->currentText());
}

void dlgEditTopologia::crearMetodoCalculo()
{
    _metodoCalculo = Factory::crearMetodoCalculo(ui->cboMetodoCalculo->currentText());
}

void dlgEditTopologia::setMaterial(MaterialPtr material)
{
    _material = material;
}

void dlgEditTopologia::setMetodoCalculo(MetodoCalculoPtr metodoCalculo)
{
    _metodoCalculo = metodoCalculo;
}

MaterialPtr dlgEditTopologia::material()
{
    if (_material.isNull())
    {
        crearMaterial();
    }
    return _material;
}

MetodoCalculoPtr dlgEditTopologia::metodoCalculo()
{
    if (_metodoCalculo.isNull())
    {
        crearMetodoCalculo();
    }
    return _metodoCalculo;
}

void dlgEditTopologia::on_btnDiagramas_released()
{
    DlgDiagramas dlg;
    dlg.setData(_seccion, _esquema, _material, _metodoCalculo);
    dlg.exec();
}

void dlgEditTopologia::on_btnArmadura_released()
{
    DlgSetArmadurasFelxion dlg;
    dlg.setData(_metodoCalculo);
    dlg.exec();
}
