#ifndef WIDGETEDITVIGACONTINUA_H
#define WIDGETEDITVIGACONTINUA_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class WidgetEditVigaContinua;
}

class WidgetEditVigaContinua : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetEditVigaContinua(QWidget *parent = 0);
    ~WidgetEditVigaContinua();

    void setLongitud(double longitud);
    void setApoyos(QList<double> &posiciones);
    double longitud();
    QList<double> apoyos();

private slots:
    void on_btnAgregarApoyo_released();

    void on_lstApoyos_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::WidgetEditVigaContinua *ui;
};

#endif // WIDGETEDITVIGACONTINUA_H
