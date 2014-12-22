#include "dlgresults.h"
#include "ui_dlgresults.h"

DlgResults::DlgResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgResults)
{
    ui->setupUi(this);
}

DlgResults::~DlgResults()
{
    delete ui;
}

void DlgResults::setReporte(const QString &html)
{
    ui->textEdit->setHtml(html);
}
