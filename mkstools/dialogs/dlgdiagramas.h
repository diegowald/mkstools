#ifndef DLGDIAGRAMAS_H
#define DLGDIAGRAMAS_H

#include <QDialog>
#include "../model/forward.h"
#include "../model/esquemas_estructurales/esquemaestructural.h"

namespace Ui {
class DlgDiagramas;
}

class DlgDiagramas : public QDialog
{
    Q_OBJECT

public:
    explicit DlgDiagramas(QWidget *parent = 0);
    ~DlgDiagramas();

    void setData(SeccionPtr seccion, EsquemaEstructuralPtr esquema, MaterialPtr material, MetodoCalculoPtr metodoCalculo);

    virtual void showEvent(QShowEvent *evt);
private:
    void redraw(Diagrama diagrama);

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::DlgDiagramas *ui;
    SeccionPtr _seccion;
    EsquemaEstructuralPtr _esquema;
    MaterialPtr _material;
    MetodoCalculoPtr _metodoCalculo;
};

#endif // DLGDIAGRAMAS_H
