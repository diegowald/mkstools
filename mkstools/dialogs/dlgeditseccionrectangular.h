#ifndef DLGEDITSECCIONRECTANGULAR_H
#define DLGEDITSECCIONRECTANGULAR_H

#include <QDialog>

namespace Ui {
class DlgEditSeccionRectangular;
}

class DlgEditSeccionRectangular : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEditSeccionRectangular(QWidget *parent = 0);
    ~DlgEditSeccionRectangular();

    void setBase(double value);
    void setAltura(double value);
    void setArmaduraInferior(double value);
    void setArmaduraSuperior(double value);
    void setRecubrimientoInferior(double value);
    void setRecubrimientoSuperior(double value);

    double base() const;
    double altura() const;
    double armaduraInferior() const;
    double armaduraSuperior() const;
    double recubrimientoInferior() const;
    double recubrimientoSuperior() const;

private:
    Ui::DlgEditSeccionRectangular *ui;
};

#endif // DLGEDITSECCIONRECTANGULAR_H
