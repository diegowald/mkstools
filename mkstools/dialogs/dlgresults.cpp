#include "dlgresults.h"
#include "ui_dlgresults.h"
#include <QtPrintSupport/QtPrintSupport>

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

/*void DlgResults::setReporte(const QString &html)
{
    ui->textEdit->setHtml(html);
}*/

QTextEdit *DlgResults::textEdit()
{
    return ui->textEdit;
}

void DlgResults::on_btnPdf_released()
{
    QString filename = "./resultado.pdf";

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filename);

    ui->textEdit->print(&printer);
}
