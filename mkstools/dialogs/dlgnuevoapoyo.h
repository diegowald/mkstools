#ifndef DLGNUEVOAPOYO_H
#define DLGNUEVOAPOYO_H

#include <QDialog>

namespace Ui {
class DlgNuevoApoyo;
}

class DlgNuevoApoyo : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNuevoApoyo(QWidget *parent = 0);
    ~DlgNuevoApoyo();

    void setPosicion(double pos);
    double posicion();
private:
    Ui::DlgNuevoApoyo *ui;
};

#endif // DLGNUEVOAPOYO_H
