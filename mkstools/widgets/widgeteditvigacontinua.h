#ifndef WIDGETEDITVIGACONTINUA_H
#define WIDGETEDITVIGACONTINUA_H

#include <QWidget>
#include <QListWidgetItem>
#include "../model/forward.h"

namespace Ui {
class WidgetEditVigaContinua;
}

class WidgetEditVigaContinua : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetEditVigaContinua(QWidget *parent = 0);
    ~WidgetEditVigaContinua();

    void setViga(VigaContinuaPtr viga);

private:
    void setLongitud(double longitud);
    void setApoyos(QList<double> &posiciones);
    double longitud();
    QList<double> apoyos();

private slots:
    void on_btnAgregarApoyo_released();

    void on_lstApoyos_itemDoubleClicked(QListWidgetItem *item);

    void on_txtLongitud_textEdited(const QString &arg1);

private:
    Ui::WidgetEditVigaContinua *ui;
    VigaContinuaPtr _viga;
};

#endif // WIDGETEDITVIGACONTINUA_H
