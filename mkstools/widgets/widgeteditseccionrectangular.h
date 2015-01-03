#ifndef WIDGETEDITSECCIONRECTANGULAR_H
#define WIDGETEDITSECCIONRECTANGULAR_H

#include <QWidget>

namespace Ui {
class WidgetEditSeccionRectangular;
}

class WidgetEditSeccionRectangular : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetEditSeccionRectangular(QWidget *parent = 0);
    ~WidgetEditSeccionRectangular();

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
};

#endif // WIDGETEDITSECCIONRECTANGULAR_H
