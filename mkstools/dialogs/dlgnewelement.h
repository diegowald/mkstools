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
    explicit DlgNewElement(QWidget *parent = 0);
    ~DlgNewElement();

    void setElemento(ElementoPtr elemento);
    ElementoPtr elemento();

private slots:
    void on_cboType_currentTextChanged(const QString &arg1);

private:
    void crearTiposEstructurales();
private:
    Ui::DlgNewElement *ui;
    QWidget *_editWidget;
    ElementoPtr _elemento;
    TipologiaPtr _tipologia;
};

#endif // DLGNEWELEMENT_H
