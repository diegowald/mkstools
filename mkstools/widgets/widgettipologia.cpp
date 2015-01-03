#include "widgettipologia.h"
#include "ui_widgettipologia.h"
#include "../factory.h"
#include "../model/esquemas_estructurales/esquemaestructural.h"
#include "../model/secciones/seccion.h"

WidgetTipologia::WidgetTipologia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetTipologia)
{
    ui->setupUi(this);
    _widgetSeccion = NULL;
    _widgetEsquemaEstructural = NULL;
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
    if (_widgetEsquemaEstructural != NULL)
    {
        _widgetEsquemaEstructural->deleteLater();
    }
    if (_esquema.isNull() || ui->cboEsquemasEstructurales->currentText() != _esquema->name())
    {
        crearEsquema();
        _widgetEsquemaEstructural = _esquema->getEditWidget();
        ui->verticalLayout->addWidget(_widgetEsquemaEstructural);
    }
}

void WidgetTipologia::on_cboSecciones_currentTextChanged(const QString &arg1)
{
    if (_widgetSeccion != NULL)
    {
        _widgetSeccion->deleteLater();
    }
    if (_seccion.isNull() || ui->cboSecciones->currentText() != _seccion->name())
    {
        crearSeccion();
        _widgetSeccion = _seccion->getEditWidget();
        ui->verticalLayout_2->addWidget(_widgetSeccion);
    }
}

void WidgetTipologia::crearEsquema()
{
    _esquema = Factory::crearEsquemaEstructural(ui->cboEsquemasEstructurales->currentText());
}

void WidgetTipologia::crearSeccion()
{
    _seccion = Factory::crearSeccion(ui->cboSecciones->currentText());
}
