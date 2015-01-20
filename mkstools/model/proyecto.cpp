#include "proyecto.h"
#include <QDebug>
#include "elemento.h"
#include "dialogs/dlgnewelement.h"
#include <QTextFrame>

Proyecto::Proyecto(const QString &name, QObject *parent) :
    Base(name, parent)
{
}

Proyecto::~Proyecto()
{
}

void Proyecto::addElemento(ElementoPtr elemento)
{
    if (_elementos.contains(elemento->name()))
    {
        qDebug() << "Error, existe un elemento con ese nombre";
    }
    else
    {
        _elementos[elemento->name()] = elemento;
    }
}

ElementoPtr Proyecto::editElemento(const QString &name)
{
    ElementoPtr elemento = _elementos[name];
    DlgNewElement dlg(elemento);
    dlg.setElemento(elemento);
    if (dlg.exec() == QDialog::Accepted)
    {
        elemento = dlg.elemento();
    }
    return elemento;
}


QString Proyecto::description()
{
    return QString("Proyecto: %1").arg(name());
}

void Proyecto::calcular()
{
    foreach (QString key, _elementos.keys())
    {
        _elementos[key]->calcular();
    }
}

QString Proyecto::reporteCalculo()
{
    QString reporte =
    "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />"
    "<title>Reporte de Cálculo</title>"
    "<style type=\"text/css\">"
    "p, li { white-space: pre-wrap; }"
    "</style></head>"
    "<body style=\" font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">";

    reporte += "<h1>Reporte de Calculo</h1>";

    reporte += "<h2>" + description() + "</h2>";

    foreach (QString key, _elementos.keys())
    {
        reporte += _elementos[key]->reporteCalculo();
        reporte += "<br>";
    }

    reporte +="</body></html>";
    return reporte;
}


void Proyecto::crearReporte(QTextEdit *textEdit)
{
    textEdit->clear();
    QTextCursor c = textEdit->document()->rootFrame()->firstCursorPosition();

    c.insertHtml(
                "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />"
                "<title>Reporte de Cálculo</title>"
                "<style type=\"text/css\">"
                "p, li { white-space: pre-wrap; }"
                "</style></head>"
                "<body style=\" font-size:9pt; font-weight:400; font-style:normal; text-decoration:none;\">");

    c.insertHtml("<h1>Reporte de Calculo</h1>");

    c.insertHtml("<h2>" + description() + "</h2>");

    foreach (QString key, _elementos.keys())
    {
        _elementos[key]->crearReporte(textEdit);
        c.insertHtml("<br>");
    }

    c.insertHtml("</body></html>");
}
