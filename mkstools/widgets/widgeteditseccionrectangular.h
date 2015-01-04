#ifndef WIDGETEDITSECCIONRECTANGULAR_H
#define WIDGETEDITSECCIONRECTANGULAR_H

#include <QWidget>
#include "../model/forward.h"

namespace Ui {
class WidgetEditSeccionRectangular;
}

class WidgetEditSeccionRectangular : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetEditSeccionRectangular(QWidget *parent = 0);
    ~WidgetEditSeccionRectangular();

    void setSeccion(SeccionRectangular* seccion);

private slots:
    void on_txtBase_textEdited(const QString &arg1);

    void on_txtAltura_textEdited(const QString &arg1);

    void on_txtArmaduraInferior_textEdited(const QString &arg1);

    void on_txtArmaduraSuperior_textEdited(const QString &arg1);

    void on_txtRecubrimientoInferior_textEdited(const QString &arg1);

    void on_txtRecubrimientoSuperior_textEdited(const QString &arg1);

private:
    void setBase(double value);
    void setAltura(double value);
    void setArmaduraInferior(double value);
    void setArmaduraSuperior(double value);
    double base() const;
    double altura() const;
    double armaduraInferior() const;
    double armaduraSuperior() const;
    void setRecubrimientoInferior(double value);
    void setRecubrimientoSuperior(double value);
    double recubrimientoInferior() const;
    double recubrimientoSuperior() const;

private:
    Ui::WidgetEditSeccionRectangular *ui;
    SeccionRectangular* _seccion;
};

#endif // WIDGETEDITSECCIONRECTANGULAR_H
