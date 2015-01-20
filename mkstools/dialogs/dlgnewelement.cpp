#include "dlgnewelement.h"
#include "ui_dlgnewelement.h"
#include "../factory.h"
#include "../widgets/widgettipologia.h"
#include "../model/elemento.h"
#include "../dialogs/dlgdiagramas.h"
#include "../dialogs/dlgsetarmadurasfelxion.h"
#include "../dialogs/dlgresults.h"
#include <QTextFrame>

DlgNewElement::DlgNewElement(ElementoPtr elemento, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewElement)
{
    ui->setupUi(this);
    _editWidget = NULL;
    //_elemento = elemento;
    _elemento.clear();
    crearTiposEstructurales();
    setElemento(elemento);
}

DlgNewElement::~DlgNewElement()
{
    delete ui;
}

void DlgNewElement::on_cboType_currentTextChanged(const QString &arg1)
{
    if (_elemento.isNull())
    {
        return;
    }
    if (_elemento->tipologia().isNull() || _elemento->tipologia()->name() != arg1)
    {
        if (_editWidget != NULL)
        {
            _editWidget->hide();
            ui->verticalLayout_3->removeWidget(_editWidget);
            _editWidget->deleteLater();
        }
        TipologiaPtr tipologia = Factory::crearTipologia(arg1);
        _elemento->setTipologia(tipologia);
        _editWidget = tipologia->getEditWidget();
        _editWidget->setParent(ui->frame);
        ui->verticalLayout_3->addWidget(_editWidget);
    }
}

void DlgNewElement::setElemento(ElementoPtr elemento)
{
    _elemento = elemento->clone();
    ui->txtName->setText(elemento->name());
    QString tipo = _elemento->tipologia()->name();
    ui->cboType->setCurrentIndex(ui->cboType->findText(_elemento->tipologia()->name()));
    if (_editWidget != NULL)
    {
        _editWidget->hide();
        ui->verticalLayout_3->removeWidget(_editWidget);
        _editWidget->deleteLater();
    }
    _editWidget = _elemento->tipologia()->getEditWidget();
    _editWidget->setParent(ui->frame);
    ui->verticalLayout_3->addWidget(_editWidget);
}

ElementoPtr DlgNewElement::elemento()
{
    _elemento->setName(ui->txtName->text());
    return _elemento;
}

void DlgNewElement::crearTiposEstructurales()
{
    ui->cboType->clear();
    ui->cboType->addItems(Factory::tipologias());
}

void DlgNewElement::on_btnDiagramas_released()
{
    _elemento->calcular();
    DlgDiagramas dlg;
    TipologiaPtr tipologia = _elemento->tipologia();
    dlg.setData(tipologia->seccion(),
                tipologia->esquemaEstructural(),
                tipologia->material(),
                tipologia->metodoCalculo());
    dlg.exec();
}

void DlgNewElement::on_btnArmadura_released()
{
    _elemento->calcular();
    DlgSetArmadurasFelxion dlg;
    dlg.setData(_elemento->tipologia()->metodoCalculo());
    dlg.exec();
}

void DlgNewElement::on_btnReporte_released()
{
    _elemento->calcular();
    DlgResults dlg;
    _elemento->crearReporte(dlg.textEdit());
    QTextCursor cursor = dlg.textEdit()->textCursor();
    cursor.movePosition(QTextCursor::PreviousBlock, QTextCursor::MoveAnchor, 0);
    dlg.exec();
}

void DlgNewElement::on_txtName_textEdited(const QString &arg1)
{
    _elemento->setName(arg1);
}
