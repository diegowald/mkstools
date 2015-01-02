#include "dlgnuevoapoyo.h"
#include "ui_dlgnuevoapoyo.h"

DlgNuevoApoyo::DlgNuevoApoyo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNuevoApoyo)
{
    ui->setupUi(this);
}

DlgNuevoApoyo::~DlgNuevoApoyo()
{
    delete ui;
}

void DlgNuevoApoyo::setPosicion(double pos)
{
    ui->txtPosicion->setText(QString::number(pos));
}

double DlgNuevoApoyo::posicion()
{
    return ui->txtPosicion->text().toDouble();
}
