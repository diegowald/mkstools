#ifndef DLGEDITVIGASIMPLEMENTEAPOYADA_H
#define DLGEDITVIGASIMPLEMENTEAPOYADA_H

#include <QDialog>

namespace Ui {
class DlgEditVigaSimplementeApoyada;
}

class DlgEditVigaSimplementeApoyada : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEditVigaSimplementeApoyada(QWidget *parent = 0);
    ~DlgEditVigaSimplementeApoyada();

    void setLongitud(double value);
    double longitud() const;


    void setPosicionApoyoIzquierdo(double value);
    void setPosicionApoyoDerecho(double value);

    double posicionApoyoIzquierdo();
    double posicinoApoyoDerecho();

private:
    Ui::DlgEditVigaSimplementeApoyada *ui;
};

#endif // DLGEDITVIGASIMPLEMENTEAPOYADA_H
