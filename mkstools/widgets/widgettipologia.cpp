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
#include "../dialogs/dlgdiagramas.h"
#include "../dialogs/dlgsetarmadurasfelxion.h"
#include "../dialogs/dlgresults.h"

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
        _widgetEsquemaEstructural = NULL;
    }

    if (_tipologia->esquemaEstructural().isNull() || ui->cboEsquemasEstructurales->currentText() != _tipologia->esquemaEstructural()->name())
    {
        crearEsquema();
    }
    if (_widgetEsquemaEstructural == NULL)
    {
        _widgetEsquemaEstructural = _tipologia->esquemaEstructural()->getEditWidget();
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
        _widgetSeccion = NULL;
    }
    if (_tipologia->seccion().isNull() || ui->cboSecciones->currentText() != _tipologia->seccion()->name())
    {
        crearSeccion();
    }
    if (_widgetSeccion == NULL)
    {
        _widgetSeccion = _tipologia->seccion()->getEditWidget();
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
}

void WidgetTipologia::crearSeccion()
{
    if (ui->cboSecciones->currentText() != _tipologia->seccion()->name())
    {
        _tipologia->setSeccion(Factory::crearSeccion(ui->cboSecciones->currentText()));
    }
}

void WidgetTipologia::crearMaterial()
{
    if (ui->cboMaterial->currentText() != _tipologia->material()->name())
    {
        _tipologia->setMaterial(Factory::crearMaterial(ui->cboMaterial->currentText()));
    }
}

void WidgetTipologia::crearMetodoCalculo()
{
    if (ui->cboMetodoCalculo->currentText() != _tipologia->metodoCalculo()->name())
    {
        _tipologia->setMetodoCalculo(Factory::crearMetodoCalculo(ui->cboMetodoCalculo->currentText()));
    }
}

void WidgetTipologia::setTipologia(TipologiaPtr tipologia)
{
    _tipologia = tipologia;
    ui->cboEsquemasEstructurales->setCurrentIndex(ui->cboEsquemasEstructurales->findText(_tipologia->esquemaEstructural()->name()));
    ui->cboMaterial->setCurrentIndex(ui->cboMaterial->findText(_tipologia->material()->name()));
    ui->cboMetodoCalculo->setCurrentIndex(ui->cboMetodoCalculo->findText(_tipologia->metodoCalculo()->name()));
    ui->cboSecciones->setCurrentIndex(ui->cboSecciones->findText(_tipologia->seccion()->name()));
}

QList<SolicitacionPtr> WidgetTipologia::solicitaciones()
{
    QList<SolicitacionPtr> lista;
    for (int i = 0; i < ui->listSolicitaciones->count(); ++i)
    {
        QListWidgetItem* item = ui->listSolicitaciones->item(i);
        lista.append(item->data(Qt::UserRole).value<SolicitacionPtr>());
    }
    return lista;
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
        QList<SolicitacionPtr> solics = solicitaciones();
        _tipologia->setSolicitaciones(solics);
    }
}

void WidgetTipologia::on_cboMaterial_currentTextChanged(const QString &arg1)
{
    (void) arg1;
    if (_tipologia->material().isNull() || ui->cboMaterial->currentText() != _tipologia->material()->name())
    {
        crearMaterial();
    }
}

void WidgetTipologia::on_cboMetodoCalculo_currentTextChanged(const QString &arg1)
{
    (void) arg1;
    if (_tipologia->metodoCalculo().isNull() || ui->cboMetodoCalculo->currentText() != _tipologia->metodoCalculo()->name())
    {
        crearMetodoCalculo();
    }
}

void WidgetTipologia::on_btnDiagramas_released()
{
    _tipologia->calcular();
    DlgDiagramas dlg;
    dlg.setData(_tipologia->seccion(),
                _tipologia->esquemaEstructural(),
                _tipologia->material(),
                _tipologia->metodoCalculo());
    dlg.exec();
}

void WidgetTipologia::on_btnArmadura_released()
{
    _tipologia->calcular();
    DlgSetArmadurasFelxion dlg;
    dlg.setData(_tipologia->metodoCalculo());
    dlg.exec();
}

void WidgetTipologia::on_btnReporte_released()
{
    _tipologia->calcular();
    DlgResults dlg;
    _tipologia->crearReporte(dlg.textEdit());
    dlg.exec();
}
