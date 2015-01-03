#include "dlgnewelement.h"
#include "ui_dlgnewelement.h"
#include "../factory.h"
#include "../widgets/widgettipologia.h"

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

QString DlgNewElement::name()
{
    return ui->txtName->text();
}

QString DlgNewElement::tipo()
{
    return ui->cboType->currentText();
}


void DlgNewElement::crearTiposEstructurales()
{
    ui->cboType->clear();
    ui->cboType->addItems(Factory::tipologias());
}

void DlgNewElement::on_cboType_currentTextChanged(const QString &arg1)
{
    if (_editWidget != NULL)
    {
        _editWidget->deleteLater();
    }
    if (arg1 == "viga")
    {
        _editWidget = new WidgetTipologia();
        ui->verticalLayout_3->addWidget(_editWidget);
    }
}
