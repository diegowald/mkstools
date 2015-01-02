#ifndef DLGEDITVIGACONTINUA_H
#define DLGEDITVIGACONTINUA_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class DlgEditVigaContinua;
}

class DlgEditVigaContinua : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEditVigaContinua(QWidget *parent = 0);
    ~DlgEditVigaContinua();

    void setLongitud(double longitud);
    void setApoyos(QList<double> &posiciones);

    double longitud();
    QList<double> apoyos();

private slots:
    void on_btnAgregarApoyo_released();

    void on_lstApoyos_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::DlgEditVigaContinua *ui;
};

#endif // DLGEDITVIGACONTINUA_H
