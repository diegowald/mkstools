#ifndef WIDGETEDITVOLADIZO_H
#define WIDGETEDITVOLADIZO_H

#include <QWidget>

namespace Ui {
class WidgetEditVoladizo;
}

class WidgetEditVoladizo : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetEditVoladizo(QWidget *parent = 0);
    ~WidgetEditVoladizo();

    void setLongitud(double value);
    void setEmpotramiento(bool estaALaIzquierda);
    double longitud();
    bool empotramientoEstaALaIzquierda();

private:
    Ui::WidgetEditVoladizo *ui;
};

#endif // WIDGETEDITVOLADIZO_H
