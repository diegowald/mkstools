#include "dlgdiagramas.h"
#include "ui_dlgdiagramas.h"
#include "../model/metodosCalculo/metodocalculo.h"

DlgDiagramas::DlgDiagramas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgDiagramas)
{
    ui->setupUi(this);
}

DlgDiagramas::~DlgDiagramas()
{
    delete ui;
}

void DlgDiagramas::on_comboBox_currentTextChanged(const QString &arg1)
{
    Diagrama diagrama;
    if (arg1 == "Esfuerzo Normal N")
    {
        diagrama = Diagrama::normal;
    }
    else if (arg1 == "Esfuerzo de corte Q")
    {
        diagrama = Diagrama::corte;
    }
    else if (arg1 == "Momento Flector M")
    {
        diagrama = Diagrama::momentoFlector;
    }
    else
    {
        diagrama = Diagrama::solicitaciones;
    }

    redraw(diagrama);
}


void DlgDiagramas::setData(SeccionPtr seccion, EsquemaEstructuralPtr esquema, MaterialPtr material, MetodoCalculoPtr metodoCalculo)
{
    _seccion = seccion;
    _esquema = esquema;
    _material = material;
    _metodoCalculo = metodoCalculo;
}

void DlgDiagramas::showEvent(QShowEvent *evt)
{
    QDialog::showEvent(evt);
    Diagrama diagrama;
    QString diagramaSeleccionado = ui->comboBox->currentText();
    if (diagramaSeleccionado == "Esfuerzo Normal N")
    {
        diagrama = Diagrama::normal;
    }
    else if (diagramaSeleccionado == "Esfuerzo de corte Q")
    {
        diagrama = Diagrama::corte;
    }
    else if (diagramaSeleccionado == "Momento Flector M")
    {
        diagrama = Diagrama::momentoFlector;
    }
    else
    {
        diagrama = Diagrama::solicitaciones;
    }
    redraw(diagrama);
}

void DlgDiagramas::redraw(Diagrama diagrama)
{
    QGraphicsScene *scene = _metodoCalculo->generarDiagrama(diagrama);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(0, 0, scene->width() * 1.3, scene->height() * 1.3, Qt::KeepAspectRatio);
    scene->setParent(ui->graphicsView);
}
