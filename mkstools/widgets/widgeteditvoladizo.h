#ifndef WIDGETEDITVOLADIZO_H
#define WIDGETEDITVOLADIZO_H

#include <QWidget>
#include "../model/forward.h"

namespace Ui {
class WidgetEditVoladizo;
}

class WidgetEditVoladizo : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetEditVoladizo(QWidget *parent = 0);
    ~WidgetEditVoladizo();

    void setViga(VoladizoPtr viga);

private:
    void setLongitud(double value);
    void setEmpotramiento(bool estaALaIzquierda);
    double longitud();
    bool empotramientoEstaALaIzquierda();

private slots:
    void on_txtLongitud_textEdited(const QString &arg1);

    void on_radioIzquierda_toggled(bool checked);

private:
    Ui::WidgetEditVoladizo *ui;
    VoladizoPtr _viga;
};

#endif // WIDGETEDITVOLADIZO_H
