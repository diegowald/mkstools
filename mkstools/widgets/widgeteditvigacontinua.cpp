#include "widgeteditvigacontinua.h"
#include "ui_widgeteditvigacontinua.h"
#include "../dialogs/dlgnuevoapoyo.h"

WidgetEditVigaContinua::WidgetEditVigaContinua(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetEditVigaContinua)
{
    ui->setupUi(this);
}

WidgetEditVigaContinua::~WidgetEditVigaContinua()
{
    delete ui;
}

void WidgetEditVigaContinua::on_btnAgregarApoyo_released()
{
    DlgNuevoApoyo dlg;
    dlg.setPosicion(0.);
    if (dlg.exec() == QDialog::Accepted)
    {
        ui->lstApoyos->addItem(QString::number(dlg.posicion()));
    }
}

void WidgetEditVigaContinua::setLongitud(double longitud)
{
    ui->txtLongitud->setText(QString::number(longitud));
}

void WidgetEditVigaContinua::setApoyos(QList<double> &posiciones)
{
    ui->lstApoyos->clear();
    foreach (double posicion, posiciones)
    {
        ui->lstApoyos->addItem(QString::number(posicion));
    }
}

double WidgetEditVigaContinua::longitud()
{
    return ui->txtLongitud->text().toDouble();
}

QList<double> WidgetEditVigaContinua::apoyos()
{
    QList<double> result;
    for (int i = 0; i < ui->lstApoyos->count(); ++i)
    {
        result.append(ui->lstApoyos->item(i)->text().toDouble());
    }
    std::sort(result.begin(), result.end());
    return result;
}

void WidgetEditVigaContinua::on_lstApoyos_itemDoubleClicked(QListWidgetItem *item)
{
    delete item;
}
