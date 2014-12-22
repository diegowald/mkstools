#include "dlgnewelement.h"
#include "ui_dlgnewelement.h"
#include "../factory.h"

DlgNewElement::DlgNewElement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewElement)
{
    ui->setupUi(this);
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
