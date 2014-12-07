#ifndef DLGEDITCARGAUNIFORMEDISTRIBUIDA_H
#define DLGEDITCARGAUNIFORMEDISTRIBUIDA_H

#include <QDialog>

namespace Ui {
class DlgEditCargaUniformeDistribuida;
}

class DlgEditCargaUniformeDistribuida : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEditCargaUniformeDistribuida(QWidget *parent = 0);
    ~DlgEditCargaUniformeDistribuida();

    void setPosicionInicial(double value);
    void setPosicionFinal(double value);
    void setCargaX(double value);
    void setCargaY(double value);

    double posicionInicial() const;
    double posicionFinal() const;
    double cargaX() const;
    double cargaY() const;

private:
    Ui::DlgEditCargaUniformeDistribuida *ui;
};

#endif // DLGEDITCARGAUNIFORMEDISTRIBUIDA_H
