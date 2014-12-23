#ifndef DLGDIAGRAMAS_H
#define DLGDIAGRAMAS_H

#include <QDialog>
#include "../model/forward.h"

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
