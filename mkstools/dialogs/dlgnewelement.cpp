#include "dlgnewelement.h"
#include "ui_dlgnewelement.h"
#include "../factory.h"
#include "../widgets/widgettipologia.h"
#include "../model/elemento.h"

DlgNewElement::DlgNewElement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewElement)
{
    ui->setupUi(this);
    _editWidget = NULL;
    crearTiposEstructurales();
}

DlgNewElement::~DlgNewElement()
{
    delete ui;
}

void DlgNewElement::on_cboType_currentTextChanged(const QString &arg1)
{
    if (_tipologia.isNull() || _tipologia->name() != arg1)
    {
        if (_editWidget != NULL)
        {
            _editWidget->hide();
            ui->verticalLayout_3->removeWidget(_editWidget);
            _editWidget->deleteLater();
        }
        _tipologia = Factory::crearTipologia(arg1);
        _editWidget = _tipologia->getEditWidget();
        _editWidget->setParent(ui->frame);
        ui->verticalLayout_3->addWidget(_editWidget);
    }
}

void DlgNewElement::setElemento(ElementoPtr elemento)
{
    _elemento = elemento;
    ui->txtName->setText(elemento->name());
    QString tipo = _elemento->tipologia()->name();
    ui->cboType->setCurrentIndex(ui->cboType->findText(_elemento->tipologia()->name()));
    _tipologia = _elemento->tipologia()->clone();
    if (_editWidget != NULL)
    {
        _editWidget->hide();
        ui->verticalLayout_3->removeWidget(_editWidget);
        _editWidget->deleteLater();
    }
    _editWidget = _tipologia->getEditWidget();
    _editWidget->setParent(ui->frame);
    ui->verticalLayout_3->addWidget(_editWidget);
}

ElementoPtr DlgNewElement::elemento()
{
    _elemento->setName(ui->txtName->text());
    _elemento->setTipologia(_tipologia);
    return _elemento;
}

void DlgNewElement::crearTiposEstructurales()
{
    ui->cboType->clear();
    ui->cboType->addItems(Factory::tipologias());
}
