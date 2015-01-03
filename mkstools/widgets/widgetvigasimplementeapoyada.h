#ifndef WIDGETVIGASIMPLEMENTEAPOYADA_H
#define WIDGETVIGASIMPLEMENTEAPOYADA_H

#include <QWidget>

namespace Ui {
class WidgetVigaSimplementeApoyada;
}

class WidgetVigaSimplementeApoyada : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetVigaSimplementeApoyada(QWidget *parent = 0);
    ~WidgetVigaSimplementeApoyada();

    void setLongitud(double value);
    double longitud() const;
    void setPosicionApoyoIzquierdo(double value);
    void setPosicionApoyoDerecho(double value);
    double posicionApoyoIzquierdo();
    double posicinoApoyoDerecho();

private:
    Ui::WidgetVigaSimplementeApoyada *ui;
};

#endif // WIDGETVIGASIMPLEMENTEAPOYADA_H
