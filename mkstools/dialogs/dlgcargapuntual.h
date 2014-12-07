#ifndef DLGCARGAPUNTUAL_H
#define DLGCARGAPUNTUAL_H

#include <QDialog>

namespace Ui {
class DlgCargaPuntual;
}

class DlgCargaPuntual : public QDialog
{
    Q_OBJECT

public:
    explicit DlgCargaPuntual(QWidget *parent = 0);
    ~DlgCargaPuntual();

    void setPosicion(double value);
    void setFuerzaX(double value);
    void setFuerzaY(double value);

    double posicion() const;
    double fuerzaX() const;
    double fuerzaY() const;

private:
    Ui::DlgCargaPuntual *ui;
};

#endif // DLGCARGAPUNTUAL_H
