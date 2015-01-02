#include "dlgeditvigacontinua.h"
#include "ui_dlgeditvigacontinua.h"
#include "dlgnuevoapoyo.h"
#include <algorithm>

DlgEditVigaContinua::DlgEditVigaContinua(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEditVigaContinua)
{
    ui->setupUi(this);
}

DlgEditVigaContinua::~DlgEditVigaContinua()
{
    delete ui;
}

void DlgEditVigaContinua::on_btnAgregarApoyo_released()
{
    DlgNuevoApoyo dlg;
    dlg.setPosicion(0.);
    if (dlg.exec() == QDialog::Accepted)
    {
        ui->lstApoyos->addItem(QString::number(dlg.posicion()));
    }
}

void DlgEditVigaContinua::on_lstApoyos_itemDoubleClicked(QListWidgetItem *item)
{
    delete item;
}

void DlgEditVigaContinua::setLongitud(double longitud)
{
    ui->txtLongitud->setText(QString::number(longitud));
}

void DlgEditVigaContinua::setApoyos(QList<double> &posiciones)
{
    ui->lstApoyos->clear();
    foreach (double posicion, posiciones)
    {
        ui->lstApoyos->addItem(QString::number(posicion));
    }
}

double DlgEditVigaContinua::longitud()
{
    return ui->txtLongitud->text().toDouble();
}

QList<double> DlgEditVigaContinua::apoyos()
{
    QList<double> result;
    for (int i = 0; i < ui->lstApoyos->count(); ++i)
    {
        result.append(ui->lstApoyos->item(i)->text().toDouble());
    }
    std::sort(result.begin(), result.end());
    return result;
}
