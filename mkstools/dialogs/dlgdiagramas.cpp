#include "dlgdiagramas.h"
#include "ui_dlgdiagramas.h"
#include "../model/esquemas_estructurales/esquemaestructural.h"
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

    QGraphicsScene *scene = _metodoCalculo->generarDiagrama(diagrama);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(0, 0, scene->width() * 1.3, scene->height() * 1.3, Qt::KeepAspectRatio);
    scene->setParent(ui->graphicsView);
}


void DlgDiagramas::setData(SeccionPtr seccion, EsquemaEstructuralPtr esquema, MaterialPtr material, MetodoCalculoPtr metodoCalculo)
{
    _seccion = seccion;
    _esquema = esquema;
    _material = material;
    _metodoCalculo = metodoCalculo;
}
