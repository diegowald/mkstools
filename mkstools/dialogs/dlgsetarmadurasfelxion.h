#ifndef DLGSETARMADURASFELXION_H
#define DLGSETARMADURASFELXION_H

#include <QDialog>
#include "../model/forward.h"
#include <QListWidgetItem>

namespace Ui {
class DlgSetArmadurasFelxion;
}

class DlgSetArmadurasFelxion : public QDialog
{
    Q_OBJECT

public:
    explicit DlgSetArmadurasFelxion(QWidget *parent = 0);
    ~DlgSetArmadurasFelxion();
    void setData(MetodoCalculoPtr metodoCalculo);

    virtual void showEvent(QShowEvent *evt);
private:
    void llenarCombosDiametros();
    void redraw();
    double area(double diametro);

private slots:
    void on_btnAgregarHierroSuperior_released();

    void on_btnAgregarHierroInferior_released();

    void on_lstHierroSuperior_itemDoubleClicked(QListWidgetItem *item);

    void on_lstHierroInferior_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::DlgSetArmadurasFelxion *ui;
    MetodoCalculoPtr _metodoCalculo;
};

#endif // DLGSETARMADURASFELXION_H
