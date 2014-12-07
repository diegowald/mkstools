#ifndef DLGEDITACERO_H
#define DLGEDITACERO_H

#include <QDialog>

namespace Ui {
class DlgEditMaterial;
}

class DlgEditMaterial : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEditMaterial(QWidget *parent = 0);
    ~DlgEditMaterial();

    void setTensionTraccion(double value);
    void setTensionCompresion(double value);
    void setModuloElasticidad(double value);

    double tensionTraccion() const;
    double tensionCompresion() const;
    double moduloElasticidad() const;

private:
    Ui::DlgEditMaterial *ui;
};

#endif // DLGEDITACERO_H
