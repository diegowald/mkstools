#include "dlgeditvigasimplementeapoyada.h"
#include "ui_dlgeditvigasimplementeapoyada.h"

DlgEditVigaSimplementeApoyada::DlgEditVigaSimplementeApoyada(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEditVigaSimplementeApoyada)
{
    ui->setupUi(this);
}

DlgEditVigaSimplementeApoyada::~DlgEditVigaSimplementeApoyada()
{
    delete ui;
}

void DlgEditVigaSimplementeApoyada::setLongitud(double value)
{
    ui->lineEdit->setText(QString::number(value));
}

double DlgEditVigaSimplementeApoyada::longitud() const
{
    return ui->lineEdit->text().toDouble();
}
