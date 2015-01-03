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

private slots:
    void on_cboEsquemasEstructurales_currentTextChanged(const QString &arg1);

    void on_cboSecciones_currentTextChanged(const QString &arg1);

private:
    void llenarSecciones();
    void llenarEsquemasEstructurales();
    void llenarMateriales();
    void llenarMetodosCalculo();
    void crearEsquema();
    void crearSeccion();

private:
    Ui::WidgetTipologia *ui;
    QWidget *_widgetSeccion;
    QWidget *_widgetEsquemaEstructural;
    SeccionPtr _seccionPrevia;
    SeccionPtr _seccion;
    EsquemaEstructuralPtr _esquemaPrevio;
    EsquemaEstructuralPtr _esquema;
    MaterialPtr _material;
    MetodoCalculoPtr _metodoCalculo;

};

#endif // WIDGETTIPOLOGIA_H
