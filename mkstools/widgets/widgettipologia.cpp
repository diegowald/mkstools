#include "widgettipologia.h"
#include "ui_widgettipologia.h"
#include "../factory.h"
#include "../model/esquemas_estructurales/esquemaestructural.h"
#include "../model/secciones/seccion.h"
#include "../dialogs/dlgeditorsolicitaciones.h"
#include "../model/tipologias/tipologia.h"
#include "../model/esquemas_estructurales/esquemaestructural.h"
#include "../model/materiales/material.h"
#include "../model/metodosCalculo/metodocalculo.h"


WidgetTipologia::WidgetTipologia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetTipologia)
{
    ui->setupUi(this);
    _widgetSeccion = NULL;
    _widgetEsquemaEstructural = NULL;
    _tipologia = Factory::crearTipologiaPorDefecto();
    llenarSecciones();
    llenarEsquemasEstructurales();
    llenarMateriales();
    llenarMetodosCalculo();
}

WidgetTipologia::~WidgetTipologia()
{
    delete ui;
}

void WidgetTipologia::llenarSecciones()
{
    ui->cboSecciones->clear();
    ui->cboSecciones->addItems(Factory::secciones());
}

void WidgetTipologia::llenarEsquemasEstructurales()
{
    ui->cboEsquemasEstructurales->clear();
    ui->cboEsquemasEstructurales->addItems(Factory::esquemasEstructurales());
}

void WidgetTipologia::llenarMateriales()
{
    ui->cboMaterial->clear();
    ui->cboMaterial->addItems(Factory::materiales(TipoMaterial::todos));
}

void WidgetTipologia::llenarMetodosCalculo()
{
    ui->cboMetodoCalculo->clear();
    ui->cboMetodoCalculo->addItems(Factory::metodosCalculo());
}

void WidgetTipologia::on_cboEsquemasEstructurales_currentTextChanged(const QString &arg1)
{
    (void) arg1;
    if (_widgetEsquemaEstructural != NULL)
    {
        _widgetEsquemaEstructural->hide();
        ui->verticalLayout->removeWidget(_widgetEsquemaEstructural);
        _widgetEsquemaEstructural->deleteLater();
    }
    if (_esquema.isNull() || ui->cboEsquemasEstructurales->currentText() != _esquema->name())
    {
        crearEsquema();
        _widgetEsquemaEstructural = _esquema->getEditWidget();
        _widgetEsquemaEstructural->setParent(ui->frameEsquemaEstructural);
        ui->verticalLayout->addWidget(_widgetEsquemaEstructural);
    }
}

void WidgetTipologia::on_cboSecciones_currentTextChanged(const QString &arg1)
{
    (void) arg1;
    if (_widgetSeccion != NULL)
    {
        _widgetSeccion->hide();
        ui->verticalLayout_2->removeWidget(_widgetSeccion);
        _widgetSeccion->deleteLater();
    }
    if (_seccion.isNull() || ui->cboSecciones->currentText() != _seccion->name())
    {
        crearSeccion();
        _widgetSeccion = _seccion->getEditWidget();
        _widgetSeccion->setParent(ui->frameSeccion);
        ui->verticalLayout_2->addWidget(_widgetSeccion);
    }
}

void WidgetTipologia::crearEsquema()
{
    if (ui->cboEsquemasEstructurales->currentText() != _tipologia->esquemaEstructural()->name())
    {
        _tipologia->setEsquemaEstructural(Factory::crearEsquemaEstructural(ui->cboEsquemasEstructurales->currentText()));
    }
    _esquema = _tipologia->esquemaEstructural();
}

void WidgetTipologia::crearSeccion()
{
    if (ui->cboSecciones->currentText() != _tipologia->seccion()->name())
    {
        _tipologia->setSeccion(Factory::crearSeccion(ui->cboSecciones->currentText()));
    }
    _seccion = _tipologia->seccion();
}

void WidgetTipologia::crearMaterial()
{
    if (ui->cboMaterial->currentText() != _tipologia->material()->name())
    {
        _tipologia->setMaterial(Factory::crearMaterial(ui->cboMaterial->currentText()));
    }
    _material = _tipologia->material();
}

void WidgetTipologia::crearMetodoCalculo()
{
    if (ui->cboMetodoCalculo->currentText() != _tipologia->metodoCalculo()->name())
    {
        _tipologia->setMetodoCalculo(Factory::crearMetodoCalculo(ui->cboMetodoCalculo->currentText()));
    }
    _metodoCalculo = _tipologia->metodoCalculo();
}

void WidgetTipologia::setTipologia(TipologiaPtr tipologia)
{
    _tipologia = tipologia;
    ui->cboEsquemasEstructurales->setCurrentIndex(ui->cboEsquemasEstructurales->findText(_tipologia->esquemaEstructural()->name()));
    ui->cboMaterial->setCurrentIndex(ui->cboMaterial->findText(_tipologia->material()->name()));
    ui->cboMetodoCalculo->setCurrentIndex(ui->cboMetodoCalculo->findText(_tipologia->metodoCalculo()->name()));
    ui->cboSecciones->setCurrentIndex(ui->cboSecciones->findText(_tipologia->seccion()->name()));
}

void WidgetTipologia::on_btnAddSolicitacion_released()
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

void WidgetTipologia::on_cboMaterial_currentTextChanged(const QString &arg1)
{
    (void) arg1;
    if (_material.isNull() || ui->cboMaterial->currentText() != _material->name())
    {
        crearMaterial();
    }
}

void WidgetTipologia::on_cboMetodoCalculo_currentTextChanged(const QString &arg1)
{
    (void) arg1;
    if (_metodoCalculo.isNull() || ui->cboMetodoCalculo->currentText() != _metodoCalculo->name())
    {
        crearMetodoCalculo();
    }
}
