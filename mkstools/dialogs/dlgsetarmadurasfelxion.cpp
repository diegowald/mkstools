#include "dlgsetarmadurasfelxion.h"
#include "ui_dlgsetarmadurasfelxion.h"
#include "../model/metodosCalculo/metodocalculo.h"
#include <math.h>

DlgSetArmadurasFelxion::DlgSetArmadurasFelxion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSetArmadurasFelxion)
{
    ui->setupUi(this);
    ui->lblTotalHierroInferior->setText("");
    ui->lblTotalHierroSuperior->setText("");
    llenarCombosDiametros();
}

DlgSetArmadurasFelxion::~DlgSetArmadurasFelxion()
{
    delete ui;
}

void DlgSetArmadurasFelxion::on_btnAgregarHierroSuperior_released()
{
    ui->lstHierroSuperior->addItem(ui->cboHierrosSuperiores->currentText());
    redraw();
}

void DlgSetArmadurasFelxion::on_btnAgregarHierroInferior_released()
{
    ui->lstHierroInferior->addItem(ui->cboHierrosInferiores->currentText());
    redraw();
}

void DlgSetArmadurasFelxion::llenarCombosDiametros()
{
    ui->cboHierrosInferiores->clear();
    ui->cboHierrosSuperiores->clear();
    QStringList list;
    list << "6" << "8" << "10" << "12" << "16" << "20" << "25";
    ui->cboHierrosInferiores->addItems(list);
    ui->cboHierrosSuperiores->addItems(list);
}

void DlgSetArmadurasFelxion::setData(MetodoCalculoPtr metodoCalculo)
{
    _metodoCalculo = metodoCalculo;
}

void DlgSetArmadurasFelxion::redraw()
{
    QList<double> armadurasInferiores, armadurasSuperiores;

    for (int i = 0; i < ui->lstHierroInferior->count(); ++i)
    {
        QListWidgetItem *item = ui->lstHierroInferior->item(i);
        armadurasInferiores.append(area(item->text().toDouble() / 10));
    }

    for (int i = 0; i < ui->lstHierroSuperior->count(); ++i)
    {
        QListWidgetItem *item = ui->lstHierroSuperior->item(i);
        armadurasSuperiores.append(area(item->text().toDouble() / 10));
    }

    QGraphicsScene *scene = _metodoCalculo->generarDiagrama(Diagrama::armaduraFlexion, armadurasInferiores, armadurasSuperiores);
    ui->graficoArmadura->setScene(scene);
    ui->graficoArmadura->fitInView(0, 0, scene->width() * 1.3, scene->height() * 1.3, Qt::IgnoreAspectRatio);
    scene->setParent(ui->graficoArmadura);
}

void DlgSetArmadurasFelxion::showEvent(QShowEvent *evt)
{
    QDialog::showEvent(evt);
    redraw();
}

double DlgSetArmadurasFelxion::area(double diametro)
{
    return diametro * diametro * M_PI / 4;
}

void DlgSetArmadurasFelxion::on_lstHierroSuperior_itemDoubleClicked(QListWidgetItem *item)
{
    delete item;
    redraw();
}

void DlgSetArmadurasFelxion::on_lstHierroInferior_itemDoubleClicked(QListWidgetItem *item)
{
    delete item;
    redraw();
}
