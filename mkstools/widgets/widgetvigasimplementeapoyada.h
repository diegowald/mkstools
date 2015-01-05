#ifndef WIDGETVIGASIMPLEMENTEAPOYADA_H
#define WIDGETVIGASIMPLEMENTEAPOYADA_H

#include <QWidget>
#include "../model/forward.h"

namespace Ui {
class WidgetVigaSimplementeApoyada;
}

class WidgetVigaSimplementeApoyada : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetVigaSimplementeApoyada(QWidget *parent = 0);
    ~WidgetVigaSimplementeApoyada();

    void setViga(VigaSimplementeApoyadaPtr viga);
private slots:
    void on_txtPosicionApoyoIzquierdo_textEdited(const QString &arg1);
    void on_lineEdit_textEdited(const QString &arg1);
    void on_txtPosicionApoyoDerecho_textEdited(const QString &arg1);

private:
    void setLongitud(double value);
    double longitud() const;
    void setPosicionApoyoIzquierdo(double value);
    void setPosicionApoyoDerecho(double value);
    double posicionApoyoIzquierdo();
    double posicinoApoyoDerecho();

private:
    Ui::WidgetVigaSimplementeApoyada *ui;
    VigaSimplementeApoyadaPtr _viga;
};

#endif // WIDGETVIGASIMPLEMENTEAPOYADA_H
