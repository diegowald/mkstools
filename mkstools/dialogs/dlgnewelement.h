#ifndef DLGNEWELEMENT_H
#define DLGNEWELEMENT_H

#include <QDialog>
#include "../model/forward.h"

namespace Ui {
class DlgNewElement;
}

class DlgNewElement : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNewElement(ElementoPtr elemento, QWidget *parent = 0);
    ~DlgNewElement();

    void setElemento(ElementoPtr elemento);
    ElementoPtr elemento();

private slots:
    void on_cboType_currentTextChanged(const QString &arg1);

    void on_btnDiagramas_released();

    void on_btnArmadura_released();

    void on_btnReporte_released();

    void on_txtName_textEdited(const QString &arg1);

private:
    void crearTiposEstructurales();
private:
    Ui::DlgNewElement *ui;
    QWidget *_editWidget;
    ElementoPtr _elemento;
};

#endif // DLGNEWELEMENT_H
