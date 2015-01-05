#ifndef WIDGETTIPOLOGIA_H
#define WIDGETTIPOLOGIA_H

#include <QWidget>
#include "../model/forward.h"

namespace Ui {
class WidgetTipologia;
}

class WidgetTipologia : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTipologia(QWidget *parent = 0);
    ~WidgetTipologia();

    void setTipologia(TipologiaPtr tipologia);

private slots:
    void on_cboEsquemasEstructurales_currentTextChanged(const QString &arg1);

    void on_cboSecciones_currentTextChanged(const QString &arg1);

    void on_btnAddSolicitacion_released();

    void on_cboMaterial_currentTextChanged(const QString &arg1);

    void on_cboMetodoCalculo_currentTextChanged(const QString &arg1);

    void on_btnDiagramas_released();

    void on_btnArmadura_released();

    void on_btnReporte_released();

private:
    void llenarSecciones();
    void llenarEsquemasEstructurales();
    void llenarMateriales();
    void llenarMetodosCalculo();
    void crearEsquema();
    void crearSeccion();
    void crearMaterial();
    void crearMetodoCalculo();
    QList<SolicitacionPtr> solicitaciones();

private:
    Ui::WidgetTipologia *ui;
    QWidget *_widgetSeccion;
    QWidget *_widgetEsquemaEstructural;
//    SeccionPtr _seccionPrevia;
//    SeccionPtr _seccion;
//    EsquemaEstructuralPtr _esquemaPrevio;
//    EsquemaEstructuralPtr _esquema;
//    MaterialPtr _material;
//    MetodoCalculoPtr _metodoCalculo;
    TipologiaPtr _tipologia;
};

#endif // WIDGETTIPOLOGIA_H
