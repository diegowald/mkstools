#ifndef DLGEDITVOLADIZO_H
#define DLGEDITVOLADIZO_H

#include <QDialog>

namespace Ui {
class DlgEditVoladizo;
}

class DlgEditVoladizo : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEditVoladizo(QWidget *parent = 0);
    ~DlgEditVoladizo();

    void setLongitud(double value);
    void setEmpotramiento(bool estaALaIzquierda);

    double longitud();
    bool empotramientoEstaALaIzquierda();
private:
    Ui::DlgEditVoladizo *ui;
};

#endif // DLGEDITVOLADIZO_H
