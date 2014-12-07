#ifndef DLGEDITHORMIGONARMADO_H
#define DLGEDITHORMIGONARMADO_H

#include <QDialog>
#include "../model/materiales/material.h"

namespace Ui {
class DlgEditHormigonArmado;
}

class DlgEditHormigonArmado : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEditHormigonArmado(QWidget *parent = 0);
    ~DlgEditHormigonArmado();
    
    void setAcero(MaterialPtr mat);
    void setHormigon(MaterialPtr mat);
    MaterialPtr acero();
    MaterialPtr hormigon();
private slots:
    void on_btnDetallesAcero_released();    
    void on_btnDetallesHormigon_released();
    
private:
    void llenarAceros();
    void llenarHormigones();
    void crearAcero();
    void crearHormigon();
private:
    Ui::DlgEditHormigonArmado *ui;
    MaterialPtr _acero;
    MaterialPtr _hormigon;
};

#endif // DLGEDITHORMIGONARMADO_H
