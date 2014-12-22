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

    void setTensionAdmisibleTraccion(double value);
    void setTensionAdmisibleCompresion(double value);
    void setTensionRoturaTraccion(double value);
    void setTensionRoturaCompresion(double value);

    void setModuloElasticidad(double value);


    double tensionAdmisibleTraccion() const;
    double tensionAdmisibleCompresion() const;
    double tensionRoturaTraccion() const;
    double tensionRoturaCompresion() const;

    double moduloElasticidad() const;


private:
    Ui::DlgEditMaterial *ui;
};

#endif // DLGEDITACERO_H
