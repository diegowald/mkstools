#include "dlgedittopologia.h"
#include "ui_dlgedittopologia.h"
#include "../model/esquemas_estructurales/vigasimplementeapoyada.h"
#include "../model/secciones/seccionrectangular.h"
#include "dlgeditorsolicitaciones.h"
#include "../model/solicitaciones/solicitacion.h"
#include <QVariant>

dlgEditTopologia::dlgEditTopologia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgEditTopologia)
{
    ui->setupUi(this);
}

dlgEditTopologia::~dlgEditTopologia()
{
    delete ui;
}

void dlgEditTopologia::setSecciones(const QStringList &secciones)
{
    ui->cboSecciones->addItems(secciones);
}

void dlgEditTopologia::setEsquemasEstructurales(const QStringList &esquemas)
{
    ui->cboEsquemasEstructurales->addItems(esquemas);
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
    QString esquemaSeleccionado = ui->cboEsquemasEstructurales->currentText();
    if (esquemaSeleccionado == "simplemente apoyada")
    {
        _esquema = VigaSimplementeApoyadaPtr::create();
    }
}

void dlgEditTopologia::crearSeccion()
{
    QString seccionSeleccionada = ui->cboSecciones->currentText();
    if (seccionSeleccionada == "rectangular")
    {
        _seccion = SeccionRectangularPtr::create();
    }
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
